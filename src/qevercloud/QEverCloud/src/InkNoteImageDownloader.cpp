/**
 * Copyright (c) 2016-2020 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms
 * of MIT license:
 * https://opensource.org/licenses/MIT
 */

#include "Http.h"

#include <Globals.h>
#include <Helpers.h>
#include <InkNoteImageDownloader.h>
#include <Log.h>

#include <QBuffer>
#include <QImage>
#include <QPainter>
#include <QSize>

#include <memory>
#include <utility>

namespace qevercloud {

class InkNoteImageDownloaderPrivate
{
public:
    std::pair<QNetworkRequest, QByteArray> createPostRequest(
        const QString & urlPart, const int sliceNumber,
        const bool isPublic = false);

    QString m_host;
    QString m_shardId;
    QString m_authenticationToken;
    int m_width;
    int m_height;
};

InkNoteImageDownloader::InkNoteImageDownloader() :
    d_ptr(new InkNoteImageDownloaderPrivate)
{}

InkNoteImageDownloader::InkNoteImageDownloader(
        QString host, QString shardId, QString authenticationToken,
        int width, int height) :
    d_ptr(new InkNoteImageDownloaderPrivate)
{
    d_ptr->m_host = host;
    d_ptr->m_shardId = shardId;
    d_ptr->m_authenticationToken = authenticationToken;
    d_ptr->m_width = width;
    d_ptr->m_height = height;
}

InkNoteImageDownloader::~InkNoteImageDownloader()
{
    delete d_ptr;
}

InkNoteImageDownloader & InkNoteImageDownloader::setHost(QString host)
{
    d_ptr->m_host = host;
    return *this;
}

InkNoteImageDownloader & InkNoteImageDownloader::setShardId(QString shardId)
{
    d_ptr->m_shardId = shardId;
    return *this;
}

InkNoteImageDownloader & InkNoteImageDownloader::setAuthenticationToken(
    QString authenticationToken)
{
    d_ptr->m_authenticationToken = authenticationToken;
    return *this;
}

InkNoteImageDownloader & InkNoteImageDownloader::setWidth(int width)
{
    d_ptr->m_width = width;
    return *this;
}

InkNoteImageDownloader & InkNoteImageDownloader::setHeight(int height)
{
    d_ptr->m_height = height;
    return *this;
}

QByteArray InkNoteImageDownloader::download(
    Guid guid, const bool isPublic, const qint64 timeoutMsec)
{
    QEC_DEBUG("ink_note_image", "Downloading ink note image: guid = " << guid
        << (isPublic ? "public" : "non-public"));

    Q_D(InkNoteImageDownloader);

    QSize size(d_ptr->m_width, d_ptr->m_height);
    QImage inkNoteImage(size, QImage::Format_RGB32);

    QString urlPattern = QStringLiteral("https://%1/shard/%2/res/%3.ink?slice=");
    QString urlPart = urlPattern.arg(d->m_host, d->m_shardId, guid);

    int painterPosition = 0;
    int sliceCounter = 1;
    while(true)
    {
        int httpStatusCode = 0;
        auto postRequest = d->createPostRequest(urlPart, sliceCounter, isPublic);

        QEC_DEBUG("ink_note_image", "Sending download request to url: "
            << postRequest.first.url());

        QByteArray reply = simpleDownload(
            postRequest.first,
            timeoutMsec,
            postRequest.second,
            &httpStatusCode);

        if (httpStatusCode != 200) {
            QEC_WARNING("ink_note_image", "Failed to download slice "
                << sliceCounter << " for guid " << guid
                << ": http status code = " << httpStatusCode);

            throw EverCloudException(
                QStringLiteral("HTTP Status Code = %1").arg(httpStatusCode));
        }

        QImage replyImagePart;
        Q_UNUSED(replyImagePart.loadFromData(reply, "PNG"))
        if (replyImagePart.isNull())
        {
            if (Q_UNLIKELY(inkNoteImage.isNull()))
            {
                QEC_WARNING("ink_note_image", "Failed to read downloaded data "
                    << "as a png image");

                throw EverCloudException(
                    QStringLiteral("Ink note's image part is null before even "
                                   "starting to assemble"));
            }

            break;
        }

        if (replyImagePart.format() != inkNoteImage.format()) {
            inkNoteImage = inkNoteImage.convertToFormat(replyImagePart.format());
        }

        QRect painterCurrentRect(
            0,
            painterPosition,
            replyImagePart.width(),
            replyImagePart.height());

        painterPosition += replyImagePart.height();

        QPainter painter(&inkNoteImage);
        painter.setRenderHints(QPainter::Antialiasing);
        painter.drawImage(painterCurrentRect, replyImagePart);

        if (painterPosition >= size.height()) {
            break;
        }

        ++sliceCounter;
    }

    if (inkNoteImage.isNull()) {
        return QByteArray();
    }

    QByteArray imageData;
    QBuffer buffer(&imageData);
    Q_UNUSED(buffer.open(QIODevice::WriteOnly))
    inkNoteImage.save(&buffer, "PNG");

    QEC_DEBUG("ink_note_image", "Finished download for guid " << guid);
    return imageData;
}

std::pair<QNetworkRequest, QByteArray>
InkNoteImageDownloaderPrivate::createPostRequest(
    const QString & urlPart, const int sliceNumber, const bool isPublic)
{
    QNetworkRequest request;
    request.setUrl(QUrl(urlPart + QString::number(sliceNumber)));
    request.setHeader(
        QNetworkRequest::ContentTypeHeader,
        QStringLiteral("application/x-www-form-urlencoded"));

    // not QByteArray()! or else ReplyFetcher will not work.
    QByteArray postData = "";
    if (!isPublic) {
        postData = QByteArray("auth=") +
            QUrl::toPercentEncoding(m_authenticationToken);
    }

    return std::make_pair(request, postData);
}

} // namespace qevercloud

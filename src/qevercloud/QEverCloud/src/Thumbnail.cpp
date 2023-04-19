/**
 * Original work: Copyright (c) 2014 Sergey Skoblikov
 * Modified work: Copyright (c) 2015-2020 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms
 * of MIT license:
 * https://opensource.org/licenses/MIT
 */

#include "Http.h"

#include <Globals.h>
#include <Log.h>
#include <RequestContext.h>
#include <Thumbnail.h>

namespace qevercloud {

////////////////////////////////////////////////////////////////////////////////

class ThumbnailPrivate
{
public:
    QString m_host;
    QString m_shardId;
    QString m_authenticationToken;
    int m_size;
    Thumbnail::ImageType m_imageType;
};

////////////////////////////////////////////////////////////////////////////////

Thumbnail::Thumbnail():
    d_ptr(new ThumbnailPrivate)
{
    d_ptr->m_size = 300;
    d_ptr->m_imageType = ImageType::PNG;
}


Thumbnail::Thumbnail(
        QString host, QString shardId, QString authenticationToken,
        int size, Thumbnail::ImageType imageType) :
    d_ptr(new ThumbnailPrivate)
{
    d_ptr->m_host = host;
    d_ptr->m_shardId = shardId;
    d_ptr->m_authenticationToken = authenticationToken;
    d_ptr->m_size = size;
    d_ptr->m_imageType = imageType;
}

Thumbnail::~Thumbnail()
{
    delete d_ptr;
}

Thumbnail & Thumbnail::setHost(QString host)
{
    d_ptr->m_host = host;
    return *this;
}

Thumbnail & Thumbnail::setShardId(QString shardId)
{
    d_ptr->m_shardId = shardId;
    return *this;
}

Thumbnail & Thumbnail::setAuthenticationToken(QString authenticationToken)
{
    d_ptr->m_authenticationToken = authenticationToken;
    return *this;
}

Thumbnail & Thumbnail::setSize(int size)
{
    d_ptr->m_size = size;
    return *this;
}

Thumbnail & Thumbnail::setImageType(ImageType imageType)
{
    d_ptr->m_imageType = imageType;
    return *this;
}

QByteArray Thumbnail::download(
    Guid guid, const bool isPublic, const bool isResourceGuid,
    const qint64 timeoutMsec)
{
    QEC_DEBUG("thumbnail", "Downloading thumbnail: guid = " << guid
        << (isPublic ? "public" : "non-public") << ", "
        << (isResourceGuid ? "resource guid" : "not a resource guid"));

    int httpStatusCode = 0;
    auto request = createPostRequest(guid, isPublic, isResourceGuid);

    QByteArray reply = simpleDownload(
        request.first,
        timeoutMsec,
        request.second,
        &httpStatusCode);

    if (httpStatusCode != 200)
    {
        QEC_WARNING("thumbnail", "Failed to download thumbnail with guid "
            << guid << ": http status code = " << httpStatusCode);

        throw EverCloudException(
            QString::fromUtf8("HTTP Status Code = %1").arg(httpStatusCode));
    }

    QEC_DEBUG("thumbnail", "Finished download for guid " << guid);
    return reply;
}

AsyncResult * Thumbnail::downloadAsync(
    Guid guid, const bool isPublic, const bool isResourceGuid,
    const qint64 timeoutMsec)
{
    QEC_DEBUG("thumbnail", "Starting async thumbnail download: guid = " << guid
        << (isPublic ? "public" : "non-public") << ", "
        << (isResourceGuid ? "resource guid" : "not a resource guid"));

    auto pair = createPostRequest(guid, isPublic, isResourceGuid);
    auto ctx = newRequestContext({}, timeoutMsec);
    auto res = new AsyncResult(
        pair.first,
        pair.second,
        ctx);

    QObject::connect(
        res,
        &AsyncResult::finished,
        [=] (QVariant value,
             EverCloudExceptionDataPtr error,
             IRequestContextPtr ctx)
        {
            Q_UNUSED(value)
            Q_UNUSED(ctx)

            if (!error) {
                QEC_DEBUG("thumbnail", "Finished async download "
                   << "for guid " << guid);
                return;
            }

            QEC_WARNING("thumbnail", "Async download for guid "
               << guid << " finished with error: "
               << error->errorMessage);
        });
    return res;
}

std::pair<QNetworkRequest, QByteArray> Thumbnail::createPostRequest(
    Guid guid, bool isPublic, bool isResourceGuid)
{
    Q_D(Thumbnail);

    QByteArray postData = ""; // not QByteArray()! or else ReplyFetcher will not work.
    QNetworkRequest request;

    QString urlPattern;
    if(isResourceGuid) {
        urlPattern = QStringLiteral("https://%1/shard/%2/thm/res/%3");
    }
    else {
        urlPattern = QStringLiteral("https://%1/shard/%2/thm/note/%3");
    }

    QString url = urlPattern.arg(d->m_host, d->m_shardId, guid);

    QString ext;
    switch(d->m_imageType)
    {
    case ImageType::BMP:
        ext = QStringLiteral(".bmp");
        break;
    case ImageType::GIF:
        ext = QStringLiteral(".gif");
        break;
    case ImageType::JPEG:
        ext = QStringLiteral(".jpg");
        break;
    default:
        ext = QStringLiteral(".png");
        break;
    }
    url += ext;

    if (d->m_size != 300) {
        url += QStringLiteral("?size=%1").arg(d->m_size);
    }

    QEC_TRACE("thumbnail", "Sending thumbnail download request: url = " << url);

    request.setUrl(QUrl(url));
    request.setHeader(
        QNetworkRequest::ContentTypeHeader,
        QStringLiteral("application/x-www-form-urlencoded"));

    if (!isPublic) {
        postData = QByteArray("auth=") +
            QUrl::toPercentEncoding(d->m_authenticationToken);
    }

    return std::make_pair(request, postData);
}

////////////////////////////////////////////////////////////////////////////////

namespace {

template <typename T>
void printImageType(T & strm, const Thumbnail::ImageType imageType)
{
    switch(imageType)
    {
    case Thumbnail::ImageType::PNG:
        strm << "PNG";
        break;
    case Thumbnail::ImageType::JPEG:
        strm << "JPEG";
        break;
    case Thumbnail::ImageType::GIF:
        strm << "GIF";
        break;
    case Thumbnail::ImageType::BMP:
        strm << "BMP";
        break;
    default:
        strm << "Unknown (" << static_cast<qint64>(imageType) << ")";
        break;
    }
}

} // namespace

////////////////////////////////////////////////////////////////////////////////

QTextStream & operator<<(
    QTextStream & strm, const Thumbnail::ImageType imageType)
{
    printImageType(strm, imageType);
    return strm;
}

QDebug & operator<<(QDebug & dbg, const Thumbnail::ImageType imageType)
{
    printImageType(dbg, imageType);
    return dbg;
}

} // namespace qevercloud

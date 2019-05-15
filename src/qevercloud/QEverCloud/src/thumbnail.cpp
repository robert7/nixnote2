/**
 * Original work: Copyright (c) 2014 Sergey Skoblikov
 * Modified work: Copyright (c) 2015-2016 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms of MIT license:
 * https://opensource.org/licenses/MIT
 */

#include <thumbnail.h>
#include "http.h"

namespace qevercloud {

class ThumbnailPrivate
{
public:
    QString m_host;
    QString m_shardId;
    QString m_authenticationToken;
    int m_size;
    Thumbnail::ImageType::type m_imageType;
};

Thumbnail::Thumbnail():
    d_ptr(new ThumbnailPrivate)
{
    d_ptr->m_size = 300;
    d_ptr->m_imageType = ImageType::PNG;
}


Thumbnail::Thumbnail(QString host, QString shardId, QString authenticationToken,
                     int size, Thumbnail::ImageType::type imageType) :
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

Thumbnail & Thumbnail::setImageType(ImageType::type imageType)
{
    d_ptr->m_imageType = imageType;
    return *this;
}

QByteArray Thumbnail::download(Guid guid, bool isPublic, bool isResourceGuid)
{
    int httpStatusCode = 0;
    QPair<QNetworkRequest, QByteArray> request = createPostRequest(guid, isPublic, isResourceGuid);

    QByteArray reply = simpleDownload(evernoteNetworkAccessManager(), request.first,
                                      request.second, &httpStatusCode);
    if (httpStatusCode != 200) {
        throw EverCloudException(QStringLiteral("HTTP Status Code = %1").arg(httpStatusCode));
    }

    return reply;
}

AsyncResult* Thumbnail::downloadAsync(Guid guid, bool isPublic, bool isResourceGuid)
{
    QPair<QNetworkRequest, QByteArray> pair = createPostRequest(guid, isPublic, isResourceGuid);
    return new AsyncResult(pair.first, pair.second);
}

QPair<QNetworkRequest, QByteArray> Thumbnail::createPostRequest(Guid guid, bool isPublic, bool isResourceGuid)
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

    request.setUrl(QUrl(url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, QStringLiteral("application/x-www-form-urlencoded"));

    if (!isPublic) {
        postData = QByteArray("auth=")+ QUrl::toPercentEncoding(d->m_authenticationToken);
    }

    return qMakePair(request, postData);
}

} // namespace qevercloud

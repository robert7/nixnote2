/**
 * Copyright (c) 2016 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms of MIT license:
 * https://opensource.org/licenses/MIT
 */

#ifndef QEVERCLOD_INK_NOTE_IMAGE_DOWNLOADER_H
#define QEVERCLOD_INK_NOTE_IMAGE_DOWNLOADER_H

#include "export.h"
#include "AsyncResult.h"
#include "generated/types.h"
#include <QByteArray>
#include <QString>
#include <QNetworkAccessManager>

namespace qevercloud {

/** @cond HIDDEN_SYMBOLS  */
class InkNoteImageDownloaderPrivate;
/** @endcond */

/**
 * @brief the class is for downloading the images of ink notes which can be created
 * with the official Evernote client on Windows (only with it, at least at the time
 * of this writing).
 *
 * On all other platforms the most one can get instead of the actual ink note
 * is its non-editable image. This class retrieves just these, exclusively in PNG format.
 *
 * NOTE: almost the entirety of this class' content represents an ad-hoc solution
 * to a completely undocumented feature of Evernote service. A very small glimpse
 * of information can be found e.g. <a href="https://discussion.evernote.com/topic/7943-linux-guinea-pigs/?page=2#comment-59366">here</a>
 * but it is practically all one can find.
 */
class QEVERCLOUD_EXPORT InkNoteImageDownloader
{
public:
    /**
     * @brief Default constructor.
     *
     * host, shardId, authenticationToken, width, height have to be specified before calling
     * @link download @endlink or @link createPostRequest @endlink
     */
    InkNoteImageDownloader();

    /**
     * @brief Constructs InkNoteImageDownloader.
     * @param host
     * www.evernote.com or sandbox.evernote.com
     * @param shardId
     * You can get the value from UserStore service or as a result of an authentication.
     * @param authenticationToken
     * For working private ink notes you must supply a valid authentication token.
     * For public resources the value specified is not used.
     * @param width
     * Width of the ink note's resource
     * @param height
     * Height of the ink note's resource
     */
    InkNoteImageDownloader(QString host, QString shardId, QString authenticationToken, int width, int height);

    virtual ~InkNoteImageDownloader();

    /**
     * @param host
     * www.evernote.com or sandbox.evernote.com
     */
    InkNoteImageDownloader & setHost(QString host);

    /**
     * @param shardId
     * You can get the value from UserStore service or as a result of an authentication.
     */
    InkNoteImageDownloader & setShardId(QString shardId);

    /**
     * @param authenticationToken
     * For working private ink notes you must supply a valid authentication token.
     * For public resources the value specified is not used.
     */
    InkNoteImageDownloader & setAuthenticationToken(QString authenticationToken);

    /**
     * @param width
     * Width of the ink note's resource
     */
    InkNoteImageDownloader & setWidth(int width);

    /**
     * @param height
     * Height of the ink note's resource
     */
    InkNoteImageDownloader & setHeight(int height);

    /**
     * @brief Downloads the image for the ink note.
     *
     * Unlike other pieces of QEverCloud API, downloading of ink note images is currently
     * synchronous only. The reason for that is that AsyncResult is bounded to a single
     * QNetworkRequest object but downloading of the ink note image might take multiple
     * requests for several ink note image's vertical stripes which are then merged
     * together to form a single image. Downloading the entire ink note's image
     * via a single request works sometimes but sometimes Evernote replies to such request
     * with messed up data which cannot be loaded into a QImage. The reason for that behaviour
     * is unknown at the moment, and, given the state of official documentation - missing -
     * it is likely to stay so. if someone has an idea how to make it more reliable,
     * please let me know.
     *
     * @param guid
     * The guid of the ink note's resource
     * @param isPublic
     * Specify true for public ink notes. In this case authentication token is not sent to
     * with the request as it shoud be according to the docs.
     * @return downloaded data.
     *
     */
    QByteArray download(Guid guid, bool isPublic = false);

private:
    InkNoteImageDownloaderPrivate * const d_ptr;
    Q_DECLARE_PRIVATE(InkNoteImageDownloader)
};

} // namespace qevercloud

#endif // QEVERCLOD_INK_NOTE_IMAGE_DOWNLOADER_H

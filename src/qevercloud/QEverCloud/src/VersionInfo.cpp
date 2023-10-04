/**
 * Copyright (c) 2017-2020 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms
 * of MIT license: https://opensource.org/licenses/MIT
 */

#include <VersionInfo.h>

#include <QtGlobal>

namespace qevercloud {

int qevercloudVersionMajor()
{
    return QEVERCLOUD_VERSION_MAJOR;
}

int qevercloudVersionMinor()
{
    return QEVERCLOUD_VERSION_MINOR;
}

int qevercloudVersionPatch()
{
    return QEVERCLOUD_VERSION_PATCH;
}

QString qevercloudBuildInfo()
{
    return QStringLiteral(QEVERCLOUD_BUILD_INFO);
}

QString qevercloudBuiltWithQtVersion()
{
    return QStringLiteral(QT_VERSION_STR);
}

bool qevercloudHasOAuth()
{
    return static_cast<bool>(QEVERCLOUD_HAS_OAUTH);
}

bool qevercloudUsesQtWebEngine()
{
    return static_cast<bool>(QEVERCLOUD_USE_QT_WEB_ENGINE);
}

bool qevercloudUsesQNamespace()
{
    return static_cast<bool>(QEVERCLOUD_USES_Q_NAMESPACE);
}

} // namespace qevercloud

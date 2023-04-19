/**
 * Copyright (c) 2023 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms
 * of MIT license: https://opensource.org/licenses/MIT
 */

#include "Utils.h"

#include <QLocale>

namespace qevercloud {

QString httpAcceptLanguage()
{
    auto uiLanguages = QLocale::system().uiLanguages();
    const QString en = QStringLiteral("en");
    if (!uiLanguages.contains(en)) {
        uiLanguages << en;
    }

    return uiLanguages.join(QStringLiteral(", "));
}

} // namespace qevercloud

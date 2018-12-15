/*********************************************************************************
NixNote - An open-source client for the Evernote service.
Copyright (C) 2018 Robert Spiegel

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
***********************************************************************************/


#include "NixnoteStringUtils.h"

NixnoteStringUtils::NixnoteStringUtils() {

}


QString NixnoteStringUtils::extractLatexFormulaFromResourceUrl(QString url) {
    QString prefix(LATEX_RENDER_URL);
    if (!url.startsWith(prefix)) {
        return QString();
    }
    return urldecode(url.right(url.size() - prefix.size()));
}

QString NixnoteStringUtils::urlencode(QString plain) {
    return QUrl::toPercentEncoding(plain);
}

QString NixnoteStringUtils::urldecode(QString encoded) {
    QByteArray encodedB(encoded.toUtf8());
    QString decoded(QUrl::fromPercentEncoding(encodedB));
    return decoded;
}


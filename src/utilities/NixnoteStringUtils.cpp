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

bool NixnoteStringUtils::isLatexFormulaResourceUrl(QString url) {
    return url.startsWith(LATEX_RENDER_URL);
}


QString NixnoteStringUtils::extractLatexFormulaFromResourceUrl(QString url, bool encoded) {
    if (!NixnoteStringUtils::isLatexFormulaResourceUrl(url)) {
        return QString();
    }

    QString prefix(LATEX_RENDER_URL);
    QString formula(url.right(url.size() - prefix.size()));
    if (!encoded) {
        formula = NixnoteStringUtils::urldecode(formula);
    }
    return formula;
}

QString NixnoteStringUtils::createLatexResourceUrl(QString formula, bool doUrlencode) {
    QString url(LATEX_RENDER_URL);

    // url encoding is optional (as we may already have url encoded source
    if (doUrlencode) {
        formula = NixnoteStringUtils::urlencode(formula);
    }

    url.append(formula);
    return url;
}

QString NixnoteStringUtils::urlencode(QString plain) {
    return QUrl::toPercentEncoding(plain);
}

QString NixnoteStringUtils::urldecode(QString encoded) {
    QByteArray encodedB(encoded.toUtf8());
    QString decoded(QUrl::fromPercentEncoding(encodedB));
    return decoded;
}


QString NixnoteStringUtils::createNoteLink(bool createInAppLink, QString server, QString userId, QString shardId,
                                           QString noteGuid) {
    if (createInAppLink) {
        return "evernote:///view/" + userId + QString("/") +
               shardId + QString("/") +
               noteGuid + QString("/") +
               noteGuid + QString("/");
    } else {
        return "https://" + server + "/shard/" + shardId + "/nl/" + userId + "/" + noteGuid + "/";
    }
}

QString NixnoteStringUtils::extractNoteGuid(QString noteUrl) {
    // Remove trailing '/' if it exists
    if (noteUrl.endsWith('/')) {
        noteUrl.chop(1);
    }
    QStringList splitNoteUrl = noteUrl.split('/');
    return splitNoteUrl[splitNoteUrl.count()-1];
}

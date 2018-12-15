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

#ifndef NIXNOTE_STRING_UTILS_H
#define NIXNOTE_STRING_UTILS_H

#include <QString>
#include <QUrl>

#define LATEX_RENDER_URL "http://latex.codecogs.com/gif.latex?"


class NixnoteStringUtils {
public:
    NixnoteStringUtils();


    static bool isLatexFormulaResourceUrl(QString url);

    /**
     * Extract latex formula from url.
     * @param urlencode whwnever we want it to receive in encoded form (needed in case we want to pass the formula
     *     in other html/xml attribute.
     */
    static QString extractLatexFormulaFromResourceUrl(QString url, bool encoded = false);

    /**
     * Create resouce url with given formula.
     * @param formula formula to put in url
     * @param urlencode whenever do url encoding.
     */
    static QString createLatexResourceUrl(QString formula, bool doUrlencode = true);

    static QString urlencode(QString plain);

    static QString urldecode(QString encoded);
};

#endif // NIXNOTE_STRING_UTILS_H

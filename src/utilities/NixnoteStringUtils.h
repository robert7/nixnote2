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

    /**
     * Create "In App Note Link" or "Note Link".
     * https://dev.evernote.com/doc/articles/note_links.php
     *
     * @param createInAppLink if true "in app" link (‘Classic Note Link’) is created.
     * false: Note Link is created - Note Links are used to reference a note in a web browser that when the
     * recipient of the link already has access via notebook or individual note sharing.
     *
     * @return note link
     */
    static QString createNoteLink(bool createInAppLink, QString server, QString userId, QString shardId, QString noteGuid);

    /**
     * Extract note GUID from "In App Note Link" or "Note Link".
     *
     * @param noteUrl Evernote note link (either in-app or external, both work)
     *
     * @return note GUID
     */
    static QString extractNoteGuid(QString noteUrl); 
};

#endif // NIXNOTE_STRING_UTILS_H

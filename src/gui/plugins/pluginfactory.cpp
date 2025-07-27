/*********************************************************************************
NixNote - An open-source client for the Evernote service.
Copyright (C) 2013 Randy Baumgarte

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

#include "src/gui/plugins/pluginfactory.h"
#include "src/gui/plugins/popplerviewer.h"
#include <QNetworkRequest>
#include <QNetworkReply>

PluginFactory::PluginFactory(QObject *parent) :
    QWebPluginFactory(parent)
{
}

QList<QWebPluginFactory::Plugin> PluginFactory::plugins() const
{
    QWebPluginFactory::MimeType mimeType;
    mimeType.name = "application/pdf";
    mimeType.description = "PDF Viewer";
    mimeType.fileExtensions = QStringList() << "pdf";

    QWebPluginFactory::Plugin plugin;
    plugin.name = "PDF file viewer";
    plugin.description = "A PDF file Web plugin.";
    plugin.mimeTypes = QList<MimeType>() << mimeType;

    return QList<QWebPluginFactory::Plugin>() << plugin;
}


QObject *PluginFactory::create(const QString &mimeType, const QUrl &url,
                            const QStringList &argumentNames,
                            const QStringList &argumentValues) const
{
    Q_UNUSED(url);  // suppress unused variable warning
    if (mimeType == "application/pdf") {
        PopplerViewer *view;
        view = new PopplerViewer(argumentValues[argumentNames.indexOf("type")],
                argumentValues[argumentNames.indexOf("lid")]);

        if (view->doc == nullptr || view->doc->isLocked())
            return 0;
        return (QObject*)view;
    }
    return 0;
}

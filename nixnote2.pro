QT += core gui widgets printsupport webkit webkitwidgets sql network xml dbus qml
DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0
unix {
    CONFIG += link_pkgconfig
    PKGCONFIG += poppler-qt5 libcurl tidy
}


unix:!mac:LIBS += -lpthread -g -rdynamic

win32:INCLUDEPATH += "$$PWD/winlib/includes/poppler/qt5"
win32:INCLUDEPATH += "$$PWD/winlib/includes"
win32:LIBS += -L"$$PWD/winlib" -lpoppler-qt5
win32:RC_ICONS += "$$PWD/resources/images/windowIcon.ico"


mac {
    TARGET = NixNote2
} else {
    TARGET = nixnote2
}
TEMPLATE = app
RESOURCES = nixnote2.qrc

UI_DIR = .

CONFIG(debug, debug|release) {
    DESTDIR = qmake-build-debug
    message(Debug build!)
} else {
    DESTDIR = qmake-build-release
    message(Release build!)
}
OBJECTS_DIR = $${DESTDIR}
MOC_DIR = $${DESTDIR}

TRANSLATIONS = \
    translations/nixnote2_cs_CZ.ts \
    translations/nixnote2_de.ts    \
    translations/nixnote2_en_GB.ts \
    translations/nixnote2_ca.ts    \
    translations/nixnote2_da.ts    \
    translations/nixnote2_es.ts    \
    translations/nixnote2_ja.ts    \
    translations/nixnote2_pt.ts    \
    translations/nixnote2_sk.ts    \
    translations/nixnote2_zh_TW.ts \
    translations/nixnote2_fr.ts    \
    translations/nixnote2_pl.ts    \
    translations/nixnote2_ru.ts    \
    translations/nixnote2_zh_CN.ts


SOURCES += \
    src/application.cpp \
    src/global.cpp \
    src/main.cpp \
    src/nixnote.cpp \
    src/cmdtools/addnote.cpp \
    src/cmdtools/alternote.cpp \
    src/cmdtools/cmdlinequery.cpp \
    src/cmdtools/cmdlinetool.cpp \
    src/cmdtools/deletenote.cpp \
    src/cmdtools/emailnote.cpp \
    src/cmdtools/extractnotes.cpp \
    src/cmdtools/extractnotetext.cpp \
    src/cmdtools/importnotes.cpp \
    src/cmdtools/signalgui.cpp \
    src/communication/communicationerror.cpp \
    src/communication/communicationmanager.cpp \
    src/dialog/aboutdialog.cpp \
    src/dialog/accountdialog.cpp \
    src/dialog/accountmaintenancedialog.cpp \
    src/dialog/adduseraccountdialog.cpp \
    src/dialog/closenotebookdialog.cpp \
    src/dialog/databasestatus.cpp \
    src/dialog/emaildialog.cpp \
    src/dialog/encryptdialog.cpp \
    src/dialog/endecryptdialog.cpp \
    src/dialog/faderdialog.cpp \
    src/dialog/htmlentitiesdialog.cpp \
    src/dialog/insertlatexdialog.cpp \
    src/dialog/insertlinkdialog.cpp \
    src/dialog/locationdialog.cpp \
    src/dialog/logindialog.cpp \
    src/dialog/notebookproperties.cpp \
    src/dialog/notehistoryselect.cpp \
    src/dialog/noteproperties.cpp \
    src/dialog/preferences/appearancepreferences.cpp \
    src/dialog/preferences/debugpreferences.cpp \
    src/dialog/preferences/emailpreferences.cpp \
    src/dialog/preferences/exitpreferences.cpp \
    src/dialog/preferences/localepreferences.cpp \
    src/dialog/preferences/preferencesdialog.cpp \
    src/dialog/preferences/searchpreferences.cpp \
    src/dialog/preferences/syncpreferences.cpp \
    src/dialog/preferences/thumbnailpreferences.cpp \
    src/dialog/remindersetdialog.cpp \
    src/dialog/savedsearchproperties.cpp \
    src/dialog/shortcutdialog.cpp \
    src/dialog/spellcheckdialog.cpp \
    src/dialog/tabledialog.cpp \
    src/dialog/tagproperties.cpp \
    src/dialog/watchfolderadd.cpp \
    src/dialog/watchfolderdialog.cpp \
    src/email/emailaddress.cpp \
    src/email/mimeattachment.cpp \
    src/email/mimecontentformatter.cpp \
    src/email/mimefile.cpp \
    src/email/mimehtml.cpp \
    src/email/mimeinlinefile.cpp \
    src/email/mimemessage.cpp \
    src/email/mimemultipart.cpp \
    src/email/mimepart.cpp \
    src/email/mimetext.cpp \
    src/email/quotedprintable.cpp \
    src/email/smtpclient.cpp \
    src/exits/exitmanager.cpp \
    src/exits/exitpoint.cpp \
    src/filters/filtercriteria.cpp \
    src/filters/filterengine.cpp \
    src/filters/notesortfilterproxymodel.cpp \
    src/filters/remotequery.cpp \
    src/gui/browserWidgets/authoreditor.cpp \
    src/gui/browserWidgets/colormenu.cpp \
    src/gui/browserWidgets/dateeditor.cpp \
    src/gui/browserWidgets/datetimeeditor.cpp \
    src/gui/browserWidgets/editorbuttonbar.cpp \
    src/gui/browserWidgets/expandbutton.cpp \
    src/gui/browserWidgets/fontnamecombobox.cpp \
    src/gui/browserWidgets/fontsizecombobox.cpp \
    src/gui/browserWidgets/locationeditor.cpp \
    src/gui/browserWidgets/notebookmenubutton.cpp \
    src/gui/browserWidgets/ntitleeditor.cpp \
    src/gui/browserWidgets/reminderbutton.cpp \
    src/gui/browserWidgets/table/tablepropertiesdialog.cpp \
    src/gui/browserWidgets/tageditor.cpp \
    src/gui/browserWidgets/tageditornewtag.cpp \
    src/gui/browserWidgets/tagviewer.cpp \
    src/gui/browserWidgets/urleditor.cpp \
    src/gui/datedelegate.cpp \
    src/gui/externalbrowse.cpp \
    src/gui/favoritesview.cpp \
    src/gui/favoritesviewdelegate.cpp \
    src/gui/favoritesviewitem.cpp \
    src/gui/findreplace.cpp \
    src/gui/flowlayout.cpp \
    src/gui/imagedelegate.cpp \
    src/gui/lineedit.cpp \
    src/gui/nattributetree.cpp \
    src/gui/nbrowserwindow.cpp \
    src/gui/nmainmenubar.cpp \
    src/gui/nnotebookview.cpp \
    src/gui/nnotebookviewdelegate.cpp \
    src/gui/nnotebookviewitem.cpp \
    src/gui/nsearchview.cpp \
    src/gui/nsearchviewitem.cpp \
    src/gui/ntableview.cpp \
    src/gui/ntableviewheader.cpp \
    src/gui/ntabwidget.cpp \
    src/gui/ntagview.cpp \
    src/gui/ntagviewdelegate.cpp \
    src/gui/ntagviewitem.cpp \
    src/gui/ntrashtree.cpp \
    src/gui/ntrashviewdelegate.cpp \
    src/gui/numberdelegate.cpp \
    src/gui/nwebpage.cpp \
    src/gui/nwebview.cpp \
    src/gui/plugins/pluginfactory.cpp \
    src/gui/plugins/popplergraphicsview.cpp \
    src/gui/plugins/popplerviewer.cpp \
    src/gui/reminderorderdelegate.cpp \
    src/gui/shortcutkeys.cpp \
    src/gui/traymenu.cpp \
    src/gui/treewidgeteditor.cpp \
    src/gui/truefalsedelegate.cpp \
    src/gui/widgetpanel.cpp \
    src/logger/qsdebugoutput.cpp \
    src/logger/qslog.cpp \
    src/logger/qslogdest.cpp \
    src/models/notecache.cpp \
    src/models/notemodel.cpp \
    src/models/ntreemodel.cpp \
    src/oauth/oauthtokenizer.cpp \
    src/oauth/oauthwindow.cpp \
    src/qevercloud/AsyncResult.cpp \
    src/qevercloud/EventLoopFinisher.cpp \
    src/qevercloud/exceptions.cpp \
    src/qevercloud/generated/constants.cpp \
    src/qevercloud/generated/services.cpp \
    src/qevercloud/generated/types.cpp \
    src/qevercloud/http.cpp \
    src/qevercloud/oauth.cpp \
    src/qevercloud/services_nongenerated.cpp \
    src/reminders/reminderevent.cpp \
    src/reminders/remindermanager.cpp \
    src/settings/accountsmanager.cpp \
    src/settings/colorsettings.cpp \
    src/settings/filemanager.cpp \
    src/settings/startupconfig.cpp \
    src/sql/configstore.cpp \
    src/sql/databaseconnection.cpp \
    src/sql/databaseupgrade.cpp \
    src/sql/datastore.cpp \
    src/sql/favoritesrecord.cpp \
    src/sql/favoritestable.cpp \
    src/sql/filewatchertable.cpp \
    src/sql/linkednotebooktable.cpp \
    src/sql/notebooktable.cpp \
    src/sql/notemetadata.cpp \
    src/sql/notetable.cpp \
    src/sql/nsqlquery.cpp \
    src/sql/resourcetable.cpp \
    src/sql/searchtable.cpp \
    src/sql/sharednotebooktable.cpp \
    src/sql/tagtable.cpp \
    src/sql/usertable.cpp \
    src/html/attachmenticonbuilder.cpp \
    src/html/enmlformatter.cpp \
    src/html/noteformatter.cpp \
    src/html/tagscanner.cpp \
    src/html/thumbnailer.cpp \
    src/threads/browserrunner.cpp \
    src/threads/counterrunner.cpp \
    src/threads/indexrunner.cpp \
    src/threads/syncrunner.cpp \
    src/utilities/crossmemorymapper.cpp \
    src/utilities/debugtool.cpp \
    src/utilities/encrypt.cpp \
    src/utilities/mimereference.cpp \
    src/utilities/noteindexer.cpp \
    src/utilities/nuuid.cpp \
    src/utilities/pixelconverter.cpp \
    src/watcher/filewatcher.cpp \
    src/watcher/filewatchermanager.cpp \
    src/xml/batchimport.cpp \
    src/xml/exportdata.cpp \
    src/xml/importdata.cpp \
    src/xml/importenex.cpp \
    src/xml/xmlhighlighter.cpp \
    src/quentier/utility/StringUtils.cpp \
    src/quentier/utility/StringUtils_p.cpp

HEADERS  += \
    src/application.h \
    src/nixnote.h \
    src/global.h \
    src/cmdtools/addnote.h \
    src/cmdtools/alternote.h \
    src/cmdtools/cmdlinequery.h \
    src/cmdtools/cmdlinetool.h \
    src/cmdtools/deletenote.h \
    src/cmdtools/emailnote.h \
    src/cmdtools/extractnotes.h \
    src/cmdtools/extractnotetext.h \
    src/cmdtools/importnotes.h \
    src/cmdtools/signalgui.h \
    src/communication/communicationerror.h \
    src/communication/communicationmanager.h \
    src/dialog/aboutdialog.h \
    src/dialog/accountdialog.h \
    src/dialog/accountmaintenancedialog.h \
    src/dialog/adduseraccountdialog.h \
    src/dialog/closenotebookdialog.h \
    src/dialog/databasestatus.h \
    src/dialog/emaildialog.h \
    src/dialog/encryptdialog.h \
    src/dialog/endecryptdialog.h \
    src/dialog/faderdialog.h \
    src/dialog/htmlentitiesdialog.h \
    src/dialog/insertlatexdialog.h \
    src/dialog/insertlinkdialog.h \
    src/dialog/locationdialog.h \
    src/dialog/logindialog.h \
    src/dialog/notebookproperties.h \
    src/dialog/notehistoryselect.h \
    src/dialog/noteproperties.h \
    src/dialog/preferences/appearancepreferences.h \
    src/dialog/preferences/debugpreferences.h \
    src/dialog/preferences/emailpreferences.h \
    src/dialog/preferences/exitpreferences.h \
    src/dialog/preferences/localepreferences.h \
    src/dialog/preferences/preferencesdialog.h \
    src/dialog/preferences/searchpreferences.h \
    src/dialog/preferences/syncpreferences.h \
    src/dialog/preferences/thumbnailpreferences.h \
    src/dialog/remindersetdialog.h \
    src/dialog/savedsearchproperties.h \
    src/dialog/shortcutdialog.h \
    src/dialog/spellcheckdialog.h \
    src/dialog/tabledialog.h \
    src/dialog/tagproperties.h \
    src/dialog/watchfolderadd.h \
    src/dialog/watchfolderdialog.h \
    src/email/emailaddress.h \
    src/email/mimeattachment.h \
    src/email/mimecontentformatter.h \
    src/email/mimefile.h \
    src/email/mimehtml.h \
    src/email/mimeinlinefile.h \
    src/email/mimemessage.h \
    src/email/mimemultipart.h \
    src/email/mimepart.h \
    src/email/mimetext.h \
    src/email/quotedprintable.h \
    src/email/smtpclient.h \
    src/email/smtpexports.h \
    src/exits/exitmanager.h \
    src/exits/exitpoint.h \
    src/filters/filtercriteria.h \
    src/filters/filterengine.h \
    src/filters/notesortfilterproxymodel.h \
    src/filters/remotequery.h \
    src/gui/browserWidgets/authoreditor.h \
    src/gui/browserWidgets/colormenu.h \
    src/gui/browserWidgets/dateeditor.h \
    src/gui/browserWidgets/datetimeeditor.h \
    src/gui/browserWidgets/editorbuttonbar.h \
    src/gui/browserWidgets/expandbutton.h \
    src/gui/browserWidgets/fontnamecombobox.h \
    src/gui/browserWidgets/fontsizecombobox.h \
    src/gui/browserWidgets/locationeditor.h \
    src/gui/browserWidgets/notebookmenubutton.h \
    src/gui/browserWidgets/ntitleeditor.h \
    src/gui/browserWidgets/reminderbutton.h \
    src/gui/browserWidgets/table/tablepropertiesdialog.h \
    src/gui/browserWidgets/tageditor.h \
    src/gui/browserWidgets/tageditornewtag.h \
    src/gui/browserWidgets/tagviewer.h \
    src/gui/browserWidgets/urleditor.h \
    src/gui/datedelegate.h \
    src/gui/externalbrowse.h \
    src/gui/favoritesview.h \
    src/gui/favoritesviewdelegate.h \
    src/gui/favoritesviewitem.h \
    src/gui/findreplace.h \
    src/gui/flowlayout.h \
    src/gui/imagedelegate.h \
    src/gui/lineedit.h \
    src/gui/nattributetree.h \
    src/gui/nbrowserwindow.h \
    src/gui/nmainmenubar.h \
    src/gui/nnotebookview.h \
    src/gui/nnotebookviewdelegate.h \
    src/gui/nnotebookviewitem.h \
    src/gui/nsearchview.h \
    src/gui/nsearchviewitem.h \
    src/gui/ntableview.h \
    src/gui/ntableviewheader.h \
    src/gui/ntabwidget.h \
    src/gui/ntagview.h \
    src/gui/ntagviewdelegate.h \
    src/gui/ntagviewitem.h \
    src/gui/ntrashtree.h \
    src/gui/ntrashviewdelegate.h \
    src/gui/numberdelegate.h \
    src/gui/nwebpage.h \
    src/gui/nwebview.h \
    src/gui/plugins/pluginfactory.h \
    src/gui/plugins/popplergraphicsview.h \
    src/gui/plugins/popplerviewer.h \
    src/gui/reminderorderdelegate.h \
    src/gui/shortcutkeys.h \
    src/gui/traymenu.h \
    src/gui/treewidgeteditor.h \
    src/gui/truefalsedelegate.h \
    src/gui/widgetpanel.h \
    src/logger/qsdebugoutput.h \
    src/logger/qslog.h \
    src/logger/qslogdest.h \
    src/models/notecache.h \
    src/models/notemodel.h \
    src/models/ntreemodel.h \
    src/oauth/oauthtokenizer.h \
    src/oauth/oauthwindow.h \
    src/plugins/hunspell/hunspellinterface.h \
    src/qevercloud/AsyncResult.h \
    src/qevercloud/EventLoopFinisher.h \
    src/qevercloud/EverCloudException.h \
    src/qevercloud/exceptions.h \
    src/qevercloud/generated/constants.h \
    src/qevercloud/generated/EDAMErrorCode.h \
    src/qevercloud/generated/services.h \
    src/qevercloud/generated/types.h \
    src/qevercloud/generated/types_impl.h \
    src/qevercloud/globals.h \
    src/qevercloud/http.h \
    src/qevercloud/impl.h \
    src/qevercloud/include/QEverCloud.h \
    src/qevercloud/include/QEverCloudOAuth.h \
    src/qevercloud/oauth.h \
    src/qevercloud/Optional.h \
    src/qevercloud/public.h \
    src/qevercloud/qt4helpers.h \
    src/qevercloud/thrift.h \
    src/qevercloud/thumbnail.h \
    src/reminders/reminderevent.h \
    src/reminders/remindermanager.h \
    src/settings/accountsmanager.h \
    src/settings/colorsettings.h \
    src/settings/filemanager.h \
    src/settings/startupconfig.h \
    src/sql/configstore.h \
    src/sql/databaseconnection.h \
    src/sql/databaseupgrade.h \
    src/sql/datastore.h \
    src/sql/favoritesrecord.h \
    src/sql/favoritestable.h \
    src/sql/filewatchertable.h \
    src/sql/linkednotebooktable.h \
    src/sql/notebooktable.h \
    src/sql/notemetadata.h \
    src/sql/notetable.h \
    src/sql/nsqlquery.h \
    src/sql/resourcetable.h \
    src/sql/searchtable.h \
    src/sql/sharednotebooktable.h \
    src/sql/tagtable.h \
    src/sql/usertable.h \
    src/html/attachmenticonbuilder.h \
    src/html/enmlformatter.h \
    src/html/noteformatter.h \
    src/html/tagscanner.h \
    src/html/thumbnailer.h \
    src/threads/browserrunner.h \
    src/threads/counterrunner.h \
    src/threads/indexrunner.h \
    src/threads/syncrunner.h \
    src/utilities/crossmemorymapper.h \
    src/utilities/debugtool.h \
    src/utilities/encrypt.h \
    src/utilities/mimereference.h \
    src/utilities/noteindexer.h \
    src/utilities/nuuid.h \
    src/utilities/pixelconverter.h \
    src/watcher/filewatcher.h \
    src/watcher/filewatchermanager.h \
    src/xml/batchimport.h \
    src/xml/exportdata.h \
    src/xml/importdata.h \
    src/xml/importenex.h \
    src/xml/xmlhighlighter.h \
    src/quentier/utility/StringUtils.h \
    src/quentier/utility/StringUtils_p.h

# http://doc.qt.io/qt-5/qmake-function-reference.html#str-member-arg-start-end
# $$left(VAR, len)
#left = $$str_member(VAR, 0, $$num_add($$len, -1))

# get g++ version
gcc {
    COMPILER_VERSION = $$system($$QMAKE_CXX " -dumpversion")
    COMPILER_MAJOR_VERSION1 = $$split(COMPILER_VERSION, ".")
    COMPILER_MAJOR_VERSION = $$first(COMPILER_MAJOR_VERSION1)
    message("Compiler version $$COMPILER_MAJOR_VERSION")
    COMPILER_CONFIG = g++$$COMPILER_MAJOR_VERSION
    message("Adding compiler config $$COMPILER_CONFIG")
    CONFIG += $$COMPILER_CONFIG
}

linux:QMAKE_CXXFLAGS += -std=c++11 -g -O2  -Wformat -Werror=format-security
linux:QMAKE_LFLAGS += -Wl,-Bsymbolic-functions -Wl,-z,relro

g++4 {
  # this is a guess, but "stack-protector-strong" may not be available yet
  QMAKE_CXXFLAGS += -fstack-protector
} else {
  QMAKE_CXXFLAGS += -fstack-protector-strong
}


win32:QMAKE_CXXFLAGS +=-g -O2 --param=ssp-buffer-size=4 -Wformat -Werror=format-security
win32:QMAKE_LFLAGS += -Wl,-Bsymbolic-functions
win32:DEFINES += SMTP_BUILD

isEmpty(PREFIX) {
  PREFIX = /usr
}

binary.path = $${PREFIX}/bin
binary.files = $${DESTDIR}/$${TARGET}
binary.CONFIG = no_check_exist
message("Target binary: $${binary.files}")

desktop.path = $${PREFIX}/share/applications
desktop.files = $${TARGET}.desktop

#pixmaps.path = $${PREFIX}/share/pixmaps
#pixmaps.files = resources/icons/nixnote2.png

icons.path = $${PREFIX}/share/icons
icons.files = resources/icons/*

images.path = $${PREFIX}/share/$$TARGET/images
images.files = resources/images/*

java.path = $${PREFIX}/share/$$TARGET/java
java.files = java/*

help.path = $${PREFIX}/share/$$TARGET/help
help.files = help/*

textfiles.path = $${PREFIX}/share/$$TARGET
textfiles.files = $$PWD/shortcuts.txt $$PWD/themes.ini $$PWD/LICENSE $$PWD/colors.txt \
                  $${DESTDIR}/version/build-version.txt $$PWD/version.txt
textfiles.CONFIG = no_check_exist

docs.path = $${PREFIX}/share/doc/$$TARGET
docs.files = $$PWD/debian/copyright $$PWD/debian/changelog $$PWD/README.md $$PWD/docs/shortcuts-howto.md $$PWD/docs/license.html

VERSION_FILES = .
fullversion.input = VERSION_FILES
fullversion.output  = $${DESTDIR}/version/build-version.txt
# echo "$(cat ${QMAKE_FILE_IN})-$(git rev-parse --short HEAD)" >${QMAKE_FILE_OUT}
fullversion.commands = ./development/create-build-version.sh ${QMAKE_FILE_OUT}
fullversion.CONFIG += no_link no_check_exist
QMAKE_EXTRA_COMPILERS += fullversion
PRE_TARGETDEPS += compiler_fullversion_make_all

man.path = $${PREFIX}/share/man/man1
man.files = docs/nixnote2.1


# compile the translation files:
isEmpty(QMAKE_LRELEASE) {
    win32:LANGREL = $$[QT_INSTALL_BINS]\lrelease.exe
    else:LANGREL = $$[QT_INSTALL_BINS]/lrelease
}
TRANSLATION_TARGET_DIR = $${DESTDIR}/translations
langrel.input = TRANSLATIONS
langrel.output = $$TRANSLATION_TARGET_DIR/${QMAKE_FILE_BASE}.qm
langrel.commands = \
    $$LANGREL -compress -nounfinished -removeidentical ${QMAKE_FILE_IN} \
          -qm $$TRANSLATION_TARGET_DIR/${QMAKE_FILE_BASE}.qm
langrel.CONFIG += no_link
QMAKE_EXTRA_COMPILERS += langrel
PRE_TARGETDEPS += compiler_langrel_make_all


mac {
    # TODO 6.2018 this will need minor adjustments

    ICON = images/NixNote2.icns

    # we go for an appbundle that contains all resources (except
    # the shared library dependencies - use macdeployqt for those).
    images.path = Contents/Resources
    images.files = resources/images
    java.path = Contents/Resources
    java.files = java
    mactranslations.path = Contents/Resources/translations
    mactranslations.files = $$files($$TRANSLATION_TARGET_DIR/*.qm)
    mactranslations.depends = compiler_langrel_make_all

    help.path = Contents/Resources
    help.files = help
    QMAKE_BUNDLE_DATA += images java mactranslations help
    INSTALLS = binary
} else {
    translations.path = $${PREFIX}/share/$$TARGET
    translations.files = $$TRANSLATION_TARGET_DIR
    translations.CONFIG = no_check_exist

    INSTALLS = binary desktop images java help textfiles docs man translations icons
}

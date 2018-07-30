# currently additionally  PKG_CONFIG_PATH=$$PWD/../libs/usr/lib/pkgconfig is needed


QT += core gui widgets printsupport webkit webkitwidgets sql network xml dbus qml
DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0
unix {
    CONFIG += link_pkgconfig
    PKGCONFIG += poppler-qt5 libcurl tidy
    QMAKE_RPATHDIR += $$PWD/../libs/lib
}

unix:!mac:LIBS += -lpthread -g -rdynamic

win32:INCLUDEPATH += "$$PWD/winlib/includes/poppler/qt5"
win32:INCLUDEPATH += "$$PWD/winlib/includes"
win32:LIBS += -L"$$PWD/winlib" -lpoppler-qt5
win32:RC_ICONS += "$$PWD/images/windowIcon.ico"


mac {
    TARGET = NixNote2
} else {
    TARGET = nixnote2
}
TEMPLATE = app
RESOURCES = NixNote2.qrc

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
    application.cpp \
    global.cpp \
    main.cpp \
    nixnote.cpp \
    cmdtools/addnote.cpp \
    cmdtools/alternote.cpp \
    cmdtools/cmdlinequery.cpp \
    cmdtools/cmdlinetool.cpp \
    cmdtools/deletenote.cpp \
    cmdtools/emailnote.cpp \
    cmdtools/extractnotes.cpp \
    cmdtools/extractnotetext.cpp \
    cmdtools/importnotes.cpp \
    cmdtools/signalgui.cpp \
    communication/communicationerror.cpp \
    communication/communicationmanager.cpp \
    dialog/aboutdialog.cpp \
    dialog/accountdialog.cpp \
    dialog/accountmaintenancedialog.cpp \
    dialog/adduseraccountdialog.cpp \
    dialog/closenotebookdialog.cpp \
    dialog/databasestatus.cpp \
    dialog/emaildialog.cpp \
    dialog/encryptdialog.cpp \
    dialog/endecryptdialog.cpp \
    dialog/faderdialog.cpp \
    dialog/htmlentitiesdialog.cpp \
    dialog/insertlatexdialog.cpp \
    dialog/insertlinkdialog.cpp \
    dialog/locationdialog.cpp \
    dialog/logindialog.cpp \
    dialog/notebookproperties.cpp \
    dialog/notehistoryselect.cpp \
    dialog/noteproperties.cpp \
    dialog/preferences/appearancepreferences.cpp \
    dialog/preferences/debugpreferences.cpp \
    dialog/preferences/emailpreferences.cpp \
    dialog/preferences/exitpreferences.cpp \
    dialog/preferences/localepreferences.cpp \
    dialog/preferences/preferencesdialog.cpp \
    dialog/preferences/searchpreferences.cpp \
    dialog/preferences/syncpreferences.cpp \
    dialog/preferences/thumbnailpreferences.cpp \
    dialog/remindersetdialog.cpp \
    dialog/savedsearchproperties.cpp \
    dialog/screencapture.cpp \
    dialog/shortcutdialog.cpp \
    dialog/spellcheckdialog.cpp \
    dialog/tabledialog.cpp \
    dialog/tagproperties.cpp \
    dialog/watchfolderadd.cpp \
    dialog/watchfolderdialog.cpp \
    email/emailaddress.cpp \
    email/mimeattachment.cpp \
    email/mimecontentformatter.cpp \
    email/mimefile.cpp \
    email/mimehtml.cpp \
    email/mimeinlinefile.cpp \
    email/mimemessage.cpp \
    email/mimemultipart.cpp \
    email/mimepart.cpp \
    email/mimetext.cpp \
    email/quotedprintable.cpp \
    email/smtpclient.cpp \
    exits/exitmanager.cpp \
    exits/exitpoint.cpp \
    filters/filtercriteria.cpp \
    filters/filterengine.cpp \
    filters/notesortfilterproxymodel.cpp \
    filters/remotequery.cpp \
    gui/browserWidgets/authoreditor.cpp \
    gui/browserWidgets/colormenu.cpp \
    gui/browserWidgets/dateeditor.cpp \
    gui/browserWidgets/datetimeeditor.cpp \
    gui/browserWidgets/editorbuttonbar.cpp \
    gui/browserWidgets/expandbutton.cpp \
    gui/browserWidgets/fontnamecombobox.cpp \
    gui/browserWidgets/fontsizecombobox.cpp \
    gui/browserWidgets/locationeditor.cpp \
    gui/browserWidgets/notebookmenubutton.cpp \
    gui/browserWidgets/ntitleeditor.cpp \
    gui/browserWidgets/reminderbutton.cpp \
    gui/browserWidgets/table/tablepropertiesdialog.cpp \
    gui/browserWidgets/tageditor.cpp \
    gui/browserWidgets/tageditornewtag.cpp \
    gui/browserWidgets/tagviewer.cpp \
    gui/browserWidgets/urleditor.cpp \
    gui/datedelegate.cpp \
    gui/externalbrowse.cpp \
    gui/favoritesview.cpp \
    gui/favoritesviewdelegate.cpp \
    gui/favoritesviewitem.cpp \
    gui/findreplace.cpp \
    gui/flowlayout.cpp \
    gui/imagedelegate.cpp \
    gui/lineedit.cpp \
    gui/nattributetree.cpp \
    gui/nbrowserwindow.cpp \
    gui/nmainmenubar.cpp \
    gui/nnotebookview.cpp \
    gui/nnotebookviewdelegate.cpp \
    gui/nnotebookviewitem.cpp \
    gui/nsearchview.cpp \
    gui/nsearchviewitem.cpp \
    gui/ntableview.cpp \
    gui/ntableviewheader.cpp \
    gui/ntabwidget.cpp \
    gui/ntagview.cpp \
    gui/ntagviewdelegate.cpp \
    gui/ntagviewitem.cpp \
    gui/ntrashtree.cpp \
    gui/ntrashviewdelegate.cpp \
    gui/numberdelegate.cpp \
    gui/nwebpage.cpp \
    gui/nwebview.cpp \
    gui/plugins/pluginfactory.cpp \
    gui/plugins/popplergraphicsview.cpp \
    gui/plugins/popplerviewer.cpp \
    gui/reminderorderdelegate.cpp \
    gui/shortcutkeys.cpp \
    gui/traymenu.cpp \
    gui/treewidgeteditor.cpp \
    gui/truefalsedelegate.cpp \
    gui/widgetpanel.cpp \
    logger/qsdebugoutput.cpp \
    logger/qslog.cpp \
    logger/qslogdest.cpp \
    models/notecache.cpp \
    models/notemodel.cpp \
    models/ntreemodel.cpp \
    oauth/oauthtokenizer.cpp \
    oauth/oauthwindow.cpp \
    qevercloud/AsyncResult.cpp \
    qevercloud/EventLoopFinisher.cpp \
    qevercloud/exceptions.cpp \
    qevercloud/generated/constants.cpp \
    qevercloud/generated/services.cpp \
    qevercloud/generated/types.cpp \
    qevercloud/http.cpp \
    qevercloud/oauth.cpp \
    qevercloud/services_nongenerated.cpp \
    reminders/reminderevent.cpp \
    reminders/remindermanager.cpp \
    settings/accountsmanager.cpp \
    settings/colorsettings.cpp \
    settings/filemanager.cpp \
    settings/startupconfig.cpp \
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
    src/xml/xmlhighlighter.cpp

HEADERS  += \
    application.h \
    nixnote.h \
    global.h \
    cmdtools/addnote.h \
    cmdtools/alternote.h \
    cmdtools/cmdlinequery.h \
    cmdtools/cmdlinetool.h \
    cmdtools/deletenote.h \
    cmdtools/emailnote.h \
    cmdtools/extractnotes.h \
    cmdtools/extractnotetext.h \
    cmdtools/importnotes.h \
    cmdtools/signalgui.h \
    communication/communicationerror.h \
    communication/communicationmanager.h \
    dialog/aboutdialog.h \
    dialog/accountdialog.h \
    dialog/accountmaintenancedialog.h \
    dialog/adduseraccountdialog.h \
    dialog/closenotebookdialog.h \
    dialog/databasestatus.h \
    dialog/emaildialog.h \
    dialog/encryptdialog.h \
    dialog/endecryptdialog.h \
    dialog/faderdialog.h \
    dialog/htmlentitiesdialog.h \
    dialog/insertlatexdialog.h \
    dialog/insertlinkdialog.h \
    dialog/locationdialog.h \
    dialog/logindialog.h \
    dialog/notebookproperties.h \
    dialog/notehistoryselect.h \
    dialog/noteproperties.h \
    dialog/preferences/appearancepreferences.h \
    dialog/preferences/debugpreferences.h \
    dialog/preferences/emailpreferences.h \
    dialog/preferences/exitpreferences.h \
    dialog/preferences/localepreferences.h \
    dialog/preferences/preferencesdialog.h \
    dialog/preferences/searchpreferences.h \
    dialog/preferences/syncpreferences.h \
    dialog/preferences/thumbnailpreferences.h \
    dialog/remindersetdialog.h \
    dialog/savedsearchproperties.h \
    dialog/screencapture.h \
    dialog/shortcutdialog.h \
    dialog/spellcheckdialog.h \
    dialog/tabledialog.h \
    dialog/tagproperties.h \
    dialog/watchfolderadd.h \
    dialog/watchfolderdialog.h \
    email/emailaddress.h \
    email/mimeattachment.h \
    email/mimecontentformatter.h \
    email/mimefile.h \
    email/mimehtml.h \
    email/mimeinlinefile.h \
    email/mimemessage.h \
    email/mimemultipart.h \
    email/mimepart.h \
    email/mimetext.h \
    email/quotedprintable.h \
    email/smtpclient.h \
    email/smtpexports.h \
    exits/exitmanager.h \
    exits/exitpoint.h \
    filters/filtercriteria.h \
    filters/filterengine.h \
    filters/notesortfilterproxymodel.h \
    filters/remotequery.h \
    gui/browserWidgets/authoreditor.h \
    gui/browserWidgets/colormenu.h \
    gui/browserWidgets/dateeditor.h \
    gui/browserWidgets/datetimeeditor.h \
    gui/browserWidgets/editorbuttonbar.h \
    gui/browserWidgets/expandbutton.h \
    gui/browserWidgets/fontnamecombobox.h \
    gui/browserWidgets/fontsizecombobox.h \
    gui/browserWidgets/locationeditor.h \
    gui/browserWidgets/notebookmenubutton.h \
    gui/browserWidgets/ntitleeditor.h \
    gui/browserWidgets/reminderbutton.h \
    gui/browserWidgets/table/tablepropertiesdialog.h \
    gui/browserWidgets/tageditor.h \
    gui/browserWidgets/tageditornewtag.h \
    gui/browserWidgets/tagviewer.h \
    gui/browserWidgets/urleditor.h \
    gui/datedelegate.h \
    gui/externalbrowse.h \
    gui/favoritesview.h \
    gui/favoritesviewdelegate.h \
    gui/favoritesviewitem.h \
    gui/findreplace.h \
    gui/flowlayout.h \
    gui/imagedelegate.h \
    gui/lineedit.h \
    gui/nattributetree.h \
    gui/nbrowserwindow.h \
    gui/nmainmenubar.h \
    gui/nnotebookview.h \
    gui/nnotebookviewdelegate.h \
    gui/nnotebookviewitem.h \
    gui/nsearchview.h \
    gui/nsearchviewitem.h \
    gui/ntableview.h \
    gui/ntableviewheader.h \
    gui/ntabwidget.h \
    gui/ntagview.h \
    gui/ntagviewdelegate.h \
    gui/ntagviewitem.h \
    gui/ntrashtree.h \
    gui/ntrashviewdelegate.h \
    gui/numberdelegate.h \
    gui/nwebpage.h \
    gui/nwebview.h \
    gui/plugins/pluginfactory.h \
    gui/plugins/popplergraphicsview.h \
    gui/plugins/popplerviewer.h \
    gui/reminderorderdelegate.h \
    gui/shortcutkeys.h \
    gui/traymenu.h \
    gui/treewidgeteditor.h \
    gui/truefalsedelegate.h \
    gui/widgetpanel.h \
    logger/qsdebugoutput.h \
    logger/qslog.h \
    logger/qslogdest.h \
    models/notecache.h \
    models/notemodel.h \
    models/ntreemodel.h \
    oauth/oauthtokenizer.h \
    oauth/oauthwindow.h \
    plugins/hunspell/hunspellinterface.h \
    plugins/webcam/webcaminterface.h \
    qevercloud/AsyncResult.h \
    qevercloud/EventLoopFinisher.h \
    qevercloud/EverCloudException.h \
    qevercloud/exceptions.h \
    qevercloud/generated/constants.h \
    qevercloud/generated/EDAMErrorCode.h \
    qevercloud/generated/services.h \
    qevercloud/generated/types.h \
    qevercloud/generated/types_impl.h \
    qevercloud/globals.h \
    qevercloud/http.h \
    qevercloud/impl.h \
    qevercloud/include/QEverCloud.h \
    qevercloud/include/QEverCloudOAuth.h \
    qevercloud/oauth.h \
    qevercloud/Optional.h \
    qevercloud/public.h \
    qevercloud/qt4helpers.h \
    qevercloud/thrift.h \
    qevercloud/thumbnail.h \
    reminders/reminderevent.h \
    reminders/remindermanager.h \
    settings/accountsmanager.h \
    settings/colorsettings.h \
    settings/filemanager.h \
    settings/startupconfig.h \
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
    src/xml/xmlhighlighter.h

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
 PREFIX = /usr/local
}

binary.path = $${PREFIX}/bin
binary.files = $${DESTDIR}/$${TARGET}
message("Target binary: $${binary.files}")

desktop.path = $${PREFIX}/share/applications
desktop.files = $${TARGET}.desktop

images.path = $${PREFIX}/share/$$TARGET/images
images.files = images/*

java.path = $${PREFIX}/share/$$TARGET/java
java.files = java/*

help.path = $${PREFIX}/share/$$TARGET/help
help.files = help/*

resources.path = $${PREFIX}/share/$$TARGET
resources.files = $$PWD/shortcuts.txt $$PWD/themes.ini $$PWD/LICENSE $$PWD/colors.txt \
                  $${DESTDIR}/build-version.txt $$PWD/version.txt

# compile the translation files:
isEmpty(QMAKE_LRELEASE) {
    win32:LANGREL = $$[QT_INSTALL_BINS]\lrelease.exe
    else:LANGREL = $$[QT_INSTALL_BINS]/lrelease
}
TRANSLATION_TARGET_DIR = $${OUT_PWD}/translations
langrel.input = TRANSLATIONS
langrel.output = $$TRANSLATION_TARGET_DIR/${QMAKE_FILE_BASE}.qm
langrel.commands = \
    $$LANGREL -compress -nounfinished -removeidentical ${QMAKE_FILE_IN} -qm $$TRANSLATION_TARGET_DIR/${QMAKE_FILE_BASE}.qm
langrel.CONFIG += no_link
QMAKE_EXTRA_COMPILERS += langrel
# this launches the actual work:
PRE_TARGETDEPS += compiler_langrel_make_all


mac {
    # TODO 6.2018 this will need minor adjustments

    ICON = images/NixNote2.icns

    # we go for an appbundle that contains all resources (except
    # the shared library dependencies - use macdeployqt for those).
    images.path = Contents/Resources
    images.files = images
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
    translations.path = $${PREFIX}/share/$$TARGET/translations
    translations.files = $$files($$TRANSLATION_TARGET_DIR/*.qm)
    INSTALLS = binary desktop images java translations help resources
}

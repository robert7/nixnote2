#ifndef SIGNALGUI_H
#define SIGNALGUI_H

#include <QObject>

class SignalGui : public QObject
{
    Q_OBJECT
public:
    SignalGui();
    bool takeScreenshot;
    bool openNote;
    bool openNoteUrl;
    bool openExternalNote;
    bool openExternalNoteUrl;
    bool openNoteNewTab;
    bool openNoteNewTabUrl;
    bool newExternalNote;
    bool newNote;
    bool shutdown;
    bool synchronize;
    bool show;
    qint32 lid;
    QString url;

};

#endif // SIGNALGUI_H

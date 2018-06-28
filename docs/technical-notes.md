# Technical notes
* Here I will try to write some note-snippets about internal architecture.
* I will try to add some text as I discover some relationships. 
* **Caution:** some info here may be not 100% accurate. And probably - at all times - there will
  be more info missing then contained.

## Classes
* NoteTable - database interface for notes    
* NoteModel - handles "note model" - relation ship between internal representation (database table 
  NoteTable) and provides source data for table view with notes.
  Here the multi column sorting is handled.
* NixNote (nixnote.cpp) - main window
  * 1:N with NBrowserWindow
* NTabWidget - handles tab bar over note edit window (and the 1:N relationship between main window (NixNote)
  and NBrowserWindow)
  * also holds a list of browser tabs (NBrowserWindow) and external browser windows ()
  * and does sync between them
* NBrowserWindow - represents one tab with note (in a tabbed interface) 
  * methods/signals
    * updateNoteList(lid, column, data) => signal that some table column changes data
    * saveNoteContent() - called to save note content (also validates HTML) 
  * NTitleEditor - title editor - instantiated in NBrowserWindow, but someway passed down
  * NWebView - editor + some related stuff (actions, toolbar) 
    * NWebPage - just the html editor itself
+ ExternalBrowse - external browser window
  * uses internally NBrowserWindow for content edit
* NTableView - table view with notes 
  * slots
    * refreshCell(lid, column, data) - refresh one cell
    * refreshData() - refresh whole table (does select from DB; more expensive then refreshCell())
    
## QT notes
* QVariant
  * QVariant::QVariant() - create invalid variant => variant.isValid()
  * http://doc.qt.io/qt-5/qvariant.html
* enum Qt::ItemDataRole - model - role
  * http://doc.qt.io/qt-5/qt.html#ItemDataRole-enum
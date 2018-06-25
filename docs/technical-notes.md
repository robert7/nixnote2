# Technical notes
* Here I will try to write some note-snippets about internal architecture.
* I will try to add some text as I discover some relationships. 
* **Caution:** Some info here may be not 100% accurate.

## Classes
* NixNote (nixnote.cpp) - main window
  * 1:N with NBrowserWindow
* NBrowserWindow - represents one tab with note 
  * signals
    * updateNoteList(lid, column, data) => signal that some table column changes data 
* NTabWidget - handles tab bar over note edit window (and the 1:N relationship between main window (NixNote)
  and NBrowserWindow)
* NoteModel - handles "note model" - relation ship between internal representation (database table 
  NoteTable) and provides source data for table view with notes.
  Here the multi column sorting is handled.
* NTableView - table view with notes 
  * slots
    * refreshCell(lid, column, data) - refresh one cell
    * refreshData() - refresh whole table (does select from DB)
# CHANGELOG

## 2018-07
### #8
* **Redesigned html cleanup**. Now newest html tidy libray is used (currently v.5.6). Before system level
  tidy executable was used, which could be like 9 years old.
  Pasting ~any html content into note should work now. Although sometimes images are not recognised.
  Images need to be attached manually (e.g. by drag & drop.) 
* Improved exception handling and logging. Removed log level setting in gui. Log level may now be set
  from command line using e.g. --logLevel=1 for debug level. 
* Changed some setting defaults - e.g. which columns are initially shown (default "title" only).
  Settings can be changed in preferences and are preserved on next run (same as before).     

### #7
* [AppImage packaging](https://appimage.org/) using [linuxdeployqt](https://github.com/probonopd/linuxdeployqt).
  This should allow easy deployment "anywhere" no worry about missing dependencies
  and later use newest libraries.

## 2018-06
### #6
* Focus on search box after "all notes"
* **Title column in note table view now display compound information** - Title + sync needed + relevance hint.
  (Sync is signalized by triangle at begin, if the note is found "more relevant" in search its displaed
  bold). May be later made configurable.
  Main aim is to be able to hide all other columns. Sorting is relevance+date update - so you may
  just display title column & hide all others. See: [compound title preview](https://www.dropbox.com/sh/62lnikzyf4r0sa2/AADMk-EHBwvBt7G5bOga9tyia?dl=0&preview=RS-6-compound-title.png)
* Removed function of opening notes in new tabs - doesn't work stable and is only confusing. Could be 
  re-added back later (commit id 6149a745d014f55352b2e6cad8ff4637414861b7).
* Improved logging in case there is problem with resources (and note is set to read only in nixnote).
  
### #5
* Minor improvement in font color/background color (highlight selection). 
  Tooltip now shows how to use. Keyboard shortcuts possible (default Ctrl-d, Ctrl-Shift-H). Context
  menu option added. Color buttons will preserve state across program restart.
* **Tooltips with kbd shortcut info for all editor and main toolbar icons added.**
* Few more default kbd shortcuts added.  
* Remove hardcoded build in kbd shortcuts (now all comes from shortcuts.ini)
* Changed theme handling - now all themes come from ini file (incl. of the Default theme). This is 
  similar to shortcuts.txt.
* Clear search text, after click on "All notes".  
* Restructured main toolbar.
* Renamed theme.ini to themes.ini because of structure changes prevent loading of legacy user themes 
  (they will need minor fixes to work with new version). To make things easier, now all CSS is inline. 
  Loading from file my be reintroduced later.

* [Preview 1](https://www.dropbox.com/sh/62lnikzyf4r0sa2/AADMk-EHBwvBt7G5bOga9tyia?dl=0&preview=RS-5-toolbar-1.png)
  [Preview 2](https://www.dropbox.com/sh/62lnikzyf4r0sa2/AADMk-EHBwvBt7G5bOga9tyia?dl=0&preview=RS-5-toolbar-2.png)

### #4
* Merged changes from [jeffkowalski/Nixnote2](https://github.com/jeffkowalski/Nixnote2) 
  and [RJVB/nixnote2](https://github.com/RJVB/nixnote2) - **various fixes, build config for macOS**
* **Rewrite of the path handling logic after merge. Now standard compliant path for config and user data are used.**
* Program has 3 directory paths "config dir", "program data dir" (like images), "user data" (database logs)
* All three can be given on commandline for non-standard cases - those have priority (logic is in 
  StartupConfig)
* As fallback legacy config/data is checked: if it exist,s its used => backwards compatibility for existing 
  users
* Else standard paths are used (if nixnote is run out of standard binary path - this is taken - so running 
  more versions on ony system is supported
* There is quite detailed logging of the applied logic, so if it breaks, it should be quite easy to find 
  where
* I'm not sure, if I didn't break the "mac" build logic (merged here from the fork), as I can't really 
  check - but even if yes, it should now be much easier to fix now
* Macro USE_QSP is removed, as it isn't needed anymore
* Not sure if the qt4 build still works, but my opinion its already deprecated and should be removed.

* [Preview](https://www.dropbox.com/sh/62lnikzyf4r0sa2/AADMk-EHBwvBt7G5bOga9tyia?dl=0&preview=RS-4-standard-paths.png)


### #3
* **Added simple search term relevance evaluation for free text search.**
* It tries to sort the found notes according to where the search term was found. If the word was found 
  in title it gets +1 point, if another word is found in title another +1 point. If the word is found 
  in tag +1. 
* Further notes can be manually marked "important" by tagging "important*" - this is similar to 
  "note pinning", but the note only shows up, if it is found according to search terms.
  Its not yet perfectly polished, more like "proof of concept" - but for me already works quite well.
* [Preview](https://www.dropbox.com/sh/62lnikzyf4r0sa2/AADMk-EHBwvBt7G5bOga9tyia?dl=0&preview=RS-3-search-sort-relevance.png)

### #2
* Some note editing and toolbar tweeks (color picker has now restricted list of color; but does'nt really 
  work correctly yet)

### #1
* Merged master to development
* Fixed [#363](https://github.com/baumgarr/nixnote2/issues/363) (**Unknown Tag record key: 1004/1006**)
* Fixed minor error in date (copy of "fixed Date Format setting item bug for yy-MM-dd format" by julee)
* Added new compact date format yyMMdd
* Discarded ellipsis in date columns to allow more compact display
* Fixed fix text typos

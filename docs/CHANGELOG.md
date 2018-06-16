# CHANGELOG

## 2018-06

### #4
* Merged changes from [jeffkowalski/Nixnote2](https://github.com/jeffkowalski/Nixnote2) - **various fixes, build config for macOS**
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

# Changelog

## 6.2.0
  * Fix OAuth with Qt5WebKit with a hack
  * Implement OAuth via system browser so that neither Qt5WebKir nor Qt5WebEngine could be required

## 6.1.0
  * Add ability to retrieve cookies set by Evernote during OAuth procedure and add
  ability to specify cookies in request context for Evernote API calls. These cookies
  suddenly became required in order to execute UserStore API calls.

## 6.0.0
  * Replaced evernoteNetworkAccessManager function with several functions which
  allow to set up network proxy settings. The motivation was the necessity to
  stop using global static instance of QNetworkAccessManager as it started to lead
  to crashes with recent versions of Qt, at least on Windows.

## 5.1.0
  * Restricted the scope of `Q_NAMESPACE` and `Q_ENUM_NS` usage to a single header
  file containing the declarations of EDAM error codes to avoid moc failures with
  recent Qt versions.

## 5.0.0
  * **A lot of new features were added in this release which unfortunately
  required to introduce several API breaks.**
  * Network requests sent to Evernote service via `NoteStore` and `UserStore`
  method calls are now automatically retried if network occasionally fails.
  Retry logic can be parametrized on `NoteStore` or `UserStore` level
  or per each particular method call.
  * `IRequestContext` interface was introduced and added to all methods of
  `NoteStore` and `UserStore` as well as to their constructors. This interface
  allows to specify and track various parameters for each request done from
  QEverCloud to Evernote service: each such request (i.e. each `NoteStore` and
  `UserStore` method call) now has a unique identifier, timeout, parameters
  controlling automatic retry of requests which failed due to network problems.
  Authentication token used for requests to Evernote service is also a part of
  `IRequestContext` interface so it can be conveniently specified for `NoteStore`
  and `UserStore` on their construction and overridden for individual requests
  if necessary.
  * Due to the introduction of request contexts global functions `connectionTimeout`
  and `setConnectionTimeout` were removed. Their names were misleading as they
  were actually request timeouts.
  * Enumerations were migrated to strongly typed ones of modern C++, i.e. they
  are `enum class` now and require explicit cast for conversion to/from integer
  types. There is also no `structs` wrapping enums called `type` anymore so e.g.
  `EDAMErrorCode::type` values are now simply `EDAMErrorCode` ones.
  * Enumerations were also marked with [Q_ENUM_NS](https://doc.qt.io/qt-5/qobject.html#Q_ENUM_NS)
  macro if QEverCloud is built with Qt >= 5.8 and if the corresponding CMake
  option is enabled. This macro adds some introspection capabilities for
  the bespoke enumerations.
  * A dedicated exception class representing network failures was added -
  `NetworkException`. As other QEverCloud's exceptions, it is a subclass of
  `EverCloudException`. By default QEverCloud catches such exceptions on its
  own and retries the request up to several times.
  * Some introspection capabilities were added to QEverCloud types: they now have
  [Q_GADGET](https://doc.qt.io/qt-5/qobject.html#Q_GADGET) macro and each of
  their attributes is registered as a [Q_PROPERTY](https://doc.qt.io/qt-5/qobject.html#Q_PROPERTY).
  * In order to support the above mentioned introspection of QEverCloud types
  `Optional` template class implementation was changed: `operator==` and
  `operator!=` accepting another `Optional` were added to it. Unfortunately, it
  has lead to some complications: you can no longer do comparisons like
  ```
  Optional<int> a = 42;
  double b = 1.0;
  bool res = (a == b);
  ```
  Instead you need to cast the right hand side expression to proper type:
  ```
  Optional<int> a = 42;
  double b = 1.0;
  bool res = (a == static_cast<int>(b));
  ```
  * Each QEverCloud type corresponding to Evernote API's type now has a member
  called `localData` of class `EverCloudLocalData`. That class encapsulates some
  attributes which are not present within Evernote API's types and thus do not
  take part in communication with Evernote but they nevertheless can be useful
  for implementation of rich Evernote client applications performing full and
  partial synchronization of data with Evernote. `EverCloudLocalData`
  contains:
    * `id` string which by default is generated as a `QUuid` but can be substituted
    with any string value
    * `dirty`, `local` and `favorited` boolean flags
    * `dict` which is a collection of arbitrary data in the form of `QVariant`s
    indexed by strings
  * Logging system was added to QEverCloud. It exists as `ILogger` interface
  which you can implement and thus integrate QEverCloud's logging into your
  application's logging system whatever that is. For convenience in debugging
  QEverCloud also provides an option to dump log messages to stderr.
  * For proper support of logging all QEverCloud's types, enumerations and
  exceptions were made printable i.e. they can now be used with `QTextStream`
  and `QDebug` to produce human readable representation of their values.
  * `NoteStore` and `UserStore` classes were converted to `INoteStore` and
  `IUserStore` abstract interfaces. It made the implementation of request retrying
  logic simpler and it is now possible to substitute your own implementations
  of `INoteStore` and/or `IUserStore`, for example, for unit tests of your code
  using QEverCloud.
  * Implementation of `NoteStore` and `UserStore` servers was added to QEverCloud.
  These classes can be used to implement your own backend substituting real Evernote
  service.
  * Unit tests using the functionality of the above mentioned servers were added
  to QEverCloud. Unit tests ensure the correctness of transport layer's implementation
  i.e. the correctness of packing requests to Thrift format and unpacking the
  responses ensuring that no data is lost or corrupted on either step. Hundreds
  of tests covering literally every single method of `NoteStore` and `UserStore`
  were added.
  * Some header files were renamed so that they all start from capital letters
  now.
  * Support for Qt < 5.5 as well as support for building QEverCloud with older
  compilers has been dropped. QEverCloud is now built with C++14 standard
  although it does not use much of its features so even some not fully compliant
  compilers can still build QEverCloud. Minimal supported gcc version is 5.4,
  minimal supported Visual Studio version is 2017.

## 4.1.0
  * Migrate to Evernote API 1.29 from 1.28. The changes are incremental and API is not broken. ABI is changed though,
    hence minor version number increase. The changes in API include:
     * Extension of `EDAMErrorCode` enumeration with new error codes
     * Extension of `NoteFilter`, `NoteList`, `NotesMetadataList`, `RelatedResult`, `RelatedResultSpec`, `UserAttributes`,
       `NotebookRecipientSettings`, `NotebookRestrictions`, `UserProfile`, `BusinessInvitation` structs
     * Extension of SystemLevel enumeration with the item for business users
     * `NoteStore.createNotebook` method can now throw `EDAMNotFoundException` exception
     * Addition of some new constants, enumerations and structs
  * Switch to building with Qt5 by default from building with Qt4 by default: now for building with Qt4 CMake option `BUILD_WITH_QT4` should be enabled and CMake option `USE_QT5` is deprecated and no longer required
  * A possibility to build QEverCloud with enabled sanitizers was added
  * Fixed a bug related to network request timeout processing: API requests never timed out in case of network problems. Now API requests have timeout which by default is 180 seconds. It can be changed through calling `setConnectionTimeout` value.


## 4.0.0
  * Migrate to Evernote API 1.28 from 1.25. Unfortunately, the changes in Evernote API are quite sufficient and hence
    the migration to it has introduced a lot of API breaks in QEverCloud. Please refer to [API breaks from 3 to 4](API_breaks_3_to_4.md)
    documentation for details.
  * Add new CMake options:
    * add QEverCloud's major version as a suffix to the library name
    * add QEverCloud's major version as a suffix to the name of the folder with development headers
    * build QEverCloud library without OAuth support and thus without QtWebKit/QtWebEngine dependency
  * Add new class: `InkNoteImageDownloader` intended, as its name suggests, for downloading the static images generated
    from ink notes.

## 3.0.3
  * Fix building the pdf version of the doc from latex
  * Use three-digit version for the installed library on Linux, have symlink with only the major version number

## 3.0.2
  * Add CMake option `USE_QT5_WEBKIT` to build QEverCloud library with Qt5WebKit instead of Qt5WebEngine for Qt >= 5.4.

## 3.0.1
  * Add missing globals.cpp to qmake project file.
  * Add missing implementations of some declared methods in Thumbnail class.
  * Fix a couple of typos in Thumbnail class' documentation.

## 3.0.0
  * The build system was changed from qmake to CMake; qmake .pro file was left within the package for backward compatibility.
  * Build shared library by default instead of static one.
  * Add unit test for Optional template class.
  * Rearrange the location of installed library's headers, now it is dependent on Qt version used to build the library.

## 2.2.1
  * Fix a bug with incompatible signal/slot connection signatures for Qt4.

## 2.2
  * The support for Qt 4 was returned back.
  * Added the option to use classes from QWebEngine component instead of the ones from QtWebKit for OAuth.

## 2.1
  * == and != operators for Evernote structs are available now.
  * Asynchronous thumbnail download is added.
  * Special exception types for AUTH_EXPIRED and RATE_LIMIT_REACHED errors.
  * Move semantics for Optional is implemented. As a result moving is working for Evernote structs under a conforming compiler (and it's NOT VS2012).

## 2.0
  * Qt 4 is no longer supported.
  * Asynchronous API is introduced.
  * Various non-critical fixes and improvements.

## 1.2
  * Fixed reported issues when compiling under Qt 4, should be no problems now.
  * This is the last version then will try to be compatible with Qt 4.
  * Some optimizations.

## 1.1
  * EvernoteOAuthDialog::open() now works as expected.
  * qsrand() is no longer called by the library.
  * Default algorithm for nonce generation can be replaced, see setNonceGenerator.

## 1.0
  * Initial release.


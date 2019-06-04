# QEverCloud API breaks from major version 3 to major version 4

The API breaks of QEverCloud between major versions 3 and 4 are caused by the migration from Evernote API 1.25 to Evernote API 1.28.
This document attempts to build a comprehensive list of QEverCloud API breaks, however, this list might be incomplete since
Evernote themselves haven't provided any changelog for their API update so far.

## struct User
  * added fields:
    * `serviceLevel` of `ServiceLevel::type` (new enumeration)
    * `photoUrl` of `QString` type
    * `photoUrlLastUpdated` of `Timestamp` type
    * `accountLimits` of `AccountLimits` type (new struct)
  * removed fields:
    * `premiumInfo` - it appears the `PremiumInfo` should now be requested from Evernote API separately, if needed

## struct UserAttributes
  * added fields:
    * `emailAddressLastConfirmed` of `Timestamp` type
    * `passwordUpdated` of `Timestamp` type
    * `salesforcePushEnabled` of `bool` type
    * `shouldLogClientEvent` of `bool` type
  * removed fields:
    * `taxExempt`

## struct Accounting
  * added fields:
    * `availablePoints` of `qint32` type - not documented, no clue what it does, probably it just occasionally got to the public API
      but only really used by the official Evernote client apps.
  * removed fields:
    * `uploadLimit` - use that from `User`'s `accountLimits` field instead
  * deprecated fields (still present in the API but should not be used):
    * `businessId` - use that from `User`'s `businessUserInfo` field instead
    * `businessName` - use that from `User`'s `businessUserInfo` field instead
    * `businessRole` - use that from `User`'s `businessUserInfo` field instead

## struct LinkedNotebook
  * renamed fields:
    * `shareKey` was renamed to `sharedNotebookGlobalId`

## struct Notebook
  * added fields:
    * `recipientSettings` of `SharedNotebookRecipientSettings` type (new struct)

## struct NotebookRestrictions
  * added fields:
    * `noShareNotesWithBusiness` of `bool` type
    * `noRenameNotebook` of `bool` type

## struct SharedNotebookInstanceRestrictions
  * renamed enum items:
    * `ONLY_JOINED_OR_PREVIEW` was renamed to `ASSIGNED`

## struct SharedNotebook
  * added fields:
    * `recipientIdentityId` of `IdentityID` type (new typedef for `qint64` type)
    * `globalId` of `QString` type
    * `sharerUserId` of `UserID` type
    * `recipientUsername` of `QString` type
    * `recipientUserId` of `UserID` type
    * `serviceAssigned` of `Timestamp` type
  * removed fields:
    * `shareKey` - use `globalId` instead

## struct Note
  * added fields:
    * `sharedNotes` of `QList<SharedNote>` type (`SharedNote` is a new struct)
    * `restrictions` of `NoteRestrictions` type (new struct)
    * `limits` of `NoteLimits` type (new struct)

## struct NoteAttributes
  * added fields:
    * `sharedWithBusiness` of `bool` type
    * `conflictSourceNoteGuid` of `QString` type
    * `noteTitleQuality` of `qint32` type

## struct ClientUsageMetrics
  * this struct was completely removed from Evernote API and seemingly has no replacement. It was not really much useful
    for Evernote client apps so it shouldn't be a big loss.

## class UserStore
  * Methods `refreshAuthentication` and `refreshAuthenticatonAsync` were removed as their counterparts were removed from Evernote API. It is not a big loss since these methods were available only to Evernote internal applications anyway.

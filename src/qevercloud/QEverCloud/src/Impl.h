/**
 * Original work: Copyright (c) 2014 Sergey Skoblikov
 * Modified work: Copyright (c) 2015-2019 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms
 * of MIT license:
 * https://opensource.org/licenses/MIT
 */

#ifndef QEVERCLOUD_IMPL_H
#define QEVERCLOUD_IMPL_H

#include "Http.h"
#include "Thrift.h"

#include <Exceptions.h>
#include <Globals.h>
#include <Optional.h>

/**

@mainpage About QEverCloud

This library presents complete Evernote SDK for Qt.
All the functionality that is described on
<a href="http://dev.evernote.com/doc/">Evernote site</a>
is implemented and ready to use. In particular OAuth autentication is implemented.

Include *QEverCloud.h* or *QEverCloudOAuth.h* to use the library. The latter
header is needed if you use OAuth functionality.

<a href="https://github.com/d1vanov/QEverCloud">QEverCloud on GitHub</a>

*/

namespace qevercloud {

/** @cond HIDDEN_SYMBOLS  */

ThriftException readThriftException(ThriftBinaryBufferReader & reader);

void writeThriftException(
    ThriftBinaryBufferWriter & writer, const ThriftException & exception);

void throwEDAMSystemException(const EDAMSystemException & baseException);

/** @endcond */

} // namespace qevercloud

#endif // QEVERCLOUD_IMPL_H

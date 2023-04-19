/**
 * Copyright (c) 2023 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms
 * of MIT license: https://opensource.org/licenses/MIT
 */

#ifndef QEVERCLOUD_OAUTH_NONCE_GENERATOR_H
#define QEVERCLOUD_OAUTH_NONCE_GENERATOR_H

#include <QtGlobal>

namespace qevercloud {

typedef quint64 (*NonceGenerator)();

[[nodiscard]] NonceGenerator nonceGenerator();

} // namespace qevercloud

#endif // QEVERCLOUD_OAUTH_NONCE_GENERATOR_H

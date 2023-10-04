/**
 * Copyright (c) 2019 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms
 * of MIT license:
 * https://opensource.org/licenses/MIT
 */

#ifndef QEVERCLOUD_TEST_OPTIONAL_H
#define QEVERCLOUD_TEST_OPTIONAL_H

#include <QObject>

namespace qevercloud {

class OptionalTester: public QObject
{
    Q_OBJECT
public:
    explicit OptionalTester(QObject * parent = nullptr);

private Q_SLOTS:
    void shouldDetectValueNotSet();
    void shouldClearValue();
    void shouldDetectExternalValueChange();
    void shouldCastToIntFromAscii();
    void shouldInitValue();
    void shouldThrowExceptionOnAttemptToReferenceUnsetValue();
    void shouldAssignFromOtherOptionals();
    void shouldProcessEqualityChecks();
    void shouldProcessStructEqualityChecks();
    void shouldProcessValueMoves();
    void shouldHandleZeroTimestamp();
};

} // namespace qevercloud

#endif // QEVERCLOUD_TEST_OPTIONAL_H

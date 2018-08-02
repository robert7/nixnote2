/*
 * Copyright 2016 Dmitry Ivanov
 *
 * This file is part of libquentier -https://github.com/d1vanov/libquentier
 *
 * libquentier is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, version 3 of the License.
 *
 * libquentier is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with libquentier. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef LIB_QUENTIER_UTILITY_STRING_UTILS_PRIVATE_H
#define LIB_QUENTIER_UTILITY_STRING_UTILS_PRIVATE_H

#include "src/quentier/utility/StringUtils.h"
#include <QHash>
#include <QStringList>

namespace quentier {

class Q_DECL_HIDDEN StringUtilsPrivate
{
public:
    StringUtilsPrivate();

    void removePunctuation(QString & str, const QVector<QChar> & charactersToPreserve) const;
    void removeDiacritics(QString & str) const;
    void removeNewlines(QString & str) const;

private:
    void initialize();

private:
    QString     m_diacriticLetters;
    QStringList m_noDiacriticLetters;
};

} // namespace quentier

#endif // LIB_QUENTIER_UTILITY_STRING_UTILS_PRIVATE_H

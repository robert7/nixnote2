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

#include "src/quentier/utility/StringUtils.h"
#include "src/quentier/utility/StringUtils_p.h"

namespace quentier {

StringUtils::StringUtils() :
    d_ptr(new StringUtilsPrivate)
{}

StringUtils::~StringUtils()
{
    delete d_ptr;
}

void StringUtils::removePunctuation(QString & str, const QVector<QChar> & charactersToPreserve) const
{
    Q_D(const StringUtils);
    d->removePunctuation(str, charactersToPreserve);
}

void StringUtils::removeDiacritics(QString & str) const
{
    Q_D(const StringUtils);
    d->removeDiacritics(str);
}

void StringUtils::removeNewlines(QString & str) const
{
    Q_D(const StringUtils);
    d->removeNewlines(str);
}

} // namespace quentier

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

#include "StringUtils_p.h"
//#include <quentier/logging/QuentierLogger.h>
#include <QRegExp>

namespace quentier {

StringUtilsPrivate::StringUtilsPrivate() :
    m_diacriticLetters(),
    m_noDiacriticLetters()
{
    initialize();
}

void StringUtilsPrivate::removePunctuation(QString & str, const QVector<QChar> & charactersToPreserve) const
{
    QString filterStr = QString::fromUtf8("[`~!@#$%^&()—+=|:;<>«»,.?/{}\'\"\\[\\]]");

    for(auto it = charactersToPreserve.begin(), end = charactersToPreserve.end(); it != end; ++it)
    {
        int pos = -1;
        while((pos = filterStr.indexOf(*it)) >= 0) {
            filterStr.remove(pos, 1);
        }
    }

    QRegExp punctuationFilter(filterStr);
    str.remove(punctuationFilter);
}

void StringUtilsPrivate::removeDiacritics(QString & str) const
{
    //QNTRACE(QStringLiteral("str before normalizing by D form: ") << str);
    str = str.normalized(QString::NormalizationForm_KD);
    //QNTRACE(QStringLiteral("str after normalizing by KD form: ") << str);

    for(int i = 0; i < str.length(); ++i)
    {
        QChar currentCharacter = str[i];
        QChar::Category category = currentCharacter.category();
        if ( (category == QChar::Mark_NonSpacing) ||
             (category == QChar::Mark_SpacingCombining) ||
             (category == QChar::Mark_Enclosing) )
        {
            str.remove(i, 1);
            continue;
        }

        int diacriticIndex = m_diacriticLetters.indexOf(currentCharacter);
        if (diacriticIndex < 0) {
            continue;
        }

        const QString & replacement = m_noDiacriticLetters[diacriticIndex];
        str.replace(i, 1, replacement);
    }

    //QNTRACE(QStringLiteral("str after removing diacritics: ") << str);
}

void StringUtilsPrivate::removeNewlines(QString & str) const
{
    str.replace(QRegExp(QStringLiteral("[\n\r\v\f]")), QStringLiteral(" "));
}

void StringUtilsPrivate::initialize()
{
    m_diacriticLetters = QString::fromUtf8("ŠŒŽšœžŸ¥µÀÁÂÃÄÅÆÇÈÉÊËÌÍÎÏÐÑÒÓÔÕÖØÙÚÛÜÝßàáâãäåæçèéêëìíîïðñòóôõöøùúûüýÿ");
    m_noDiacriticLetters.reserve(m_diacriticLetters.size());
    m_noDiacriticLetters << QStringLiteral("S") << QStringLiteral("OE") << QStringLiteral("Z") << QStringLiteral("s")
                         << QStringLiteral("oe") << QStringLiteral("z") << QStringLiteral("Y") << QStringLiteral("Y")
                         << QStringLiteral("u") << QStringLiteral("A") << QStringLiteral("A") << QStringLiteral("A")
                         << QStringLiteral("A") << QStringLiteral("A") << QStringLiteral("A") << QStringLiteral("AE")
                         << QStringLiteral("C") << QStringLiteral("E") << QStringLiteral("E") << QStringLiteral("E")
                         << QStringLiteral("E") << QStringLiteral("I") << QStringLiteral("I") << QStringLiteral("I")
                         << QStringLiteral("I") << QStringLiteral("D") << QStringLiteral("N") << QStringLiteral("O")
                         << QStringLiteral("O") << QStringLiteral("O") << QStringLiteral("O") << QStringLiteral("O")
                         << QStringLiteral("O") << QStringLiteral("U") << QStringLiteral("U") << QStringLiteral("U")
                         << QStringLiteral("U") << QStringLiteral("Y") << QStringLiteral("s") << QStringLiteral("a")
                         << QStringLiteral("a") << QStringLiteral("a") << QStringLiteral("a") << QStringLiteral("a")
                         << QStringLiteral("a") << QStringLiteral("ae") << QStringLiteral("c") << QStringLiteral("e")
                         << QStringLiteral("e") << QStringLiteral("e") << QStringLiteral("e") << QStringLiteral("i")
                         << QStringLiteral("i") << QStringLiteral("i") << QStringLiteral("i") << QStringLiteral("o")
                         << QStringLiteral("n") << QStringLiteral("o") << QStringLiteral("o") << QStringLiteral("o")
                         << QStringLiteral("o") << QStringLiteral("o") << QStringLiteral("o") << QStringLiteral("u")
                         << QStringLiteral("u") << QStringLiteral("u") << QStringLiteral("u") << QStringLiteral("y")
                         << QStringLiteral("y");
}

} // namespace quentier

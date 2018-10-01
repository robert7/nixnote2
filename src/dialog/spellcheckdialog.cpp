/*********************************************************************************
NixNote - An open-source client for the Evernote service.
Copyright (C) 2014 Randy Baumgarte

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
***********************************************************************************/


#include <QGridLayout>

#include "src/global.h"
#include "spellcheckdialog.h"
#include "src/plugins/hunspell/spellchecker.h"
#include "src/plugins/hunspell/hunspellplugin.h"

extern Global global;

SpellCheckDialog::SpellCheckDialog(QWidget *parent) :
        QDialog(parent) {
    QFont guiFont(global.getGuiFont(font()));
    QFont guiFontBold = guiFont;
    guiFontBold.setBold(true);

    setWindowIcon(global.getIconResource(":spellCheckIcon"));
    language = new QComboBox(this);
    QGridLayout *grid = new QGridLayout(this);
    setLayout(grid);
    QGridLayout *suggestionGrid = new QGridLayout(this);
    QGridLayout *buttonGrid = new QGridLayout(this);

    currentWord = new QLabel(this);
    currentWord->setFont(guiFontBold);
    replacementWord = new QLineEdit(this);
    this->suggestions = new QListWidget(this);

    connect(replacementWord, SIGNAL(textChanged(QString)), this, SLOT(validateInput()));
    connect(this->suggestions, SIGNAL(itemSelectionChanged()), this, SLOT(replacementChosen()));

    suggestionGrid->addWidget(currentWord, 1, 1);
    suggestionGrid->addWidget(new QLabel(tr("Suggestion"), this), 2, 1);
    suggestionGrid->addWidget(replacementWord, 3, 1);
    suggestionGrid->addWidget(this->suggestions, 4, 1);
    suggestionGrid->addWidget(language, 5, 1);
    suggestionGrid->setContentsMargins(10, 10, -10, -10);
    grid->addLayout(suggestionGrid, 1, 1);

    replace = new QPushButton(tr("Replace"));
    ignore = new QPushButton(tr("Ignore"));
    ignoreAll = new QPushButton(tr("Ignore All"));
    addToDictionary = new QPushButton(tr("Add To Dictionary"));

    connect(replace, SIGNAL(clicked()), this, SLOT(replaceButtonPressed()));
    connect(ignore, SIGNAL(clicked()), this, SLOT(ignoreButtonPressed()));
    connect(ignoreAll, SIGNAL(clicked()), this, SLOT(ignoreAllButtonPressed()));
    connect(addToDictionary, SIGNAL(clicked()), this, SLOT(addToDictionaryButtonPressed()));

    QPushButton *cancelButton = new QPushButton(tr("Cancel"), this);
    connect(cancelButton, SIGNAL(clicked()), this, SLOT(cancelButtonPressed()));

    suggestionGrid->addWidget(replace, 1, 2);
    suggestionGrid->addWidget(ignore, 2, 2);
    suggestionGrid->addWidget(ignoreAll, 3, 2);
    suggestionGrid->addWidget(addToDictionary, 4, 2);
    suggestionGrid->setAlignment(Qt::AlignTop);

    buttonGrid->addWidget(new QLabel(this), 1, 1);
    buttonGrid->addWidget(cancelButton, 1, 2);
    buttonGrid->addWidget(new QLabel(this), 1, 3);
    buttonGrid->setColumnStretch(1, 10);
    buttonGrid->setColumnStretch(3, 10);
    grid->addLayout(buttonGrid, 2, 1);
    this->replace->setEnabled(false);
    this->setFont(guiFont);
    loadLanguages();

    connect(language, SIGNAL(currentIndexChanged(int)), this, SLOT(languageChangeRequested(int)));
}

void SpellCheckDialog::setState(QString misspelled, QStringList suggestions) {
    misspelledWord = misspelled;
    currentWord->setText(misspelledWord);

    this->suggestions->clear();
    this->suggestions->addItems(suggestions);

    replacementWord->clear();
}


void SpellCheckDialog::cancelButtonPressed() {
    done(DONE_CANCEL);
}


void SpellCheckDialog::addToDictionaryButtonPressed() {
    done(DONE_CANCEL);
}

void SpellCheckDialog::replaceButtonPressed() {
    done(DONE_REPLACE);
}

void SpellCheckDialog::ignoreButtonPressed() {
    done(DONE_IGNORE);
}

void SpellCheckDialog::ignoreAllButtonPressed() {
    done(DONE_IGNOREALL);
}


void SpellCheckDialog::validateInput() {
    if (replacementWord->text().trimmed() == "") {
        replace->setEnabled(false);}
    else {
        replace->setEnabled(true);
    }
}

void SpellCheckDialog::replacementChosen() {
    replacementWord->setText(suggestions->currentItem()->text());
}

void SpellCheckDialog::loadLanguages() {
    QStringList dictionaryPath = SpellChecker::dictionaryPaths();

    QStringList values;
    // Start loading available language dictionaries
    for (int i = 0; i < dictionaryPath.size(); i++) {
        QDir spellDir(dictionaryPath[i]);
        QStringList filter;
        filter.append("*.aff");
        filter.append("*.dic");
                foreach (QString fileName, spellDir.entryList(filter)) {
                QString lang = fileName;
                lang.chop(4);
                if (!values.contains(lang))
                    values.append(lang);
            }
    }
    language->addItems(values);
    global.settings->beginGroup(INI_GROUP_LOCALE);
    QString dict = global.settings->value("translation").toString();
    global.settings->endGroup();
    if (dict.trimmed() == "") {
        dict = QLocale::system().name();
    }

    int k = language->findText(dict);
    if (k >= 0)
        language->setCurrentIndex(k);

    // for now let the combo shown, even if there is only one entry
    //if (values.size() <=1)
    //    language->setVisible(false);
}


void SpellCheckDialog::languageChangeRequested(int) {
    done(DONE_CHANGELANGUAGE);
}

/*********************************************************************************
NixNote - An open-source client for the Evernote service.
Copyright (C) 2013 Randy Baumgarte

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

#include "nsearchview.h"
#include "src/global.h"
#include "nsearchviewitem.h"
#include "src/dialog/savedsearchproperties.h"
#include "src/sql/searchtable.h"
#include "src/gui/treewidgeteditor.h"
#include "src/gui/widgetpanel.h"
#include "src/sql/nsqlquery.h"

#include <QHeaderView>
#include <QMouseEvent>
#include <QDrag>
#include <QtSql>
#include <QAction>
#include <QMessageBox>
#include <QPainter>

#define NAME_POSITION 0

extern Global global;

// Constructor
NSearchView::NSearchView(QWidget *parent) :
    QTreeWidget(parent)
{
    this->setFont(global.getGuiFont(font()));
    setAcceptDrops(false);
    setDragEnabled(true);

    filterPosition = -1;

    // setup options
    this->setEditTriggers(QAbstractItemView::NoEditTriggers);
    this->setSelectionBehavior(QAbstractItemView::SelectRows);
    this->setSelectionMode(QAbstractItemView::SingleSelection);
    this->setRootIsDecorated(true);
    this->setSortingEnabled(false);
    this->header()->setVisible(false);

    // Build the root item
    QIcon icon = global.getIconResource(":searchIcon");
    root = new NSearchViewItem(this);
    root->setIcon(NAME_POSITION,icon);
    root->setRootColor(true);
    root->setData(NAME_POSITION, Qt::UserRole, "root");
    root->setData(NAME_POSITION, Qt::DisplayRole, tr("Saved Searches"));
    this->addTopLevelItem(root);
    this->loadData();
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    connect(this, SIGNAL(itemExpanded(QTreeWidgetItem*)), this, SLOT(calculateHeight()));
    connect(this, SIGNAL(itemCollapsed(QTreeWidgetItem*)), this, SLOT(calculateHeight()));
    connect(this, SIGNAL(itemSelectionChanged()), this, SLOT(buildSelection()));

    addAction = context.addAction(tr("Create Saved Search"));
    addAction->setShortcut(QKeySequence(Qt::Key_Insert));
    addAction->setShortcutContext(Qt::WidgetShortcut);

    addShortcut = new QShortcut(this);
    addShortcut->setKey(QKeySequence(Qt::Key_Insert));
    addShortcut->setContext(Qt::WidgetShortcut);

    context.addSeparator();
    deleteAction = context.addAction(tr("Delete"));
    deleteAction->setShortcut(QKeySequence(Qt::Key_Delete));

    deleteShortcut = new QShortcut(this);
    deleteShortcut->setKey(QKeySequence(Qt::Key_Delete));
    deleteShortcut->setContext(Qt::WidgetShortcut);

    renameAction = context.addAction(tr("Rename"));
    renameAction->setShortcutContext(Qt::WidgetShortcut);

    context.addSeparator();
    propertiesAction = context.addAction(tr("Properties"));

    connect(addAction, SIGNAL(triggered()), this, SLOT(addRequested()));
    connect(deleteAction, SIGNAL(triggered()), this, SLOT(deleteRequested()));
    connect(renameAction, SIGNAL(triggered()), this, SLOT(renameRequested()));
    connect(propertiesAction, SIGNAL(triggered()), this, SLOT(propertiesRequested()));

    connect(addShortcut, SIGNAL(activated()), this, SLOT(addRequested()));
    connect(deleteShortcut, SIGNAL(activated()), this, SLOT(deleteRequested()));
    this->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
    this->setFrameShape(QFrame::NoFrame);

    expandedImage = new QImage(global.resourceList[":expandedIcon"] != "" ?
            global.resourceList[":expandedIcon"] : ":expandedIcon");
    collapsedImage = new QImage(global.resourceList[":collapsedIcon"] != "" ?
            global.resourceList[":collapsedIcon"] : ":collapsedIcon");

    this->setProperty("animated", false);

    QString css = global.getThemeCss("savedSearchTreeCss");
    if (css!="")
        this->setStyleSheet(css);

}


// Destructor
NSearchView::~NSearchView() {
    delete root;
}



// This allows for the tree item to be toggled.  If the prior item is selected again
// it is deselected.  If it is the root item, we don't permit the selection.
void NSearchView::mousePressEvent(QMouseEvent *event)
{
    QModelIndex item = indexAt(event->pos());
    bool selected = selectionModel()->isSelected(indexAt(event->pos()));
    QTreeView::mousePressEvent(event);
    if (selected && (event->buttons() & Qt::LeftButton))
        selectionModel()->select(item, QItemSelectionModel::Deselect);

    for (int i=0; i<this->selectedItems() .size(); i++) {
        if (this->selectedIndexes().at(i).data(Qt::UserRole) == "root") {
            if (!root->isExpanded())
                root->setExpanded(true);
            selectionModel()->select(this->selectedIndexes().at(i), QItemSelectionModel::Deselect);
        }
    }
}


// Load up the data from the database
void NSearchView::loadData() {
    NSqlQuery query(global.db);
    query.exec("Select lid, name from SearchModel order by name");
    while (query.next()) {
        qint32 lid = query.value(0).toInt();
        SearchTable table(global.db);
        if (!table.isDeleted(lid)) {
            NSearchViewItem *newWidget = new NSearchViewItem();
            newWidget->setData(NAME_POSITION, Qt::DisplayRole, query.value(1).toString());
            newWidget->setData(NAME_POSITION, Qt::UserRole, lid);
            this->dataStore.insert(query.value(0).toInt(), newWidget);
            root->addChild(newWidget);
        }
    }
    query.finish();
}


//*************************************************************
// This function is called when a search has been updated from
// somewhere else.
//*************************************************************
void NSearchView::searchUpdated(qint32 lid, QString name) {
    // Check if it already exists
    if (this->dataStore.contains(lid)) {
        NSearchViewItem *newWidget = this->dataStore.value(lid);
        newWidget->setData(NAME_POSITION, Qt::DisplayRole, name);
        newWidget->setData(NAME_POSITION, Qt::UserRole, lid);
    } else {
        NSearchViewItem *newWidget = new NSearchViewItem();
        newWidget->setData(NAME_POSITION, Qt::DisplayRole, name);
        newWidget->setData(NAME_POSITION, Qt::UserRole, lid);
        this->dataStore.insert(lid, newWidget);
        root->addChild(newWidget);
        if (this->dataStore.count() == 1) {
            this->expandAll();
        }
    }
    this->sortItems(NAME_POSITION, Qt::AscendingOrder);
    resetSize();
    this->sortByColumn(NAME_POSITION);
}


//*************************************************************
// This function is called when a search has been removed
// during a sync.
//*************************************************************
void NSearchView::searchExpunged(qint32 lid) {
    // Check if it already exists
    if (this->dataStore.contains(lid)) {
        NSearchViewItem *item = this->dataStore.value(lid);
        item->parent()->removeChild(item);
        this->dataStore.remove(lid);
    }
    this->resetSize();
}




//*************************************************************
// Calculate the tree height.
//*************************************************************
void NSearchView::calculateHeight()
{
    int h = 0;

    int topLevelCount = topLevelItemCount();

    for(int i = 0;i < topLevelCount;i++)
    {
        QTreeWidgetItem * item = topLevelItem(i);
        h += calculateHeightRec(item);
        h += item->sizeHint(0).height() + 5;
    }

    if(h != 0)
    {
        setMinimumHeight(h);
        setMaximumHeight(h);
    }
    setMaximumWidth(sizeHint().width());
}



int NSearchView::calculateHeightRec(QTreeWidgetItem * item)
{
    if(!item)
        return 0;

    QModelIndex index = indexFromItem(item);

    if(!item->isExpanded())
    {
        return rowHeight(index);
    }

    int h = item->sizeHint(0).height() + 2 + rowHeight(index);
    int childCount = item->childCount();
    for(int i = 0; i < childCount;i++)
    {
        h += calculateHeightRec(item->child(i));
    }

    return h;
}


void NSearchView::resetSize() {
    calculateHeight();
}





//*************************************************************
// This function is called when a user selects something
// within this tree.  It also emits a signal that will
// be picked up by the main nixnote program.
//*************************************************************
void NSearchView::buildSelection() {
    QLOG_TRACE() << "Inside NNotebookView::buildSelection()";

    QList<QTreeWidgetItem*> selectedItems = this->selectedItems();

    // First, find out if we're already viewing history.  If we are we
    // chop off the end of the history & start a new one
    if (global.filterPosition+1 < global.filterCriteria.size()) {
        while (global.filterPosition+1 < global.filterCriteria.size())
            global.filterCriteria.removeLast();
    }

    filterPosition++;
    FilterCriteria *newFilter = new FilterCriteria();
    global.filterCriteria.push_back(newFilter);
    global.filterPosition++;

    if (selectedItems.size() > 0) {
        newFilter->setSavedSearch(*(NSearchViewItem*)(selectedItems[0]));
        qint32 lid = selectedItems[0]->data(NAME_POSITION, Qt::UserRole).toInt();
        SearchTable stable(global.db);
        SavedSearch search;
        if (stable.get(search, lid))
            newFilter->setSearchString(search.query);
    }

    newFilter->resetAttribute = true;
    newFilter->resetFavorite = true;
    newFilter->resetDeletedOnly = true;
    newFilter->resetNotebook =true;
    newFilter->resetTags = true;
    newFilter->resetSavedSearch = true;
    newFilter->resetSearchString = true;

    emit updateSelectionRequested();

    QLOG_TRACE() << "Leaving NNotebookView::buildSelection()";
}


//*************************************************************
// This function is called from the main NixNote class.
// it will reset the items which are selected based upon
// what the user did somewhere else (outside this widget).
//*************************************************************
void NSearchView::updateSelection() {
    blockSignals(true);

    FilterCriteria *criteria = global.getCurrentCriteria();
    if (global.filterPosition != filterPosition) {
        QList<QTreeWidgetItem*> selectedItems = this->selectedItems();
        for (int i=0; i<selectedItems.size() && criteria->resetSavedSearch; i++) {
            selectedItems[i]->setSelected(false);
        }
    }
    filterPosition = global.filterPosition;

    blockSignals(false);
}



//*************************************************************
// This function is called when a user right-clicks on an
// item to bring up the popup menu.
//*************************************************************
void NSearchView::contextMenuEvent(QContextMenuEvent *event) {
    QList<QTreeWidgetItem*> items = selectedItems();
    if (items.size() == 0) {
        propertiesAction->setEnabled(false);
        deleteAction->setEnabled(false);
        renameAction->setEnabled(false);
    } else {
        propertiesAction->setEnabled(true);
        deleteAction->setEnabled(true);
        renameAction->setEnabled(true);
    }
    context.exec(event->globalPos());
}


//*************************************************************
// This function is called when a user clicks "add" from
// the popup menu.
//*************************************************************
void NSearchView::addRequested() {
    SavedSearchProperties dialog;
    QList<QTreeWidgetItem*> items = selectedItems();

    dialog.setLid(0);

    dialog.exec();
    if (!dialog.okPressed)
        return;

    SearchTable table(global.db);
    NSearchViewItem *newWidget = new NSearchViewItem();
    QString name = dialog.name.text().trimmed();
    qint32 lid = table.findByName(name);
    newWidget->setData(NAME_POSITION, Qt::DisplayRole, name);
    newWidget->setData(NAME_POSITION, Qt::UserRole, lid);
    this->dataStore.insert(lid, newWidget);
    root->addChild(newWidget);
    this->sortItems(NAME_POSITION, Qt::AscendingOrder);
    resetSize();
    this->sortByColumn(NAME_POSITION);

    dataStore.insert(lid, newWidget);
}


//*************************************************************
// This function is called when a user clicks "properties"
// from the popup menu.
//*************************************************************
void NSearchView::propertiesRequested() {
    SavedSearchProperties dialog;
    QList<QTreeWidgetItem*> items = selectedItems();

    qint32 lid = items[0]->data(NAME_POSITION, Qt::UserRole).toInt();
    dialog.setLid(lid);

    dialog.exec();
    if (!dialog.okPressed)
        return;
    items[0]->setData(NAME_POSITION, Qt::DisplayRole, dialog.name.text().trimmed());
}



//*************************************************************
// This function is called when a user clicks "delete" from
// the popup menu.
//*************************************************************
void NSearchView::deleteRequested() {
    QList<QTreeWidgetItem*> items = selectedItems();

    qint32 lid = items[0]->data(NAME_POSITION, Qt::UserRole).toInt();
    if (global.confirmDeletes()) {
        QMessageBox msgBox;
        msgBox.setIcon(QMessageBox::Question);
        msgBox.setText(tr("Are you sure you want to delete this saved search?"));
        msgBox.setWindowTitle(tr("Verify Delete"));
        msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
        msgBox.setDefaultButton(QMessageBox::No);
        int ret = msgBox.exec();
        if (ret == QMessageBox::No)
            return;
    }
    SearchTable s(global.db);
    s.deleteSearch(lid);
    items[0]->setHidden(true);
    dataStore.remove(lid);
    emit searchDeleted(lid);
}



//*************************************************************
// This function is called when a user clicks "rename" from
// the popup menu.
//*************************************************************
void NSearchView::renameRequested() {
    editor = new TreeWidgetEditor(this);
    connect(editor, SIGNAL(editComplete()), this, SLOT(editComplete()));

    QList<QTreeWidgetItem*> items = selectedItems();
    editor->setText(items[0]->text(NAME_POSITION));
    editor->lid = items[0]->data(NAME_POSITION, Qt::UserRole).toInt();
    editor->setTreeWidgetItem(items[0], NAME_POSITION);
    QFontMetrics m(font());
    editor->setMinimumHeight(m.height()+4);
    editor->setMaximumHeight(m.height()+4);
    setItemWidget(items[0], NAME_POSITION, editor);
    editor->setFocus();
}



//*************************************************************
// This function is called when a user has finished editing a
// search.
//*************************************************************
void NSearchView::editComplete() {
    QString text = editor->text().trimmed();
    qint32 lid = editor->lid;
    SearchTable table(global.db);
    SavedSearch s;
    table.get(s, lid);
    QString oldName = "";
    if (s.name.isSet())
        oldName = s.name;

    // Check that this search doesn't already exist
    // if it exists, we go back to the original name
    qint32 check = 0;
    if (text.toLower() == oldName.toLower() && text != oldName)
        check = 0;
    else
        check = table.findByName(text);

    if (check != 0 || text.trimmed()=="") {
        NSearchViewItem *item = dataStore[lid];
        QString name = "";
        if (s.name.isSet())
            name = s.name;
        item->setData(NAME_POSITION, Qt::DisplayRole,name);
    } else {
        s.name = text;
        table.update(lid, s, true);
    }
    this->sortItems(NAME_POSITION, Qt::AscendingOrder);
    resetSize();
    this->sortByColumn(NAME_POSITION);
}



QSize NSearchView::sizeHint() {
    return QTreeView::sizeHint();
}



//*************************************************************
// Draw the branches of the tree.
//*************************************************************
void NSearchView::drawBranches(QPainter *painter, const QRect &rect, const QModelIndex &index) const {
    if (!index.child(0,0).isValid())
        return;

    painter->save();
    if (isExpanded(index)) {
        int offset = rect.width()-expandedImage->width()-1;
        int voffset = (rect.height() - expandedImage->height()) / 2;
        painter->drawImage(offset, rect.y()+voffset,*expandedImage);
    } else {
        int offset = rect.width()-collapsedImage->width()-1;
        int voffset = (rect.height() - collapsedImage->height()) / 2;
        painter->drawImage(offset, rect.y()+voffset,*collapsedImage);
    }
    painter->restore();
    return;
}



//*************************************************************
// Process mouse movements.
//*************************************************************
void NSearchView::mouseMoveEvent(QMouseEvent *event)
{
    QTreeView::mouseMoveEvent(event);

    if (currentItem() == nullptr)
        return;

    if (!(event->buttons() & Qt::LeftButton))
        return;

    QDrag *drag = new QDrag(this);
    QMimeData *mimeData = new QMimeData;

    NSearchViewItem *current = (NSearchViewItem*)currentItem();
    QByteArray mime = current->data(NAME_POSITION, Qt::UserRole).toByteArray();

    QString userdata = current->data(NAME_POSITION, Qt::UserRole).toString();
    if (userdata.startsWith("root", Qt::CaseInsensitive))
        return;

    mimeData->setData("application/x-nixnote-search", mime);
    drag->setMimeData(mimeData);

    drag->exec(Qt::MoveAction);
    QTreeView::mouseMoveEvent(event);
}



//*************************************************************
// Reload icens in the tree.  This is useful if the theme
// changes.
//*************************************************************
void NSearchView::reloadIcons() {
    root->setIcon(NAME_POSITION,global.getIconResource(":searchIcon"));
}



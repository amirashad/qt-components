/* 
 * File:   TreeViewerButton.cpp
 * Author: Rashad Amirjanov
 * 
 * Created on May 6, 2012, 12:08 AM
 */

#include "QTreeViewerButton.h"

QTreeViewerButton::QTreeViewerButton(QWidget* parent) : QPushButton(parent),
menu(this) {

    //    TreeViewerMenu *menu = new TreeViewerMenu(this);
    //    menu->addAction("alma");
    setStyleSheet("Text-align:left");
    this->setMenu(&menu);
}

QTreeViewerButton::~QTreeViewerButton() {
}

QTreeWidget *QTreeViewerButton::tree() {
    return menu.tree();
}

void QTreeViewerButton::addSubItemsToList(QVector<QTreeWidgetItem *> *items, QTreeWidgetItem *item) {
    items->append(item);
    for (int i = 0; i < item->childCount(); i++)
        addSubItemsToList(items, item->child(i));
}

QVector<QTreeWidgetItem*> QTreeViewerButton::allItems() {
    QVector<QTreeWidgetItem*> items;
    for (int i = 0; i < tree()->topLevelItemCount(); i++)
        addSubItemsToList(&items, tree()->topLevelItem(i));
    return items;
}

QVector<QTreeWidgetItem*> QTreeViewerButton::checkedItems() {
    QVector<QTreeWidgetItem*> selectedItems;
    QVector<QTreeWidgetItem*> items = allItems();
    for (int i = 0; i < items.count(); i++) {
        if (items[i]->checkState(0) == Qt::Checked) {
            selectedItems.append(items[i]);
        }
    }
    return selectedItems;
}

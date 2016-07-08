/* 
 * File:   TreeViewerButton.cpp
 * Author: Rashad Amirjanov
 * 
 * Created on May 6, 2012, 12:08 AM
 */

#include "TreeViewerButton.h"

TreeViewerButton::TreeViewerButton(QWidget* parent) : QPushButton(parent),
menu(this) {

    //    TreeViewerMenu *menu = new TreeViewerMenu(this);
    //    menu->addAction("alma");
    setStyleSheet("Text-align:left");
    this->setMenu(&menu);
}

TreeViewerButton::~TreeViewerButton() {
}

QTreeWidget *TreeViewerButton::tree() {
    return menu.tree();
}

void TreeViewerButton::addSubItemsToList(QVector<QTreeWidgetItem *> *items, QTreeWidgetItem *item) {
    items->append(item);
    for (int i = 0; i < item->childCount(); i++)
        addSubItemsToList(items, item->child(i));
}

QVector<QTreeWidgetItem*> TreeViewerButton::allItems() {
    QVector<QTreeWidgetItem*> items;
    for (int i = 0; i < tree()->topLevelItemCount(); i++)
        addSubItemsToList(&items, tree()->topLevelItem(i));
    return items;
}

QVector<QTreeWidgetItem*> TreeViewerButton::checkedItems() {
    QVector<QTreeWidgetItem*> selectedItems;
    QVector<QTreeWidgetItem*> items = allItems();
    for (int i = 0; i < items.count(); i++) {
        if (items[i]->checkState(0) == Qt::Checked) {
            selectedItems.append(items[i]);
        }
    }
    return selectedItems;
}

///-------------------------------TreeViewerMenu--------------------------------

TreeViewerMenu::TreeViewerMenu(QWidget *parent) : QMenu(parent),
treeWidget(this) {
    QVBoxLayout *layout = new QVBoxLayout(this);


    setLayout(layout);
    layout->addWidget(&treeWidget);
    //    layout->addWidget(&btClose);
    layout->setContentsMargins(0, 0, 0, 0);
    layout->setSpacing(0);
    setFixedSize(320, 150);

    treeWidget.setHeaderHidden(true);
}

TreeViewerMenu::~TreeViewerMenu() {
}

QTreeWidget *TreeViewerMenu::tree() {
    return &treeWidget;
}

void TreeViewerMenu::showEvent(QShowEvent* evt) {
    if (parentWidget() == NULL) {
        //        printf("is null\n");
        //        fflush(stdout);
        return;
    }
    QRect desktopRect = QApplication::desktop()->screenGeometry(0);
    if (y() + height() > desktopRect.height()) {
        move(x(), y() - height());
    }
    if (x() + width() > desktopRect.width()) {
        move(parentWidget()->x() - width(), y());
    }
}
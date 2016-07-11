/* 
 * File:   QQTreeViewerMenu.cpp
 * Author: Rashad Amirjanov
 * 
 * Created on May 6, 2012, 12:08 AM
 */

#include "QTreeViewerMenu.h"

QTreeViewerMenu::QTreeViewerMenu(QWidget *parent) : QMenu(parent),
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

QTreeViewerMenu::~QTreeViewerMenu() {
}

QTreeWidget *QTreeViewerMenu::tree() {
    return &treeWidget;
}

void QTreeViewerMenu::showEvent(QShowEvent* evt) {
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

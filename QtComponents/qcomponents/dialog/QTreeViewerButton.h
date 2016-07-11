/* 
 * File:   QTreeViewerButton.h
 * Author: Rashad Amirjanov
 *
 * Created on May 6, 2012, 12:08 AM
 */

#ifndef _QTREEVIEWERBUTTON_H
#define	_QTREEVIEWERBUTTON_H

#include <QPushButton>
#include <QTreeWidget>
#include <QMenu>
#include <QVBoxLayout>
#include <QApplication>
#include <QDesktopWidget>

#include "../qcomps_global.h"
#include "QTreeViewerMenu.h"

class QCOMPS_EXPORT QTreeViewerButton : public QPushButton {
    Q_OBJECT
public:
    QTreeViewerButton(QWidget *parent = 0);
    virtual ~QTreeViewerButton();

    QTreeWidget *tree();

    QVector<QTreeWidgetItem *> allItems();
    QVector<QTreeWidgetItem *> checkedItems();
private:
    QTreeViewerMenu menu;

    void addSubItemsToList(QVector<QTreeWidgetItem *> *items, QTreeWidgetItem *item);
public slots:
    //    void treeSelectionChanged();
};

#endif	/* _QTREEVIEWERBUTTON_H */


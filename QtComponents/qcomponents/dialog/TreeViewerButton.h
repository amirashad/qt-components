/* 
 * File:   TreeViewerButton.h
 * Author: Rashad Amirjanov
 *
 * Created on May 6, 2012, 12:08 AM
 */

#ifndef TREEVIEWERMENU_H
#define	TREEVIEWERMENU_H

#include <QtWidgets/QPushButton>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QMenu>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDesktopWidget>
#include "../qcomps_global.h"

class QCOMPS_EXPORT TreeViewerMenu : public QMenu {
    Q_OBJECT
public:
    TreeViewerMenu(QWidget *parent = 0);
    virtual ~TreeViewerMenu();

    QTreeWidget *tree();
protected:
    void showEvent(QShowEvent* evt);
private:
    QTreeWidget treeWidget;
    //    QPushButton btClose;
};

#endif	/* TREEVIEWERMENU_H */

#ifndef TREEVIEWERBUTTON_H
#define	TREEVIEWERBUTTON_H

//#include <QtGui>

class QCOMPS_EXPORT TreeViewerButton : public QPushButton {
    Q_OBJECT
public:
    TreeViewerButton(QWidget *parent = 0);
    virtual ~TreeViewerButton();

    QTreeWidget *tree();

    QVector<QTreeWidgetItem *> allItems();
    QVector<QTreeWidgetItem *> checkedItems();
private:
    TreeViewerMenu menu;

    void addSubItemsToList(QVector<QTreeWidgetItem *> *items, QTreeWidgetItem *item);
public slots:
    //    void treeSelectionChanged();
};

#endif	/* TREEVIEWERBUTTON_H */


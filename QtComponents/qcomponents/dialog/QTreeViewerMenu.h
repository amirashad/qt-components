/* 
 * File:   QTreeViewerMenu.h
 * Author: Rashad Amirjanov
 *
 * Created on May 6, 2012, 12:08 AM
 */

#ifndef _QTREEVIEWERMENU_H
#define	_QTREEVIEWERMENU_H

#include <QPushButton>
#include <QTreeWidget>
#include <QMenu>
#include <QVBoxLayout>
#include <QApplication>
#include <QDesktopWidget>
#include "../qcomps_global.h"

class QCOMPS_EXPORT QTreeViewerMenu : public QMenu {
    Q_OBJECT
public:
    QTreeViewerMenu(QWidget *parent = 0);
    virtual ~QTreeViewerMenu();

    QTreeWidget *tree();
protected:
    void showEvent(QShowEvent* evt);
private:
    QTreeWidget treeWidget;
    //    QPushButton btClose;
};

#endif	/* _QTREEVIEWERMENU_H */


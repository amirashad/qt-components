/* 
 * File:   QTouchDialog.h
 * Author: Rashad Amirjanov
 *
 * Created on May 7, 2009, 4:43 PM
 */

#ifndef _QTOUCHDIALOG_H
#define	_QTOUCHDIALOG_H

#include <QWidget>
#include <QDialog>
#include <QPushButton>
#include <QLayout>
#include <QLineEdit>
#include <QComboBox>
#include <QKeyEvent>
#include <QString>

#include "../qcomps_global.h"

class QCOMPS_EXPORT QTouchDialog : public QDialog {
public:

    QTouchDialog(QWidget * parent);
    virtual ~QTouchDialog();
protected:

    void showEvent(QShowEvent *);
    void closeEvent(QCloseEvent *);
};

#endif	/* _QTOUCHDIALOG_H */


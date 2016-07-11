/* 
 * File:   QClickableDialog.h
 * Author: Rashad Amirjanov
 *
 * Created on February 19, 2011, 7:19 PM
 */

#ifndef QCLICKABLEDIALOG_H
#define	QCLICKABLEDIALOG_H

#include <QDialog>
#include <QMouseEvent>

#include "../qcomps_global.h"

class QCOMPS_EXPORT QClickableDialog : public QDialog {
    Q_OBJECT
public:
    QClickableDialog(QWidget *parent = 0);
    virtual ~QClickableDialog();
protected:
    void mouseReleaseEvent(QMouseEvent *);
private:

signals:
    void clicked();
};

#endif	/* QCLICKABLEDIALOG_H */


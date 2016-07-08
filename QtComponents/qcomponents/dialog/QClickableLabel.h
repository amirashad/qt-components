/* 
 * File:   QClickableLabel.h
 * Author: Rashad Amirjanov
 *
 * Created on February 19, 2011, 7:19 PM
 */

#ifndef QCLICKABLELABEL_H
#define	QCLICKABLELABEL_H

#include <QtWidgets/QLabel>
#include <QtGui/QMouseEvent>
#include "../qcomps_global.h"

class QCOMPS_EXPORT QClickableLabel : public QLabel {
    Q_OBJECT
public:
    QClickableLabel(QWidget *parent = 0);
    virtual ~QClickableLabel();
protected:
    void mouseReleaseEvent(QMouseEvent *);
private:

signals:
    void clicked();
};

#endif	/* QCLICKABLEDIALOG_H */


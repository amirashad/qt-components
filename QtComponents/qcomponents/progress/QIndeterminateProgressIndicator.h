/* 
 * File:   IndeterminateProgressIndicator.h
 * Author: Rashad Amirjanov
 *
 * Created on April 12, 2010, 11:53 AM
 */

#ifndef _IndeterminateProgressIndicator_H
#define	_IndeterminateProgressIndicator_H

#include <QProgressBar>
#include "../qcomps_global.h"

class QCOMPS_EXPORT IndeterminateProgressIndicator : public QProgressBar {
    //    Q_OBJECT
public:
    IndeterminateProgressIndicator(QWidget *parent = 0);
    virtual ~IndeterminateProgressIndicator();
    //protected:
    //    void timerEvent(QTimerEvent *);
private:
};

#endif	/* _IndeterminateProgressIndicator_H */

/* 
 * File:   QIndeterminateProgressIndicator.h
 * Author: Rashad Amirjanov
 *
 * Created on April 12, 2010, 11:53 AM
 */

#ifndef _QINDETERMINATEPROGRESSINDICATOR_H
#define	_QINDETERMINATEPROGRESSINDICATOR_H

#include <QProgressBar>
#include "../qcomps_global.h"

class QCOMPS_EXPORT QIndeterminateProgressIndicator : public QProgressBar {
    //    Q_OBJECT
public:
    QIndeterminateProgressIndicator(QWidget *parent = 0);
    virtual ~QIndeterminateProgressIndicator();
    //protected:
    //    void timerEvent(QTimerEvent *);
private:
};

#endif	/* _QINDETERMINATEPROGRESSINDICATOR_H */

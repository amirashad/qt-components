/* 
 * File:   QClickableLabel.cpp
 * Author: Rashad Amirjanov
 * 
 * Created on February 19, 2011, 7:19 PM
 */

#include "QClickableLabel.h"
//#include <stdio.h>

QClickableLabel::QClickableLabel(QWidget * parent) : QLabel(parent) {
    setCursor(Qt::PointingHandCursor);
}

QClickableLabel::~QClickableLabel() {
}

void QClickableLabel::mouseReleaseEvent(QMouseEvent*evt) {
    if (evt->button() == Qt::LeftButton && this->rect().contains(evt->pos())) {
//        printf("cliecked\n");
        emit clicked();
    }
}


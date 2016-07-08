/* 
 * File:   QClickableDialog.cpp
 * Author: Rashad Amirjanov
 * 
 * Created on February 19, 2011, 7:19 PM
 */

#include "QClickableDialog.h"
#include <stdio.h>

QClickableDialog::QClickableDialog(QWidget * parent) : QDialog(parent) {

}

QClickableDialog::~QClickableDialog() {
}

void QClickableDialog::mouseReleaseEvent(QMouseEvent*evt) {
    if (evt->button() == Qt::LeftButton && this->rect().contains(evt->pos())) {
//        printf("cliecked\n");
        emit clicked();
    }
}


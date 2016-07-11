/* 
 * File:   QTouchDialog.cpp
 * Author: Rashad Amirjanov
 *
 * Created on May 7, 2009, 4:43 PM
 */

#include <typeinfo>

#include "QTouchDialog.h"
#include "QTouchScreenKeyboard.h"

QTouchDialog::QTouchDialog(QWidget * parent = 0) : QDialog(parent) {

}

QTouchDialog::~QTouchDialog() {

}

void QTouchDialog::showEvent(QShowEvent *) {
    QTouchScreenKeyboard::showKeyboard(this);
}

void QTouchDialog::closeEvent(QCloseEvent *) {
    QTouchScreenKeyboard::hideKeyboard();
}

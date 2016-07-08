/* 
 * File:   splashdialog.h
 * Author: Rashad Amirjanov
 *
 * Created on April 29, 2009, 11:40 AM
 */

#ifndef _SPLASHDIALOG_H
#define	_SPLASHDIALOG_H

#include <QtWidgets/QDialog>
#include <QtWidgets/QWidget>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QMessageBox>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtGui/QMouseEvent>
#include <QtCore/QTimer>
#include "../qcomps_global.h"

class QCOMPS_EXPORT SplashScreenDialog : public QDialog {
    Q_OBJECT
public:
    SplashScreenDialog();
    ~SplashScreenDialog();

    void openSplash();
    void closeSplash();

    void setPixmap(QPixmap px);
private:
    QLabel *lbImage, *lbText;
    QVBoxLayout *vMainLayout, *vLayoutText;

    static SplashScreenDialog *splashScreenDlg;
public:
    static void openSplashDialog(QPixmap px);
    static void closeSplashDialog();
};

#endif	/* _SPLASHDIALOG_H */


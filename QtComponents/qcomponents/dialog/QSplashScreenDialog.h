/* 
 * File:   QSplashScreenDialog.h
 * Author: Rashad Amirjanov
 *
 * Created on April 29, 2009, 11:40 AM
 */

#ifndef _QSPLASHSCREENDIALOG_H
#define	_QSPLASHSCREENDIALOG_H

#include <QDialog>
#include <QWidget>
#include <QGridLayout>
#include <QToolButton>
#include <QMessageBox>
#include <QApplication>
#include <QLabel>
#include <QVBoxLayout>
#include <QMouseEvent>
#include <QTimer>
#include "../qcomps_global.h"

class QCOMPS_EXPORT QSplashScreenDialog : public QDialog {
    Q_OBJECT
public:
    QSplashScreenDialog();
    ~QSplashScreenDialog();

    void openSplash();
    void closeSplash();

    void setPixmap(QPixmap px);
private:
    QLabel *lbImage, *lbText;
    QVBoxLayout *vMainLayout, *vLayoutText;

    static QSplashScreenDialog *splashScreenDlg;
public:
    static void openSplashDialog(QPixmap px);
    static void closeSplashDialog();
};

#endif	/* _QSPLASHSCREENDIALOG_H */


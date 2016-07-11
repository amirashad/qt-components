/* 
 * File:   QSplashScreenDialog.cpp
 * Author: Rashad Amirjanov
 *
 * Created on April 29, 2009, 11:40 AM
 */

#include "QSplashScreenDialog.h"

QSplashScreenDialog *QSplashScreenDialog::splashScreenDlg = NULL;

QSplashScreenDialog::QSplashScreenDialog() : QDialog(NULL) {
    setWindowFlags(Qt::SplashScreen);
    QPalette palette1(QColor(188, 220, 240, 225));
    setPalette(palette1);

    lbImage = new QLabel("");
    lbText = new QLabel(tr("Loading..."), lbImage);
    QFont fntText = font();
    fntText.setPixelSize(12);
    lbText->setFont(fntText);
    QPalette pal = lbText->palette();
    pal.setColor(QPalette::WindowText, QColor(163, 63, 45));
    lbText->setPalette(pal);
    lbText->setAlignment(Qt::AlignCenter);

    vLayoutText = new QVBoxLayout(lbImage);
    vLayoutText->addStretch(0);
    vLayoutText->addWidget(lbText);

    vMainLayout = new QVBoxLayout(this);
    vMainLayout->setContentsMargins(5, 5, 5, 5);
    vMainLayout->addWidget(lbImage);
}

QSplashScreenDialog::~QSplashScreenDialog() {
    delete vLayoutText;
    delete lbText;
    delete lbImage;
    delete vMainLayout;
}

void QSplashScreenDialog::openSplash() {
    show();
}

void QSplashScreenDialog::closeSplash() {
    close();
}

void QSplashScreenDialog::setPixmap(QPixmap px) {
    lbImage->setPixmap(px);
}

void QSplashScreenDialog::openSplashDialog(QPixmap px) {
    splashScreenDlg = new QSplashScreenDialog();
    splashScreenDlg->setPixmap(px);
    splashScreenDlg->openSplash();
}

void QSplashScreenDialog::closeSplashDialog() {
    splashScreenDlg->closeSplash();
    delete splashScreenDlg;
    splashScreenDlg = NULL;
}


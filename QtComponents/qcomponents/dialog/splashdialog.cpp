/* 
 * File:   splashdialog.cpp
 * Author: Rashad Amirjanov
 *
 * Created on April 29, 2009, 11:40 AM
 */

#include "splashdialog.h"

SplashScreenDialog *SplashScreenDialog::splashScreenDlg = NULL;

SplashScreenDialog::SplashScreenDialog() : QDialog(NULL) {
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

SplashScreenDialog::~SplashScreenDialog() {
    delete vLayoutText;
    delete lbText;
    delete lbImage;
    delete vMainLayout;
}

void SplashScreenDialog::openSplash() {
    show();
}

void SplashScreenDialog::closeSplash() {
    close();
}

void SplashScreenDialog::setPixmap(QPixmap px) {
    lbImage->setPixmap(px);
}

void SplashScreenDialog::openSplashDialog(QPixmap px) {
    splashScreenDlg = new SplashScreenDialog();
    splashScreenDlg->setPixmap(px);
    splashScreenDlg->openSplash();
}

void SplashScreenDialog::closeSplashDialog() {
    splashScreenDlg->closeSplash();
    delete splashScreenDlg;
    splashScreenDlg = NULL;
}


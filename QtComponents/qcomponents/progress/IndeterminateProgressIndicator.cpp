/*
 * File:   IndeterminateProgressIndicator.cpp
 * Author: Rashad Amirjanov
 *
 * Created on April 12, 2010, 11:53 AM
 */

#include "QIndeterminateProgressIndicator.h"

IndeterminateProgressIndicator::IndeterminateProgressIndicator(QWidget *parent) : QProgressBar(parent) {
    //    widget.setupUi(this);
    //    this->setWindowFlags(Qt::SplashScreen | Qt::WindowStaysOnTopHint);

    //    resize(412, 40);
    //    QHBoxLayout *horizontalLayout = new QHBoxLayout(this);

    //    QProgressBar *progressBar = new QProgressBar(this);
    //    progressBar->setObjectName(QString::fromUtf8("progressBar"));
    setMinimum(0);
    setMaximum(0);
    setValue(-1);
    setAlignment(Qt::AlignCenter);
    setInvertedAppearance(false);

    //    horizontalLayout->addWidget(progressBar);

    //    startTimer(100);
}

IndeterminateProgressIndicator::~IndeterminateProgressIndicator() {
}

//void ProgressDialog::timerEvent(QTimerEvent*) {
//    QMessageBox::information(this, "", "dss");
//    QCoreApplication::processEvents();
//    update();
//}
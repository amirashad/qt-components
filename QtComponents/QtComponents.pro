#********************************************
#       Author: Rashad Amirjanov
#       Created: 16.12.2013
#********************************************

TEMPLATE = lib
TARGET = libqcomps
INCLUDEPATH += .

QT = core gui widgets xml network

DEFINES += QCOMPS_DLL

TRANSLATIONS += qcomps_az.ts qcomps_ru.ts

HEADERS += \
    qcomponents/qcomps_global.h \
    qcomponents/sort/qNaturalSort.h \
    qcomponents/dialog/QClickableDialog.h \
    qcomponents/dialog/QClickableLabel.h \
    qcomponents/dialog/QSplashScreenDialog.h \
    qcomponents/dialog/QTouchDialog.h \
    qcomponents/dialog/QTouchScreenKeyboard.h \
    qcomponents/dialog/QTreeViewerButton.h \
    qcomponents/dialog/QTreeViewerMenu.h \
    qcomponents/http/QHttpRequester.h \
    qcomponents/progress/QCircularProgressIndicator.h \
    qcomponents/progress/QIndeterminateProgressIndicator.h

SOURCES += \
    qcomponents/dialog/QClickableDialog.cpp \
    qcomponents/dialog/QClickableLabel.cpp \
    qcomponents/dialog/QSplashScreenDialog.cpp \
    qcomponents/dialog/QTouchDialog.cpp \
    qcomponents/dialog/QTouchScreenKeyboard.cpp \
    qcomponents/dialog/QTreeViewerButton.cpp \
    qcomponents/dialog/QTreeViewerMenu.cpp \
    qcomponents/http/QHttpRequester.cpp \
    qcomponents/progress/QCircularProgressIndicator.cpp \
    qcomponents/progress/QIndeterminateProgressIndicator.cpp


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

HEADERS +=  qcomponents/qcomps_global.h \
            qcomponents/dialog/QClickableDialog.h \
            qcomponents/dialog/QClickableLabel.h \
            qcomponents/sort/qNaturalSort.h \
            qcomponents/dialog/QTouchDialog.h \
            qcomponents/dialog/QTreeViewerButton.h \
            qcomponents/http/QHttpRequester.h \
            qcomponents/progress/QCircularProgressIndicator.h \
            qcomponents/progress/QIndeterminateProgressIndicator.h \
            qcomponents/dialog/QSplashScreenDialog.h \
            qcomponents/dialog/QTreeViewerMenu.h \
            qcomponents/dialog/QTouchScreenKeyboard.h

SOURCES +=  qcomponents/dialog/QClickableDialog.cpp \
            qcomponents/dialog/QClickableLabel.cpp \
            qcomponents/progress/CircularProgressIndicator.cpp \
            qcomponents/progress/IndeterminateProgressIndicator.cpp \
            qcomponents/dialog/QTouchDialog.cpp \
            qcomponents/dialog/QTreeViewerButton.cpp \
            qcomponents/http/QHttpRequester.cpp \
            qcomponents/dialog/QTreeViewerMenu.cpp \
            qcomponents/dialog/QSplashScreenDialog.cpp \
            qcomponents/dialog/QTouchScreenKeyboard.cpp

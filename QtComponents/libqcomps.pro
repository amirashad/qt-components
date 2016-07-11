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

HEADERS += qcomponents/qcomps_global.h \
           qcomponents/dialog/QClickableDialog.h \
           qcomponents/dialog/QClickableLabel.h \
           qcomponents/dialog/splashdialog.h \
           qcomponents/dialog/touchdialog.h \
           qcomponents/dialog/TreeViewerButton.h \
           qcomponents/http/HttpRequester2.h \
           qcomponents/progress/CircularProgressIndicator.h \
           qcomponents/progress/IndeterminateProgressIndicator.h \
           qcomponents/sort/qNaturalSort.h \
           qcomponents/dialog/IPCtrl.h

SOURCES += \
           qcomponents/dialog/QClickableDialog.cpp \
           qcomponents/dialog/QClickableLabel.cpp \
           qcomponents/dialog/splashdialog.cpp \
           qcomponents/dialog/touchdialog.cpp \
           qcomponents/dialog/TreeViewerButton.cpp \
           qcomponents/http/HttpRequester2.cpp \
           qcomponents/progress/CircularProgressIndicator.cpp \
           qcomponents/progress/IndeterminateProgressIndicator.cpp \
           qcomponents/dialog/IPCtrl.cpp

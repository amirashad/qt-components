#********************************************
#       Author: Rashad Amirjanov
#       Created: 16.12.2013
#********************************************

TEMPLATE = lib
TARGET = libqcomps
INCLUDEPATH += .

DESTDIR = $$top_destdir

QT = core xml network widgets printsupport multimedia multimediawidgets
DEFINES += QCOMPS_DLL

RESOURCES += qcomponents/tableprinter/tableprinterresource.qrc
TRANSLATIONS += qcomps_az.ts qcomps_ru.ts

HEADERS += qcomponents/qcomps_global.h \
           qcomponents/dialog/QClickableDialog.h \
           qcomponents/dialog/QClickableLabel.h \
           qcomponents/dialog/splashdialog.h \
           qcomponents/dialog/touchdialog.h \
           qcomponents/dialog/TreeViewerButton.h \
           qcomponents/dialog/videoplayer.h \
           qcomponents/http/HttpRequester2.h \
           qcomponents/progress/CircularProgressIndicator.h \
           qcomponents/progress/IndeterminateProgressIndicator.h \
           qcomponents/singleapplication/qtlocalpeer.h \
           qcomponents/singleapplication/qtlockedfile.h \
           qcomponents/singleapplication/qtsingleapplication.h \
           qcomponents/singleapplication/qtsinglecoreapplication.h \
           qcomponents/sort/qNaturalSort.h \
           qcomponents/tableprinter/custommodel.h \
           qcomponents/tableprinter/tableprinterexample.h \
           qcomponents/tableprinter/tdpreviewdialog.h \
           qcomponents/singleapplication/qtlockedfile.cpp \
           qcomponents/singleapplication/qtlockedfile_win.cpp \
           qcomponents/singleapplication/qtlockedfile_unix.cpp \
           qcomponents/dialog/IPCtrl.h

FORMS += qcomponents/tableprinter/tableprinterexample.ui \
         qcomponents/tableprinter/tdpreviewdialog.ui \
         qcomponents/tableprinter/tdtableprinter.ui

SOURCES += \
           qcomponents/dialog/QClickableDialog.cpp \
           qcomponents/dialog/QClickableLabel.cpp \
           qcomponents/dialog/splashdialog.cpp \
           qcomponents/dialog/touchdialog.cpp \
           qcomponents/dialog/TreeViewerButton.cpp \
           qcomponents/dialog/videoplayer.cpp \
           qcomponents/http/HttpRequester2.cpp \
           qcomponents/progress/CircularProgressIndicator.cpp \
           qcomponents/progress/IndeterminateProgressIndicator.cpp \
           qcomponents/singleapplication/qtlocalpeer.cpp \
           qcomponents/singleapplication/qtlockedfile.cpp \
           qcomponents/singleapplication/qtlockedfile_unix.cpp \
           qcomponents/singleapplication/qtlockedfile_win.cpp \
           qcomponents/singleapplication/qtsingleapplication.cpp \
           qcomponents/singleapplication/qtsinglecoreapplication.cpp \
           qcomponents/tableprinter/custommodel.cpp \
           qcomponents/tableprinter/tableprinterexample.cpp \
           qcomponents/tableprinter/tdpreviewdialog.cpp \
           qcomponents/dialog/IPCtrl.cpp

TEMPLATE = app

#DESTDIR = $$top_destdir

QT = core network widgets

DESTDIR = $$top_destdir

INCLUDEPATH += . ../../QtComponents
LIBS += -L$$DESTDIR -lQtComponents

CONFIG += console

SOURCES += \
    main.cpp






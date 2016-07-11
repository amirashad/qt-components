TEMPLATE = app
#TARGET = SafeRegion

DESTDIR = $$top_destdir

QT = core xml network widgets printsupport #multimedia multimediawidgets axcontainer #webkitwidgets
DEFINES += _USE_MATH_DEFINES
#DEFINES += QT_MESSAGELOGCONTEXT

INCLUDEPATH += . ../libqcomps ../libSafeRegionCore ../libStyle
LIBS += -L$$DESTDIR -llibqcomps -llibSafeRegionCore -llibStyle

RESOURCES += resource/images.qrc
TRANSLATIONS += translation_az.ts translation_ru.ts

CONFIG+=console
win32:RC_FILE=$$top_srcdir/SafeRegion/resource/myapp.rc

HEADERS += src/initialization.h \
           src/mainwindow.h \
           src/SearchWidget.h \
           src/modules/address/AddressLayer.h \
           src/modules/address/AddressObject.h \
           src/modules/address/AddressSearchWidget.h \
           src/modules/alarm/Alarm.h \
           src/modules/alarm/AlarmSearchWidget.h \
           src/modules/distance/Distance.h \
           src/modules/distance/DistanceLayer.h \
           src/modules/searchobject/SearchObject.h \
           src/modules/searchobject/SearchObjectLayer.h \
           src/modules/searchobject/SelectMenu.h \
           src/modules/searchobject/SelectMenuTab.h \
           src/modules/user/LoginDialog.h \
           src/Logger.h

SOURCES += src/initialization.cpp \
           src/main.cpp \
           src/mainwindow.cpp \
           src/SearchWidget.cpp \
           src/modules/address/AddressLayer.cpp \
           src/modules/address/AddressSearchWidget.cpp \
           src/modules/alarm/AlarmSearchWidget.cpp \
           src/modules/distance/DistanceLayer.cpp \
           src/modules/searchobject/SearchObjectLayer.cpp \
           src/modules/searchobject/SelectMenu.cpp \
           src/modules/searchobject/SelectMenuTab.cpp \
           src/modules/user/LoginDialog.cpp \
           src/Logger.cpp




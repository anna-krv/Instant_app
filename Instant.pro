QT       += core gui sql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    MathHandler.cpp \
    game.cpp \
    main.cpp \
    widgets.cpp \
    window.cpp \
    windowStats.cpp

HEADERS += \
    game.h \
    mathHandler.h \
    widgets.h \
    window.h \
    windowStats.h

FORMS += \
    window.ui

TRANSLATIONS += \
    Instant_uk_UA.ts

QT_DEBUG_PLUGINS=1

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

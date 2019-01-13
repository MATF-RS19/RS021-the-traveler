#-------------------------------------------------
#
# Project created by QtCreator 2018-12-30T18:16:07
#
#-------------------------------------------------

QT       += core gui \
         multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TheTraveler
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
        mainmenuwindow.cpp \
    city.cpp \
    paris.cpp \
    game.cpp \
    tokyo.cpp \
    building.cpp \
    player.cpp \
    evil.cpp \
    settingsdialog.cpp \
    myqfile.cpp \
    paris_utility.cpp \
    howtoplaydialog.cpp \
    london.cpp \
    tee.cpp

HEADERS += \
        mainmenuwindow.h \
    city.h \
    paris.h \
    game.h \
    tokyo.h \
    building.h \
    player.h \
    evil.h \
    settingsdialog.h \
    myqfile.h \
    paris_utility.h \
    howtoplaydialog.h \
    london.h \
    tee.h

FORMS += \
        mainmenuwindow.ui \
    settingsdialog.ui \
    howtoplaydialog.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    images.qrc \
    song.qrc \
    buttons.qrc \
    json.qrc \
    text.qrc

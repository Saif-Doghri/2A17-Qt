QT       += core gui
QT       += sql
QT += printsupport serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11
CONFIG += sql
# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Agent.cpp \
    AgentController.cpp \
    arduino.cpp \
    main.cpp \
    mainwindow.cpp \
    profil.cpp \
    profilcontroller.cpp \
    qr.cpp

HEADERS += \
    Agent.h \
    AgentController.h \
    Config.h \
    arduino.h \
    mainwindow.h \
    profil.h \
    profilcontroller.h \
    qr.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../wamp64/bin/mysql/mysql5.7.31/lib/ -llibmysql
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../wamp64/bin/mysql/mysql5.7.31/lib/ -llibmysqld
else:unix: LIBS += -L$$PWD/../../../../wamp64/bin/mysql/mysql5.7.31/lib/ -llibmysql

INCLUDEPATH += $$PWD/../../../../wamp64/bin/mysql/mysql5.7.31/include
DEPENDPATH += $$PWD/../../../../wamp64/bin/mysql/mysql5.7.31/include

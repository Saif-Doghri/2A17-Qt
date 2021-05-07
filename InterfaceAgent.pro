QT       += core gui
QT       += sql
QT += printsupport serialport network multimedia charts

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
    cellule.cpp \
    cellulecontroller.cpp \
    citoyen.cpp \
    document.cpp \
    dossier.cpp \
    exportexcelobjet.cpp \
    main.cpp \
    mainwindow.cpp \
    parking.cpp \
    parkingcontroller.cpp \
    prisonnier.cpp \
    prisonniercontroller.cpp \
    profil.cpp \
    profilcontroller.cpp \
    qr.cpp \
    reclamation.cpp \
    smtp.cpp \
    vehiculecontroller.cpp \
    vehicules.cpp

HEADERS += \
    Agent.h \
    AgentController.h \
    Config.h \
    arduino.h \
    cellule.h \
    cellulecontroller.h \
    citoyen.h \
    document.h \
    dossier.h \
    exportexcelobjet.h \
    mainwindow.h \
    parking.h \
    parkingcontroller.h \
    prisonnier.h \
    prisonniercontroller.h \
    profil.h \
    profilcontroller.h \
    qr.h \
    reclamation.h \
    smtp.h \
    vehiculecontroller.h \
    vehicules.h

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

RESOURCES += \
    multimedia.qrc

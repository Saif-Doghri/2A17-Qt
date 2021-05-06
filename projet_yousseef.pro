QT       += core gui
QT       += core gui charts
QT +=sql network


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    cellule.cpp \
    celluleController.cpp \
    main.cpp \
    mainwindow.cpp \
    prisonnier.cpp \
    prisonnierController.cpp \
    smtp.cpp

HEADERS += \
    cellule.h \
    celluleController.h \
    configg.h \
    mainwindow.h \
    prisonnier.h \
    prisonnierController.h \
    smtp.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

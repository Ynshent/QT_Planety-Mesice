QT       += core gui
QT       += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Planety_Mesice
TEMPLATE = app

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    dialogceres.cpp \
    dialogeris.cpp \
    dialoghaumea.cpp \
    dialogjupiter.cpp \
    dialogmakemake.cpp \
    dialogmars.cpp \
    dialogmerkur.cpp \
    dialogmesice.cpp \
    dialogmesice_eris.cpp \
    dialogmesice_haumea.cpp \
    dialogmesice_jupiter.cpp \
    dialogmesice_makemake.cpp \
    dialogmesice_mars.cpp \
    dialogmesice_neptun.cpp \
    dialogmesice_pluto.cpp \
    dialogmesice_saturn.cpp \
    dialogmesice_uran.cpp \
    dialogmesice_zeme.cpp \
    dialogneptun.cpp \
    dialogplanety.cpp \
    dialogpluto.cpp \
    dialogsaturn.cpp \
    dialoguran.cpp \
    dialogvenuse.cpp \
    dialogvsechnymesice.cpp \
    dialogvsechnyplanety.cpp \
    dialogzeme.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    dialogceres.h \
    dialogeris.h \
    dialoghaumea.h \
    dialogjupiter.h \
    dialogmakemake.h \
    dialogmars.h \
    dialogmerkur.h \
    dialogmesice.h \
    dialogmesice_eris.h \
    dialogmesice_haumea.h \
    dialogmesice_jupiter.h \
    dialogmesice_makemake.h \
    dialogmesice_mars.h \
    dialogmesice_neptun.h \
    dialogmesice_pluto.h \
    dialogmesice_saturn.h \
    dialogmesice_uran.h \
    dialogmesice_zeme.h \
    dialogneptun.h \
    dialogplanety.h \
    dialogpluto.h \
    dialogsaturn.h \
    dialoguran.h \
    dialogvenuse.h \
    dialogvsechnymesice.h \
    dialogvsechnyplanety.h \
    dialogzeme.h \
    mainwindow.h

FORMS += \
    dialogceres.ui \
    dialogeris.ui \
    dialoghaumea.ui \
    dialogjupiter.ui \
    dialogmakemake.ui \
    dialogmars.ui \
    dialogmerkur.ui \
    dialogmesice.ui \
    dialogmesice_eris.ui \
    dialogmesice_haumea.ui \
    dialogmesice_jupiter.ui \
    dialogmesice_makemake.ui \
    dialogmesice_mars.ui \
    dialogmesice_neptun.ui \
    dialogmesice_pluto.ui \
    dialogmesice_saturn.ui \
    dialogmesice_uran.ui \
    dialogmesice_zeme.ui \
    dialogneptun.ui \
    dialogplanety.ui \
    dialogpluto.ui \
    dialogsaturn.ui \
    dialoguran.ui \
    dialogvenuse.ui \
    dialogvsechnymesice.ui \
    dialogvsechnyplanety.ui \
    dialogzeme.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

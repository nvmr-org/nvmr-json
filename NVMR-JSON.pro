#-------------------------------------------------
#
# Project created by QtCreator 2020-09-07T18:51:42
#
#-------------------------------------------------

QT       -= gui

TARGET = nvmr-json
TEMPLATE = lib

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += create_pc create_prl no_install_prl


SOURCES += \
    videosendermessage.cpp \
    videosenderconfiguration.cpp \
    videosettings.cpp \
    networksettings.cpp

HEADERS += \
    videosendermessage.h \
    videosenderconfiguration.h \
    videosettings.h \
    networksettings.h


unix {
    if( isEmpty(LIBRARY_PATH) ){
        target.path = /usr/lib
    }else{
        target.path = /usr/lib/$$LIBRARY_PATH/
    }
    INSTALLS += target 

    headers_target.files = $$HEADERS
    headers_target.path = /usr/include/nvmr-json
    INSTALLS += headers_target

    QMAKE_PKGCONFIG_INCDIR=/usr/include/nvmr-json
    QMAKE_PKGCONFIG_FILE=nvmr-json
    QMAKE_PKGCONFIG_DESTDIR=pkgconfig
}


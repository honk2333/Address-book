#-------------------------------------------------
#
# Project created by QtCreator 2018-12-21T22:06:33
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MyAddressBook
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
        widget.cpp \
    adddatadialog.cpp \
    displaydialog.cpp \
    searchdialog.cpp \
    changedialog.cpp \
    person.cpp \
    groupdialog.cpp \
    infodialog.cpp

HEADERS += \
        widget.h \
    adddatadialog.h \
    displaydialog.h \
    searchdialog.h \
    changedialog.h \
    person.h \
    groupdialog.h \
    infodialog.h

FORMS += \
        widget.ui \
    adddatadialog.ui \
    displaydialog.ui \
    searchdialog.ui \
    changedialog.ui \
    groupdialog.ui \
    infodialog.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc

DISTFILES +=

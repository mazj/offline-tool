#-------------------------------------------------
#
# Project created by QtCreator 2015-05-08T23:23:43
#
#-------------------------------------------------

QT       += core gui xmlpatterns
CONFIG += static c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CronosOffline
TEMPLATE = app

SOURCES += main.cpp\
        mainwindow.cpp \
    generator/exportcronossitexmlgenerator.cpp \
    parser/importxmlvalidator.cpp \
    parser/importxmlfilevalidationmessagehandler.cpp \
    parser/importfilexmlparser.cpp \
    dialog/aboutdialog.cpp \
    dialog/selecttimezonedialog.cpp \
    utils.cpp \
    widget/comboboxwithcheckboxes.cpp \
    dialog/selectsitedialog.cpp \
    dialog/logindialog.cpp \
    widget/table/proxymodelwithheadermodels.cpp \
    widget/table/hierarchicalheaderview.cpp

HEADERS  += mainwindow.h \
    entities.h \
    generator/exportcronossitexmlgenerator.h \
    parser/importxmlvalidator.h \
    parser/importxmlfilevalidationmessagehandler.h \
    parser/importfilexmlparser.h \
    dialog/aboutdialog.h \
    dialog/selecttimezonedialog.h \
    utils.h \
    widget/comboboxwithcheckboxes.h \
    dialog/selectsitedialog.h \
    dialog/logindialog.h \
    widget/table/proxymodelwithheadermodels.h \
    widget/table/hierarchicalheaderview.h

FORMS    += mainwindow.ui \
    dialog/aboutdialog.ui \
    dialog/selecttimezonedialog.ui \
    dialog/selectsitedialog.ui \
    dialog/logindialog.ui

DISTFILES +=

RESOURCES += \
    resources.qrc

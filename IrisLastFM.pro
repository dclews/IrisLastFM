#-------------------------------------------------
#
# Project created by QtCreator 2014-03-02T03:51:34
#
#-------------------------------------------------

include(/usr/local/share/iris/iris_plugin.pri)

TARGET = $$qtLibraryTarget(xclueless.iris.LastFM)

QT       -= gui
QT       += network xml

LIBS += -llastfm

SOURCES += LFMPlugin.cpp \
    LFMCommandFactory.cpp \
    LFMCommand.cpp
HEADERS += LFMPlugin.hpp \
    LFMCommandFactory.hpp \
    LFMCommand.hpp


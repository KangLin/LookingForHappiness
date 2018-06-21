#-------------------------------------------------
#
# Project created by QtCreator 2018-06-14T10:58:13
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = LookingForHappiness
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


SOURCES += \
        main.cpp \
        mainwindow.cpp \
        maze.cpp \
        rectangularmaze.cpp \
        circularmaze.cpp \
        circularhexagonmaze.cpp \
        hexagonalmaze.cpp \
        honeycombmaze.cpp \
        minimumspanningtreealgorithm.cpp \
        kruskal.cpp \
        depthfirstsearch.cpp \
        breadthfirstsearch.cpp \
        cellborder.cpp \ 
    Draw.cpp \
    FrmMaze.cpp \
    QtDraw.cpp

HEADERS += \
        mainwindow.h \
        maze.h \
        rectangularmaze.h \
        circularmaze.h \
        circularhexagonmaze.h \
        hexagonalmaze.h \
        honeycombmaze.h \
        minimumspanningtreealgorithm.h \
        kruskal.h \
        depthfirstsearch.h \
        breadthfirstsearch.h \
        cellborder.h \ 
    Draw.h \
    FrmMaze.h \
    QtDraw.h

FORMS += \
        mainwindow.ui \
    FrmMaze.ui

CONFIG += mobility c++11
MOBILITY = 

RESOURCES += \
    Resource/Resource.qrc

OTHER_FILES += tag.sh \
    .travis.yml \
    appveyor.yml \
    .gitignore \
    ci/* \
    Install/Install.nsi


QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17 console

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    AnyObject.cpp \
    Ball.cpp \
    Board.cpp \
    Brick.cpp \
    DynamicObject.cpp \
    Game.cpp \
    MyWidgetDraw.cpp \
    MyWidgets.cpp \
    NewGame.cpp \
    Room.cpp \
    StaticObject.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    AnyObject.h \
    Ball.h \
    Board.h \
    Box2D/box2d.h \
    Brick.h \
    DynamicObject.h \
    Game.h \
    MyWidgetDraw.h \
    MyWidgets.h \
    NewGame.h \
    Room.h \
    StaticObject.h \
    mainwindow.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

win32: LIBS += -L$$PWD/./ -lBox2D

INCLUDEPATH += $$PWD/.
DEPENDPATH += $$PWD/.

win32:!win32-g++: PRE_TARGETDEPS += $$PWD/./Box2D.lib
else:win32-g++: PRE_TARGETDEPS += $$PWD/./libBox2D.a

RESOURCES += \
     Resource.qrc

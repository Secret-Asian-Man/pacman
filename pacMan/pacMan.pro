TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    grid.cpp \
    object.cpp \
    coords.cpp \
    random.cpp \
    pacman.cpp \
    ghost.cpp \
    walls.cpp \
    boarders.cpp \
    warp.cpp \
    pellet.cpp \
    powerpellet.cpp \
    door.cpp \
    ghostchild1.cpp \
    ghostchild2.cpp \
    game.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    grid.h \
    object.h \
    constants.h \
    coords.h \
    random.h \
    pacman.h \
    ghost.h \
    walls.h \
    boarders.h \
    warp.h \
    pellet.h \
    powerpellet.h \
    door.h \
    ghostchild1.h \
    ghostchild2.h \
    game.h

INCLUDEPATH += "C:/sfml-2.2/include/"

LIBS += -L"C:/sfml-2.2/lib/"

CONFIG(debug, debug|release): LIBS += -lsfml-graphics-d -lsfml-window-d -lsfml-audio-d -lsfml-network-d -lsfml-system-d
CONFIG(release, debug|release): LIBS += -lsfml-graphics -lsfml-window -lsfml-audio -lsfml-network -lsfml-system

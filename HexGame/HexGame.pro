QT += widgets

CONFIG += c++14

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        button.cpp \
        game.cpp \
        hex.cpp \
        hexboard.cpp \
        main.cpp

HEADERS += \
    button.h \
    game.h \
    hex.h \
    hexboard.h

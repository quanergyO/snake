QT += core gui widgets

CONFIG += c++17

# Добавляем конфигурацию для Desktop (x86-darwin-generic-mach_o-64bit)
CONFIG += x86_64

# Путь к библиотекам
QMAKE_MACOSX_DEPLOYMENT_TARGET = 10.15

# Сборка для Desktop
CONFIG += app_bundle

# Пути к файлам
SOURCES += \
    ../../../brick_game/snake/Model.cpp \
    ../../../brick_game/snake/Snake.cpp \
    ../../../controllers/snake/Controller.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    ../../../brick_game/snake/Model.h \
    ../../../brick_game/snake/Snake.h \
    ../../../controllers/snake/Controller.h \
    mainwindow.h \
    ../../../brick_game/lib/defines.h

FORMS += \
    mainwindow.ui
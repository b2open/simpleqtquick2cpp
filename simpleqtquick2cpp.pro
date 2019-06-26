QT += quick quickcontrols2
CONFIG += c++11

SOURCES += \
        main.cpp \
        myclass.cpp

RESOURCES += qml.qrc

unix: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    myclass.h

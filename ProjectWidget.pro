QT       += core gui
QT += sql
QT += core gui widgets sql multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    calculatorwindow.cpp \
    logindialog.cpp \
    main.cpp \
    playerwindow.cpp \
    projectwidget.cpp \
    toolform.cpp \
    database.cpp

HEADERS += \
    calculatorwindow.h \
    logindialog.h \
    playerwindow.h \
    projectwidget.h \
    toolform.h \
    database.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

FORMS += \
    calculatorwindow.ui \
    logindialog.ui \
    playerwindow.ui \
    toolform.ui

RESOURCES += \
    pic.qrc

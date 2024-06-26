QT += gui core network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17 app_bundle

ICON = resources/AppIcon.png

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    adminwindow.cpp \
    backendclient.cpp \
    emailsender.cpp \
    hash.cpp \
    basketwindow.cpp \
    bookingwindow.cpp \
    main.cpp \
    mainwindow.cpp \
    menuwindow.cpp \
    entering_window.cpp \
    profilewindow.cpp \
    register_window.cpp

HEADERS += \
    adminwindow.h \
    backendclient.h \
    emailsender.h \
    hash.h \
    basketwindow.h \
    bookingwindow.h \
    mainwindow.h \
    menuwindow.h \
    entering_window.h \
    message.h \
    profilewindow.h \
    register_window.h

FORMS += \
    adminwindow.ui \
    basketwindow.ui \
    bookingwindow.ui \
    mainwindow.ui \
    menuwindow.ui \
    entering_window.ui \
    profilewindow.ui \
    register_window.ui


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc

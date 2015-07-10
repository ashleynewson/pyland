CONFIG       += release

greaterThan(QT_MAJOR_VERSION, 4) {
    QT += widgets
}

HEADERS       = mainwindow.h \
                api_list.h

SOURCES       = mainwindow.cpp \

RESOURCES     = application.qrc \

LIBS         += -lqscintilla2 -lSDL2 -lGL

ICON = images/app.icns
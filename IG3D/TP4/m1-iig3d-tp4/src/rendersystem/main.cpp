
#include <QApplication>
#include "mainwindow.h"

using namespace gui;

/**
  * Main function.
  * just creates GUI main window and launch interaction loop.
  */
int main ( int argc, char *argv[] ) {
    QApplication app ( argc, argv );
    MainWindow * mw = new MainWindow();
    mw->show();
    int result = app.exec();
    delete mw;
    return result;
}


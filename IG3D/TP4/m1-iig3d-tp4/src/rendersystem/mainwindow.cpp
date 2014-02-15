
#include "mainwindow.h"

#include <QtGui>

#include <QGLFormat>
#include <openglwidget.h>

#include <QTextStream>
#include <QCloseEvent>
#include <QFileDialog>

#include <iostream>

namespace gui {

MainWindow::MainWindow() : curFile_(""), fileMenu_(NULL), renderMenu_(NULL) {
    std::cerr << std::endl << " -------- IG3D Renderer 2012 -------- " << std::endl<< std::endl;

    /* Create main windows actions, menu and status bar */
    createActions();
    createMenus();
    createStatusBar();

    /* Get persistent settings from system */
    readSettings();

    /* Create OpenGL part of the main window*/
    /* Request OpenGL 3.2 context with standard settings */
    QGLFormat fmt;
    fmt.setDoubleBuffer ( true );
    fmt.setDirectRendering ( true );
    fmt.setRgba ( true );
    fmt.setStencil ( true );
    fmt.setDepth ( true );
    fmt.setAlpha ( true );
#if (QT_VERSION >= 0x40700)
    fmt.setVersion ( 3,2 );
    fmt.setProfile ( QGLFormat::CoreProfile  );
#endif
    QGLFormat::setDefaultFormat ( fmt );
    /* Create OpenGL widget */
    openGLWidget_ = new OpenGLWidget(this);
    /* Verify OpenGL widget */
#if (QT_VERSION >= 0x40700)
    if ( QGLFormat::openGLVersionFlags() & QGLFormat::OpenGL_Version_3_2 ) {
#else
    if ( QGLFormat::openGLVersionFlags() & QGLFormat::OpenGL_Version_3_0 ) {
#endif
        std::cerr << "Contexte OpenGL OK" << std::endl;
    } else {
        std::cerr << "Problème contexte OpenGL" << std::endl;
        QCoreApplication::instance()->quit();
    }
    /* integrate OpenGL widget in the main window */
    setCentralWidget ( openGLWidget_ );
    connect ( openGLWidget_, SIGNAL ( fpsChanged ( const QString & ) ), this, SLOT ( statusChanged ( const QString & ) ) );

}


MainWindow::~MainWindow() {
    delete openGLWidget_;
    delete fileMenu_;
    delete renderMenu_;
}


void MainWindow::closeEvent ( QCloseEvent *event ) {
        writeSettings();
        event->accept();
}

void MainWindow::open() {
    QString fileName = QFileDialog::getOpenFileName ( this );
    if ( !fileName.isEmpty() )
        loadFile ( fileName );
}

void MainWindow::createActions() {
    openAct_ = new QAction ( QIcon ( ":/fileopen.xpm" ), tr ( "&Open..." ), this );
    openAct_->setShortcut ( tr ( "Ctrl+O" ) );
    openAct_->setStatusTip ( tr ( "Open an existing file" ) );
    connect ( openAct_, SIGNAL ( triggered() ), this, SLOT ( open() ) );

    exitAct_ = new QAction ( tr ( "E&xit" ), this );
    exitAct_->setShortcut ( tr ( "Ctrl+Q" ) );
    exitAct_->setStatusTip ( tr ( "Exit the application" ) );
    connect ( exitAct_, SIGNAL ( triggered() ), this, SLOT ( close() ) );

    checkResetCamera_ = new QAction ( tr ( "&Reset Camera" ), this );
    checkResetCamera_->setShortcut ( tr ( "Ctrl+R" ) );
    checkResetCamera_->setStatusTip ( tr( "Reset Camera attributes" ) );
    connect ( checkResetCamera_, SIGNAL ( triggered() ), this, SLOT ( resetCamera() ) );

    checkReloadShaders_ = new QAction ( tr ( "Reload &Shaders" ), this );
    checkReloadShaders_->setShortcut ( tr ( "Ctrl+S" ) );
    checkReloadShaders_->setStatusTip ( tr ( "Reload Shaders" ) );
    connect ( checkReloadShaders_, SIGNAL ( triggered() ), this, SLOT ( reloadShaders() ) );

}

void MainWindow::createMenus() {
    fileMenu_ = menuBar()->addMenu ( tr ( "&File" ) );
    fileMenu_->addAction ( openAct_ );
    fileMenu_->addSeparator();
    fileMenu_->addAction ( exitAct_ );

    renderMenu_ = menuBar()->addMenu ( tr ( "&Rendering" ) );
    renderMenu_->addAction (checkResetCamera_ );
    renderMenu_->addSeparator();
    renderMenu_->addAction ( checkReloadShaders_ );



}

void MainWindow::createStatusBar() {
    statusBar()->showMessage ( tr ( "Ready" ) );
}

void MainWindow::readSettings() {
    QSettings settings ( "MinimalRenderer", "MinimalRenderer" );
    QPoint pos = settings.value ( "pos", QPoint ( 200, 200 ) ).toPoint();
    QSize size = settings.value ( "size", QSize ( 800, 690 ) ).toSize();
    resize ( size );
    move ( pos );
}

void MainWindow::writeSettings() {
    QSettings settings ( "MinimalRenderer", "IG3D Rendering System" );
    settings.setValue ( "pos", pos() );
    settings.setValue ( "size", size() );
}

void MainWindow::loadFile ( const QString &fileName ) {
    QFile file ( fileName );
    QString reason;
    if ( !file.open ( QFile::ReadOnly | QFile::Text ) ) {
        QMessageBox::warning ( this, tr ( "Application" ),
                              tr ( "Cannot read file %1:\n%2." )
                              .arg ( fileName )
                              .arg ( file.errorString() ) );
        return;
    }

    QApplication::setOverrideCursor ( Qt::WaitCursor );


    //bool succeed = loadScene(fileName, reason);

    bool succeed = true;

    QApplication::restoreOverrideCursor();

    if ( succeed ) {
        reset();
        setCurrentFile ( fileName );
        statusBar()->showMessage ( tr ( "File loaded" ), 2000 );
        openGLWidget_->updateGL();
    } else {
        QMessageBox::warning ( this, tr ( "Application" ), tr ( "Cannot read file %1\n%2" ) .arg ( fileName ) );
        statusBar()->showMessage ( tr ( "Error loading file" ), 2000 );
    }
}

void MainWindow::setCurrentFile ( const QString &fileName ) {
    curFile_ = fileName;

    QString shownName;
    if ( curFile_.isEmpty() )
        shownName = "untitled.obj";
    else
        shownName = strippedName ( curFile_ );
    /*save the name of the file without extension*/
    mNameFile_ = shownName;
    mNameFile_.truncate(shownName.indexOf(".", 0));
    setWindowTitle ( tr ( "%1[*] - %2" ).arg ( shownName ).arg ( tr ( "Application" ) ) );
}

QString MainWindow::strippedName ( const QString &fullFileName ) {
    return QFileInfo ( fullFileName ).fileName();
}

void MainWindow::reset(){
    resetCamera();
}

void MainWindow::statusChanged ( const QString &message ) {
    statusBar()->showMessage ( message );
}

void MainWindow::reloadShaders(){
    openGLWidget_->reloadShaders();
    openGLWidget_->updateGL();
}

void MainWindow::resetCamera(){
    openGLWidget_->resetView();
    openGLWidget_->updateGL();
}


} // namespace gui

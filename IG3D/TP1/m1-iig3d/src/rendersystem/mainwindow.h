
#ifndef VORTEXRENDERER_H
#define VORTEXRENDERER_H

#include <QMainWindow>
#include <QCloseEvent>
#include <QWidgetAction>
#include <QDoubleSpinBox>
#include <QHBoxLayout>
#include <QLabel>

#include "openglwidget.h"


/** @defgroup InterfaceSystem Qt-OpenGL graphical interface
 *  Graphical User Interface of a minimal OpenGL Renderer
 * @author Mathias Paulin <Mathias.Paulin@irit.fr>
 *  @{
 */

/**
  * @ingroup InterfaceSystem
  * Graphical User Interface classes and functions
  */
namespace gui {

/**
  * @ingroup InterfaceSystem
  * The main window of the application.
  * The main window contains a menu bar, a status bar and a central region where openGL rendering will be done.
  * This class manage the general interaction between user and application.
  */
class MainWindow: public QMainWindow {
    Q_OBJECT

public:
    MainWindow();
    ~MainWindow();

protected:
    void closeEvent ( QCloseEvent *event );

private slots:
    void open();
    void statusChanged ( const QString &message );

    void resetCamera();
    void reloadShaders();


private:

    void createActions();
    void createMenus();
    void createStatusBar();
    void readSettings();
    void writeSettings();
    void loadFile ( const QString &fileName );
    void setCurrentFile ( const QString &fileName );
    QString strippedName ( const QString &fullFileName );
    void reset();
    QSize getSize();

    OpenGLWidget *openGLWidget_;
    QString curFile_;

    QMenu *fileMenu_;
    QMenu *renderMenu_;
    QAction *openAct_;
    QAction *exitAct_;
    QAction *checkResetCamera_;
    QAction *checkReloadShaders_;

    QString mNameFile_;


};


} // namespace gui

/** @} */ // end of InterfaceSystem group


#endif


#ifndef OPENGLWIDGET_H
#define OPENGLWIDGET_H

#include "opengl.h"
#include "renderer.h"


#include <QGLWidget>
#include <QImage>

namespace gui {

/** @ingroup InterfaceSystem
 *  Qt-OpenGL interface component.
 *  This specialized QGLWidget manage the OpenGL rendering and its interaction with the windowing system.
 */
class OpenGLWidget : public QGLWidget {
    Q_OBJECT
public:
    OpenGLWidget ( QWidget *parent );

    virtual ~OpenGLWidget();

    void clear();

    void resetView();
    void reloadShaders();


signals:
    void fpsChanged ( const QString & );

public slots:


protected:
    void initializeGL();
    void resizeGL ( int w, int h );
    void paintGL();
    virtual void mousePressEvent ( QMouseEvent * e );
    virtual void mouseReleaseEvent ( QMouseEvent * e );
    virtual void mouseMoveEvent ( QMouseEvent * e );
    virtual void wheelEvent ( QWheelEvent * e );
    virtual void keyPressEvent ( QKeyEvent * e );

private:
    int width_;
    int height_;

    rendersystem::Renderer renderer_;


};

} // namespace gui
#endif

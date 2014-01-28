
#include "openglwidget.h"

#include "timer.h"

#include <QWheelEvent>
#include <QApplication>

#include <iostream>

namespace gui {
//-----------------------------------
void cerrInfoGL(OpenGLWidget *w) {
    const GLubyte *str;
    glAssert( str = glGetString(GL_RENDERER) );
    std::cerr << "Renderer : " << str << std::endl;
    glAssert( str = glGetString(GL_VENDOR) );
    std::cerr << "Vendor : " << str << std::endl;
    glAssert( str = glGetString(GL_VERSION) );
    std::cerr << "Version : " << str << std::endl;
    glAssert( str = glGetString(GL_SHADING_LANGUAGE_VERSION) );
    std::cerr << "GLSL Version : " << str << std::endl;
}

#ifdef __APPLE__
//-----------------------------------
// To get OpenGL 3.2 core on Mac Os X lion with QT 4.7.4
void* select_3_2_mac_visual(GDHandle handle);

class Core3_2_context : public QGLContext
{
public:
    Core3_2_context(const QGLFormat& format, QPaintDevice* device) : QGLContext(format,device) {}
    Core3_2_context(const QGLFormat& format) : QGLContext(format) {}
    virtual void* chooseMacVisual(GDHandle handle)
    {
        return select_3_2_mac_visual(handle);
    }
};


OpenGLWidget::OpenGLWidget ( QWidget *parent) : QGLWidget (new Core3_2_context(QGLFormat::defaultFormat()) ) {
    setFocusPolicy ( Qt::StrongFocus );
    makeCurrent();
    cerrInfoGL(this);
}

#else

OpenGLWidget::OpenGLWidget ( QWidget *parent ) : QGLWidget ( parent ) {
    setFocusPolicy ( Qt::StrongFocus );
    makeCurrent();
    cerrInfoGL(this);
}

#endif

OpenGLWidget::~OpenGLWidget() {

}

void OpenGLWidget::clear() {
    updateGL();
}

void OpenGLWidget::initializeGL() {
    renderer_.initRessources();

}

void OpenGLWidget::resizeGL ( int w, int h ) {
    width_=w;
    height_=h;
    renderer_.setViewport(width_, height_);

}

void OpenGLWidget::paintGL() {
#ifdef __APPLE__
    // strange QT - OpenGL error on MacOsX
    glGetError();
#endif

    static float time = 0.0;
    static int frames = 0;

    rendersystem::Timer t;
    t.start();

    renderer_.render(glm::mat4x4(1.0), glm::mat4x4(1.0));
    renderer_.renderDebug(glm::mat4x4(1.0), glm::mat4x4(1.0));
    // Draw here

    glFinish();
    t.stop();
    time += t.value();
    if ( frames % 25 == 0 ) {
        float fps = ( ( float ) frames ) / time;
        QString thetext = QString ( "FPS : %1" ).arg ( fps );
        emit fpsChanged ( thetext );
        time = 0.0;
        frames = 0;
    }
    frames += 1;
}


void OpenGLWidget::keyPressEvent ( QKeyEvent * e ) {

    switch ( e->key() ) {
        case Qt::Key_Escape :
        QCoreApplication::instance()->quit();
        break;
        default:
        renderer_.handleKeyEvent( e->text().toAscii()[0] );
    }
    updateGL();
}

void OpenGLWidget::wheelEvent ( QWheelEvent * e ) {

    updateGL();
}

void OpenGLWidget::mouseMoveEvent ( QMouseEvent * e ) {
    rendersystem::MouseEvent event;

    // dont need to know which button
    event.button=rendersystem::MouseEvent::MOVE;

    event.modifiers=rendersystem::MouseEvent::NONE;
    if ( e->modifiers() & Qt::ShiftModifier )
        event.modifiers|=rendersystem::MouseEvent::SHIFT;
    if ( e->modifiers() & Qt::ControlModifier )
        event.modifiers|=rendersystem::MouseEvent::CONTROL;
    if ( e->modifiers() & Qt::AltModifier )
        event.modifiers|=rendersystem::MouseEvent::ALT;

    event.click=false;
    event.x = e->x();
    event.y = e->y();
    event.delta = 0;

    renderer_.handleMouseEvent ( event );
    updateGL();
}

void OpenGLWidget::mouseReleaseEvent ( QMouseEvent *e ) {

    rendersystem::MouseEvent event;

    if ( e->button() &Qt::LeftButton )
        event.button=rendersystem::MouseEvent::LEFT;
    if ( e->button() &Qt::MidButton )
        event.button=rendersystem::MouseEvent::MIDDLE;
    if ( e->button() &Qt::RightButton )
        event.button=rendersystem::MouseEvent::RIGHT;

    event.modifiers=rendersystem::MouseEvent::NONE;
    if ( e->modifiers() & Qt::ShiftModifier )
        event.modifiers|=rendersystem::MouseEvent::SHIFT;
    if ( e->modifiers() & Qt::ControlModifier )
        event.modifiers|=rendersystem::MouseEvent::CONTROL;
    if ( e->modifiers() & Qt::AltModifier )
        event.modifiers|=rendersystem::MouseEvent::ALT;

#ifdef __APPLE__
    if ( (e->modifiers() & Qt::ShiftModifier) && (e->button() &Qt::LeftButton) )
        event.button=rendersystem::MouseEvent::MIDDLE;
    if ( (e->modifiers() & Qt::ControlModifier) && (e->button() &Qt::LeftButton) )
        event.button=rendersystem::MouseEvent::RIGHT;
#endif

    event.click=false;
    event.x = e->x();
    event.y = e->y();
    event.delta = 0;

    renderer_.handleMouseEvent ( event );
    updateGL();
}

void OpenGLWidget::mousePressEvent ( QMouseEvent * e ) {
    rendersystem::MouseEvent event;



    if ( e->button() &Qt::LeftButton )
        event.button=rendersystem::MouseEvent::LEFT;
    if ( e->button() &Qt::MidButton )
        event.button=rendersystem::MouseEvent::MIDDLE;
    if ( e->button() &Qt::RightButton )
        event.button=rendersystem::MouseEvent::RIGHT;

    event.modifiers=rendersystem::MouseEvent::NONE;
    if ( e->modifiers() & Qt::ShiftModifier )
        event.modifiers|=rendersystem::MouseEvent::SHIFT;
    if ( e->modifiers() & Qt::ControlModifier )
        event.modifiers|=rendersystem::MouseEvent::CONTROL;
    if ( e->modifiers() & Qt::AltModifier )
        event.modifiers|=rendersystem::MouseEvent::ALT;

#ifdef __APPLE__
    if ( (e->modifiers() & Qt::ShiftModifier) && (e->button() &Qt::LeftButton) )
        event.button=rendersystem::MouseEvent::MIDDLE;
    if ( (e->modifiers() & Qt::ControlModifier) && (e->button() &Qt::LeftButton) )
        event.button=rendersystem::MouseEvent::RIGHT;
#endif

    event.click=true;
    event.x = e->x();
    event.y = e->y();
    event.delta = 0;

    renderer_.handleMouseEvent( event );
    updateGL();
}


void OpenGLWidget::resetView(){
    renderer_.initView();
}

void OpenGLWidget::reloadShaders(){
    renderer_.initShaders();
}


} // namespace gui

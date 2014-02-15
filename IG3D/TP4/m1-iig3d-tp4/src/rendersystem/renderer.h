
#ifndef RENDERER_H
#define RENDERER_H
#include "opengl.h"

#include <vector>

#include "glmesh.h"
#include "glentity.h"
#include "gllight.h"





/** @defgroup RenderSystem Simple OpenGL Rendering system
 *  Simple OpenGL 3.2 core renderer.
 * @author Mathias Paulin <Mathias.Paulin@irit.fr>
 *  @{
 */

/**
  * Render system classes and functions.
  */
namespace rendersystem {

/**
  * @ingroup RenderSystem
  * Mouse event structure.
  * Mouse interaction events as the renderer will understand them.
  * It is the role of the graphical user interface to translate native mouse
  * event (Qt, WIN32, X11, ...) to this representation.
  */
struct MouseEvent {
    enum Modifiers {NONE = 0x00, CONTROL = 0x01, SHIFT = 0x02, ALT = 0x04};
    enum Buttons {LEFT = 0x01, MIDDLE = 0x02, RIGHT = 0x04, WHEEL = 0x08, MOVE = 0x10};
    int button;
    bool click; // true -> click, false -> release
    int modifiers;
    int x;
    int y;
    int delta;
};



/**
  * @ingroup RenderSystem
  * OpenGL renderer.
  * Manages all of the OpenGL operation to render a scene.
  */
class Renderer {
public:
    /**
     * Default constructor
     */
    Renderer() : program_(0), viewMatrix_(1.0f){}
    /**
     * Destructor
     */
    virtual ~Renderer() {}

    /**
     * Viewport management.
     */
    virtual void setViewport(int width, int height);

    /**
     * Render the scene.
     */
    virtual void render(const glm::mat4x4 &modelViewMatrix, const glm::mat4x4 &projectionMatrix);
    virtual void renderDebug(const glm::mat4x4 &modelViewMatrix, const glm::mat4x4 &projectionMatrix);
    /**
     * Handle mouse event given by the vortexEngine
     * @return 1 if event is understood and fully managed. 0 otherwise.
     */
    virtual int handleMouseEvent(const MouseEvent & event);

    /**
     * Handle key event given by the vortexEngine
     * @return 1 if event is understood and fully managed. 0 otherwise.
     */
    virtual int handleKeyEvent(char key);

    /**
     * Initialise all the resources needed for rendering : shaders, geometries, teture, ...
     */
    virtual void initRessources();

    /**
     * Initialise the viewing configuration
     */
    virtual void initView();

    /**
     * Initialise the geometric content
     */
    virtual void initGeometry();

    /**
     * Initialise the lighting configuration
     */
    virtual void initLighting();

    /**
     * Initialise the shader configuration
     */
    virtual void initShaders();


    int width(){ return width_; }
    int height(){ return height_; }

    const std::vector<GlEntity*> &getEntities() {return entities_;}

    const std::vector<MyGlLight*> &getLights() {return lights_;}

    glm::mat4 getViewMatrix(){return viewMatrix_;}
protected:
    int width_;
    int height_;

private:
    int initShader(std::string vsFileName, std::string fsFileName);
    /**
      * Vector of meshes of the scene.
      */
    std::vector<GlMesh*> meshes_;

    /**
      * Vector of entities to be drawn.
      */
    std::vector<GlEntity*> entities_;

    /**
      * Vector of lights.
      */
    std::vector<MyGlLight*> lights_;

    /**
      * OpenGl Shader Program to be used when drawing.
      */
    int program_;
    int programLine_;

public:




private:
    /**
      * Viewing matrix for the rendering.
      */
    glm::mat4 viewMatrix_;

};

} // namespace rendersystem

/** @} */ // end of RenderSystem group


#endif


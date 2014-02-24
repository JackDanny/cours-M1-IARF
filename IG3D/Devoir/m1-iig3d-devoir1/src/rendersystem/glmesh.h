#ifndef GLMESH_H
#define GLMESH_H
#include "tp_defines.h"
#include "opengl.h"
#include "mesh.h"
#include "gldrawable.h"

namespace rendersystem {

/**
  * @ingroup RenderSystem
  * A mesh with OpenGL rendering capabilities.
  */
class GlMesh : public loaders::Mesh, public GlDrawable {
private :
    // OpenGL stuffs
        GLuint vertexArrayObject_;
        enum {VBO_VERTICES, VBO_INDICES};
        GLuint vertexBufferObjects_[2];

public:
    GlMesh (const loaders::Mesh &mesh) : loaders::Mesh(mesh){
    }

    GlMesh (const std::vector<float> &vertexBuffer, const std::vector<int> &triangleBuffer, bool hasNormals=true, bool hasTextureCoords=true )
        : loaders::Mesh(vertexBuffer, triangleBuffer, std::vector<int>() , hasNormals, hasTextureCoords) {
    }

    /**
      * Build VartexArrayObjects for the mesh.
      */
    void compileGL();

    void destroyGL();

    /**
      * Draws the VartexArrayObjects of the mesh.
      */
    void drawGL();

    void getData ( std::vector<float> &vertexBuffer,
                               std::vector<int> &triangleBuffer,
                               bool &parametrized
                             ) {loaders::Mesh::getData(vertexBuffer, triangleBuffer, parametrized); }

};

}

#endif // MESH_H

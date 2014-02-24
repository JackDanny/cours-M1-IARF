#ifndef GLENTITY_H
#define GLENTITY_H

#include "tp_defines.h"
#include "opengl.h"
#include "glmesh.h"
#include "glmaterial.h"

namespace rendersystem {

//-------------------------------------------
// Classe MyGLEntity
//-------------------------------------------
class GlEntity {
    GlDrawable *mesh_;
    GlMaterial *material_;
    glm::mat4 modelToSceneMatrix_;

public:
    GlEntity(GlDrawable *theMesh, GlMaterial *theMaterial, const glm::mat4 &theTransformation) : mesh_(theMesh), material_(theMaterial), modelToSceneMatrix_(theTransformation) {}

    void drawGL(const glm::mat4x4 &sceneToViewMatrix, const glm::mat4x4 &projectionMatrix, int transformLocation[4], int materialLocation[4]);

    glm::mat4 getModelMatrix() const {return modelToSceneMatrix_;}

    GlDrawable *getMesh() const {return mesh_;}

    GlMaterial *getMaterial() const {return material_;}
};


}
#endif // GLENTITY_H

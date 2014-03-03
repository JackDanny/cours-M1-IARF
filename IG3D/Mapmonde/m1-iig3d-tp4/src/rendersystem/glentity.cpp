#include "tp_defines.h"

#include "glentity.h"

#include "parametricmeshes.h"

namespace rendersystem {

//-------------------------------------------
// Classe MyGLEntity
//-------------------------------------------

void GlEntity::drawGL(const glm::mat4x4 &sceneToViewMatrix, const glm::mat4x4 &projectionMatrix, int transformLocation[4], int materialLocation[4])  {
    // 2 - Construire les matrices de vue et de projection :
    //    2.1 - Définir une matrice de projection perspective
    glm::mat4x4 localprojectionMatrix = projectionMatrix;
    //    2.2 - Définir la matrice de vue à partir de sceneToViewMatrix et de mTransformMatrix
    glm::mat4x4 localmodelViewMatrix = sceneToViewMatrix*modelToSceneMatrix_;
    //    2.3 - Calculer la matrice de transformation des normales
    glm::mat4x4 normalMatrix = glm::transpose(glm::inverse(localmodelViewMatrix));
    //    2.4 - Calculer la matrice MVP de passage du repère objet au repère image
    glm::mat4x4 MVP = localprojectionMatrix * localmodelViewMatrix;
    // 3 - Paramétrer les shader par défaut :
    //    3.1 - Positionner les paramètres de transformation
    glAssert( glUniformMatrix4fv( transformLocation[0], 1, GL_FALSE, glm::value_ptr(localmodelViewMatrix)) );
    glAssert( glUniformMatrix4fv( transformLocation[1], 1, GL_FALSE, glm::value_ptr(localprojectionMatrix)));
    glAssert( glUniformMatrix4fv( transformLocation[2], 1, GL_FALSE, glm::value_ptr(normalMatrix)));
    glAssert( glUniformMatrix4fv( transformLocation[3], 1, GL_FALSE, glm::value_ptr(MVP)));
    // 3.2 bind the material
    material_->bindGL(materialLocation);

    // 4 - Dessiner le maillage :
    mesh_->drawGL();

}



}



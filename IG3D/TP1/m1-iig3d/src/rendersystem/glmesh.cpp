#include "glmesh.h"


namespace rendersystem {

//-------------------------------------------
// Code devant être modifié par les étudiants
//-------------------------------------------

//-------------------------------------------
// TP1
//-------------------------------------------

//-------------------------------------------
// Classe MyGLMesh
//-------------------------------------------

#define BUFFER_OFFSET(i) ((char *)NULL + (i))


    /**
      * Build VartexArrayObjects for the mesh.
      */
    void GlMesh::compileGL() {

        // Début du code à écrire
        // 1 - Générer un identifiant pour un VertexArrayObject et le stocker dans l'attribut mVertexArrayObject
        // 2 - Générer deux identifiants pour deux VertexBufferObject (un pour les sommets, l'autre pour les faces) et les stocker dans l'attribut mVertexBufferObjects
        // 3 - Activez le VertexArrayObject
        // 4 - Activez le VertexBufferObject contenant les sommets (GL_ARRAY_BUFFER)
        // 5 - Remplir le VertexBufferObject contenant les sommets
        // 6 - Décrire l'organisation mémoire (glVertexAttribPointer) permettant à OpenGL d'accéder aux informations
        // de position (index 0), de normale (index 1) et de coordonnées de texture (index 2) pour chaque sommet.
        // position

        // normal

        // texcoord

        // 7 - Activez le VertexBufferObject contenant les faces (GL_ELEMENT_ARRAY_BUFFER)
        // 8 - Remplir le VertexBufferObject contenant les faces

        // Fin du code à écrire


    }

    void GlMesh::destroyGL(){
        glAssert(glDeleteVertexArrays(1, &vertexArrayObject_));
        vertexArrayObject_ = 0;
        glAssert(glDeleteBuffers(2, vertexBufferObjects_));
        vertexBufferObjects_[0] = 0;
        vertexBufferObjects_[1] = 1;
    }

    /**
      * Draws the VartexArrayObjects of the mesh.
      */
    void GlMesh::drawGL() {

        // Début du code à écrire
        // 1 - Activer le VAO

        // 2 - Dessiner les triangles. Les sommets des triangles étant indexés et non consécutifs (sauf cas très particulier)
        // on utilisera la fonction glDrawElements(...)

        // Fin du code à écrire


    }



}



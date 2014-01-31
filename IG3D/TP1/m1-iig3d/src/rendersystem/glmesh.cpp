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
		glAssert( glGenVertexArrays(1, &vertexArrayObject_) );

		
		// 2 - Générer deux identifiants pour deux VertexBufferObject (un pour les sommets, l'autre pour les faces) et les stocker dans l'attribut mVertexBufferObjects
        glAssert( glGenBuffers(2, VertexBufferObjects_));
		
		// 3 - Activez le VertexArrayObject
		glAssert( glBindVertexArray(VertexArrayObject_));
		
        // 4 - Activez le VertexBufferObject contenant les sommets (GL_ARRAY_BUFFER)
		glAssert( glBindBuffer(GL_ARRAY_BUFFER, vertexBufferObjects_[VBO_VERTICES]) );
		
        // 5 - Remplir le VertexBufferObject contenant les sommets
		glAssert( glBufferData(GL_ARRAY_BUFFER,nbVertices_ * sizeof(Vertex), &(vertices[0]),GL_STATIC_DRAW));

		
		// 6 - Décrire l'organisation mémoire (glVertexAttribPointer) permettant à OpenGL d'accéder aux informations
        // de position (index 0), de normale (index 1) et de coordonnées de texture (index 2) pour chaque sommet.
		GLuint stride = sizeof(Vertex);
		GLboolean normalized= GL_FALSE;
		GLenum type = GL_FLOAT;
							   
		// position
							   GLuint index=0;
							   GLint size=3;
							   GLvoid *pointer = BUFFER_OFFSET(0)
							   glAssert( glVertexAttribPointer(index,size,type,normalized,stride,pointer) );
							   glAssert( glEnableVertexAttribArray(index) );

        // normal
							   
							   index=1;
							   size = 3;
							   pointer=BUFFER_OFFSET(sizeof(glm::vec3));
							   glAssert(glVertexAttribPointer(index,size,type,normalized, stride, pointer) );
							   glAssert( glEnableVertexAttribArray(index) );

        // texcoord
							   index=2;
							   size=2;
							   pointer=BUFFER_OFFSET(2*sizeof(glm::vec3));
							   glAssert( glVertexAttribPointer(index,size,type,normalized, stride, pointer) );
							   glAssert( glEnableVertexAttribArray(index) );
							   

        // 7 - Activez le VertexBufferObject contenant les faces (GL_ELEMENT_ARRAY_BUFFER)
							   
							   glAssert( glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vertexBufferObjects_[VBO_VERTICES]) );
        // 8 - Remplir le VertexBufferObject contenant les faces
				 glAssert( glBufferData(GL_ELEMENT_ARRAY_BUFFER, 3*nbTriangles_ * sizeof(int), &(triangles[0]),GL_STATIC_DRAW);
        // Fin du code à écrire
				glAssert(glBindVertexArray(0) );
																											   


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
		
		glAssert( glBindVertexArray(VertexArrayObject_));


        // 2 - Dessiner les triangles. Les sommets des triangles étant indexés et non consécutifs (sauf cas très particulier)
        // on utilisera la fonction glDrawElements(...)

		glAssert( glDrawElements(GL_TRIANGLES, 3*nbTriangles_, GL_UNSIGNED_INT, NULL) );

        // Fin du code à écrire


    }



}



#include "parametricmeshes.h"
namespace rendersystem {


//-------------------------------------------
// TP3
//-------------------------------------------

//-------------------------------------------
// Classe ParametricMesh
//-------------------------------------------

    void ParametricMesh::generateMesh(int res_u, int res_v) {
        assert(res_u > 0); assert(res_v > 0);
        triangles_.clear();
        vertices_.clear();

        // Sample surface
        double step_u = 1. / (double)res_u;
        double step_v = 1. / (double)res_v;
        for(int j = 0; j < (res_v+1); j++)
            for(int i = 0; i < (res_u+1); i++)
                vertices_.push_back( evalSurface( ((double)i)*step_u, ((double)j)*step_v) );

        // Compute faces
        for(int i = 0; i < res_u; i++)
        {
            for(int j = 0; j < res_v; j++)
            {
                int a = toLinear(i  , j  , res_u+1);
                int b = toLinear(i+1, j  , res_u+1);
                int c = toLinear(i+1, j+1, res_u+1);
                int d = toLinear(i  , j+1, res_u+1);

                triangles_.push_back( TriangleIndex(a, b, c) );
                triangles_.push_back( TriangleIndex(a, c, d) );
            }
        }

        nbVertices_  = vertices_. size();
        nbTriangles_ = triangles_.size();

        hasNormal_        = true;
        hasTextureCoords_ = true;
    }

    loaders::Mesh::Vertex ParametricMesh::evalSurface(float u, float v) const {

        // de base un plan.
        assert(u >= 0.f); assert(u <= 1.f);
        assert(v >= 0.f); assert(v <= 1.f);

        Vertex vert;
        vert.position_ = glm::vec3(u-0.5f, v-0.5f, 0.f);
        vert.normal_   = glm::vec3(0.f   , 0.f   , 1.f);
        vert.texcoord_ = glm::vec2(u, v);
        return vert;
    }

    int ParametricMesh::toLinear(int x, int y, int width) const{
        return y*width + x;
    }


//-------------------------------------------
// Classe ParametricSphere
//-------------------------------------------

    loaders::Mesh::Vertex ParametricSphere::evalSurface(float u, float v) const {
        assert(u >= 0.f); assert(u <= 1.f);
        assert(v >= 0.f); assert(v <= 1.f);

        Vertex vert;
        vert.texcoord_ = glm::vec2(u, v);

        u  = u * (2. * M_PI);
        v = v * M_PI;
        float x = cos(u)*sin(v);
        float y = sin(u)*sin(v);
        float z = cos(v);

        vert.position_ = glm::vec3(x, y, z);
        vert.normal_   = glm::vec3(x, y, z);
        return vert;

    }

//-------------------------------------------
// Classe ParametricCylindre
//-------------------------------------------

    loaders::Mesh::Vertex ParametricCylindre::evalSurface(float u, float v) const {
        assert(u >= 0.f); assert(u <= 1.f);
        assert(v >= 0.f); assert(v <= 1.f);

        Vertex vert;
        vert.texcoord_ = glm::vec2(u, v);

        u  = u * (2. * M_PI);

        float x = cos(u);
        float y = sin(u);
        float z = v;

        vert.position_ = glm::vec3(x, y, z  );
        vert.normal_   = glm::vec3(x, y, 0.f);
        return vert;


    }

//-------------------------------------------
// Classe ParametricCone
//-------------------------------------------

    loaders::Mesh::Vertex ParametricCone::evalSurface(float u, float v) const {
        assert(u >= 0.f); assert(u <= 1.f);
        assert(v >= 0.f); assert(v <= 1.f);

        Vertex vert;
        vert.texcoord_ = glm::vec2(u, v);

        u  = u * (2. * M_PI);

        float x = v*cos(u);
        float y = v*sin(u);
        float z = v;

        vert.position_ = glm::vec3(x, y, z  );        
        vert.normal_   = -glm::normalize( glm::cross(glm::vec3(cos(u), sin(u), 1.f), glm::vec3(-sin(u), cos(u), 0.f)));
        glm::normalize(vert.normal_);
        return vert;

    }

}

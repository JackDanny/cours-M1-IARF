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
        loaders::Mesh::Vertex vert;
        glm::vec3 xyz;

        float pi=3.14159265359;

        xyz[0]=cos(u*2.*pi)*sin(v*pi);
        xyz[1]=sin(u*2.*pi)*sin(v*pi);
        xyz[2]=cos(v*pi);

        vert.position_ = xyz;
        vert.normal_ = xyz;
        vert.texcoord_ = glm::vec2(u,v);

        return vert;
    }

//-------------------------------------------
// Classe ParametricCylindre
//-------------------------------------------

    loaders::Mesh::Vertex ParametricCylindre::evalSurface(float u, float v) const {


        loaders::Mesh::Vertex vert;
        glm::vec3 xyz;

        float pi=3.14159265359;

        xyz[0]=cos(u*2.*pi);
        xyz[1]=sin(u*2.*pi);
        xyz[2]=v;

        vert.position_ = xyz;
        vert.normal_ = glm::vec3(cos(u*2.*pi),sin(u*2.*pi),0.);
        vert.texcoord_ = glm::vec2(u,v);

        return vert;









    }

//-------------------------------------------
// Classe ParametricCone
//-------------------------------------------

    loaders::Mesh::Vertex ParametricCone::evalSurface(float u, float v) const {

        loaders::Mesh::Vertex vert;
        glm::vec3 xyz;

        float pi=3.14159265359;
        float a=pi/8.;
        xyz[0]=v*tan(a)*cos(2*pi*u);
        xyz[1]=v*tan(a)*sin(2*pi*u);
        xyz[2]=v;

        vert.position_ = xyz;
        vert.normal_ = xyz;
        vert.texcoord_ = glm::vec2(u,v);

        return vert;

    }

}

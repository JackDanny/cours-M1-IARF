#ifndef PARAMETRICMESHES_H
#define PARAMETRICMESHES_H
#include "tp_defines.h"
#include "mesh.h"


namespace rendersystem {

//-------------------------------------------
// TP3
//-------------------------------------------

//-------------------------------------------
// Classe ParametricMesh
//-------------------------------------------

class ParametricMesh : public loaders::Mesh {
public:
    ParametricMesh() : Mesh() { }

    virtual void generateMesh(int res_u, int res_v);

protected:
    virtual Vertex evalSurface(float u, float v) const;

    int toLinear(int x, int y, int width) const;
};

//-------------------------------------------
// Classe ParametricSphere
//-------------------------------------------

class ParametricSphere : public ParametricMesh {
public:
    ParametricSphere() : ParametricMesh() { }

protected:
    Vertex evalSurface(float u, float v) const;
};

//-------------------------------------------
// Classe ParametricCylindre
//-------------------------------------------

class ParametricCylindre : public ParametricMesh {
public:
    ParametricCylindre() : ParametricMesh() { }

protected:
    Vertex evalSurface(float u, float v) const;
};

//-------------------------------------------
// Classe ParametricCone
//-------------------------------------------

class ParametricCone : public ParametricMesh {
public:
    ParametricCone() : ParametricMesh() { }

protected:
    Vertex evalSurface(float u, float v) const;
};

}

#endif // PARAMETRICMESHES_H

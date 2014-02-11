#ifndef ICOSAHEDRE_H
#define ICOSAHEDRE_H

#include "tp_defines.h"
#include "mesh.h"


namespace rendersystem {

class Icosahedre : public loaders::Mesh
{
public:
    Icosahedre() : Mesh() { }

    virtual void generateMesh();
    
};
}

#endif // ICOSAHEDRE_H

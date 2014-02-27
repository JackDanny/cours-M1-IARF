#ifndef GEODESIQUE_H
#define GEODESIQUE_H

#include "tp_defines.h"
#include "mesh.h"


namespace rendersystem {

class Geodesique : public loaders::Mesh
{
public:
    Geodesique() : Mesh() { }

    virtual void generateMesh();

    void drawtriangle(glm::vec3 v1,glm::vec3 v2,glm::vec3 v3);

    void subdivide(glm::vec3 v1,glm::vec3 v2,glm::vec3 v3,int depth);



};
}

#endif // GEODESIQUE_H

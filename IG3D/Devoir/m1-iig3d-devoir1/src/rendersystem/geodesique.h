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

    void drawtriangle(glm::vec3 pos1,glm::vec3 pos2,glm::vec3 pos3);

    void subdivide(glm::vec3 pos1,glm::vec3 pos2,glm::vec3 pos3,int depth);

    void drawtriangleOptimize(int ind1,int ind2,int ind3);

    void subdivideOptimize(int ind1,int ind2,int ind3,int depth);

};
}

#endif // GEODESIQUE_H

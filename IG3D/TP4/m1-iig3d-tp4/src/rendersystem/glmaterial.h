#ifndef GLMATERIAL_H
#define GLMATERIAL_H

#include "opengl.h"
#include "texture.h"

namespace rendersystem {

//-------------------------------------------
// Classe Material
//-------------------------------------------
class GlMaterial {
    glm::vec3 kd_;
    glm::vec3 ks_;
    float ns_;

    Texture *texture_;

public:
    GlMaterial(glm::vec3 kd, glm::vec3 ks, float n) : kd_(kd), ks_(ks), ns_(n), texture_(NULL) {}

    void getParameters(glm::vec3 &kd, glm::vec3 &ks, float &n, Texture *&texture) {
        kd = kd_;
        ks = ks_;
        n=ns_;
        texture=texture_;
    }

    void setTexture(Texture *tex);

    void bindGL(int parameterLocation[4]);
};


}
#endif // GLMATERIAL_H

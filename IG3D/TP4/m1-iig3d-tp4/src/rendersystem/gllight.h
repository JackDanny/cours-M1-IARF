#ifndef GLLIGHT_H
#define GLLIGHT_H
#include "opengl.h"

namespace rendersystem {

class MyGlLight
{
glm::vec3 position_;
glm::vec3 color_;
bool shadowCaster_;
public:
    MyGlLight(const glm::vec3 &pos, const glm::vec3 &col, bool sc);
    const glm::vec3 &getPosition();
    const glm::vec3 &getColor();
    bool castShadows();
};


}

#endif // MYGLLIGHT_H

#include "gllight.h"
namespace rendersystem {

MyGlLight::MyGlLight(const glm::vec3 &pos, const glm::vec3 &col, bool sc) : position_(pos), color_(col), shadowCaster_(sc) {
}
const glm::vec3 &MyGlLight::getPosition(){
    return position_;
}

const glm::vec3 &MyGlLight::getColor(){
    return color_;
}

bool MyGlLight::castShadows(){
    return shadowCaster_;
}


}

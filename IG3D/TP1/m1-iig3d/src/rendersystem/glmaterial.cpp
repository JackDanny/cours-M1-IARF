
#include "glmaterial.h"

namespace rendersystem {

//-------------------------------------------
// Classe Material
//-------------------------------------------

    void GlMaterial::setTexture(Texture *tex){
        texture_ = tex;
    }

    void GlMaterial::bindGL(int parameterLocation[4]){
        glAssert( glUniform3fv( parameterLocation[0], 1, glm::value_ptr(kd_)) );
        glAssert( glUniform3fv( parameterLocation[1], 1, glm::value_ptr(ks_)) );
        glAssert( glUniform1f( parameterLocation[2], ns_) );
        if(texture_) texture_->bind(0);
        glAssert( glUniform1i(parameterLocation[3], 0) );
    }


}

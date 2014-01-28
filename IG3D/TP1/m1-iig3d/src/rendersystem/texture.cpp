#include "texture.h"
#include <iostream>

namespace rendersystem {

Texture::Texture (std::string filename){
    QImage img(filename.c_str());
    std::cerr << filename << " : " << img.width() << "x" << img.height() << " - " << img.depth() << "bpp" << std::endl;

    int bpp = (img.depth() == 32) ? GL_RGBA : GL_RGB;
    int format = (img.depth() == 32) ? GL_BGRA : GL_BGR;

    initGL(bpp, img.width(), img.height(), format, GL_UNSIGNED_BYTE, img.bits() );

}

Texture::Texture (unsigned char color[3]){
    initGL(GL_RGB, 1, 1, GL_RGB, GL_UNSIGNED_BYTE, color);
}

void Texture::initGL(int bytesperpixel, int width, int height, int format, int type, unsigned char * data)
{
    width_=width;
    height_=height;
    format_ = (bytesperpixel == GL_RGBA);
    pixOrder_ = (GL_RGB == format);
    pixels_ = new unsigned char[width_*height_*(3+format_)];
    memcpy(pixels_, data, width_*height_*(3+format_)*sizeof(unsigned char));

    glAssert(glGenTextures(1, &mTexId));
    glAssert(glBindTexture(GL_TEXTURE_2D, mTexId));
    glAssert(glTexImage2D(GL_TEXTURE_2D, 0, bytesperpixel, width, height, 0, format, type, data));
    glAssert(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT));
    glAssert(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT));
    glAssert(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST));
    glAssert(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST));
}


void Texture::useMipMap(GLenum minFliter, GLenum magFilter)
{
    glAssert(glBindTexture(GL_TEXTURE_2D, mTexId));
    glAssert(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, magFilter));
    glAssert(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, minFliter));
    glAssert(glGenerateMipmap(GL_TEXTURE_2D));
}

void Texture::setFilter(GLenum minFliter, GLenum magFilter)
{
    glAssert(glBindTexture(GL_TEXTURE_2D, mTexId));
    glAssert(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, magFilter));
    glAssert(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, minFliter));
}
void Texture::setClamp(GLenum warpS, GLenum warpT)
{
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, warpS);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, warpT);
}


void Texture::bind(int unit)
{
    GLenum texUnit = GL_TEXTURE0+unit;
    glAssert(glActiveTexture(texUnit));
    glAssert(glBindTexture(GL_TEXTURE_2D, mTexId));
}

void Texture::deleteGL()
{
    glDeleteTextures(1, &mTexId);
}


void Texture::getPixel(float u, float v, glm::vec3 &color) {
    float scaledU = u * width_;
    float scaledV = v * height_;
    int s = (int)scaledU;
    int t = (int)scaledV;

    glm::vec3 centerColor;
    int linPos = (t*width_ + s)*(3+format_);
    if (pixOrder_) {
        centerColor.x = ((float) pixels_[linPos])/255.0;
        centerColor.y = ((float) pixels_[linPos+1])/255.0;
        centerColor.z = ((float) pixels_[linPos+2])/255.0;
    } else {
        centerColor.x = ((float) pixels_[linPos+2])/255.0;
        centerColor.y = ((float) pixels_[linPos+1])/255.0;
        centerColor.z = ((float) pixels_[linPos])/255.0;
    }
    color = centerColor;

}

}

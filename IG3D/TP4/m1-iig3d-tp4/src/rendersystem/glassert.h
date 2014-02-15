#ifndef GL_ASSERT_H
#define GL_ASSERT_H

/**
 *
 * OpenGL error management class.
 *
 */

#ifndef NDEBUG
// debug mode

#include <iostream>
#include <cassert>

#ifdef __APPLE__
// MacOsX stuff
#define glAssert(code) \
    code; \
    {\
        GLuint err = glGetError(); \
        if (err != GL_NO_ERROR) { \
            std::cerr<<"erreur OpenGL ("<<__FILE__<<":"<<__LINE__<<", "<<__STRING(code)<<\
                ( (err == GL_INVALID_ENUM) ? " Invalid enum" : \
                ( (err == GL_INVALID_VALUE) ? " Invalid value" : \
                ( (err == GL_INVALID_OPERATION) ? " Invalid operation" : "unknown error") \
                ) \
                )\
                << "("<<err<<")"<<std::endl; \
            assert(false); \
        } \
    }

#define glCheckError() \
    {\
        GLuint err = glGetError(); \
        if (err != GL_NO_ERROR) { \
            std::cerr<<"erreur OpenGL ("<<__FILE__<<":"<<__LINE__<<\
    ( (err == GL_INVALID_ENUM) ? " Invalid enum" : \
    ( (err == GL_INVALID_VALUE) ? " Invalid value" : \
    ( (err == GL_INVALID_OPERATION) ? " Invalid operation" : "unknown error") \
    ) \
    )\
    << "("<<err<<")"<<std::endl; \
            assert(false); \
        } \
    }

#else
// Linux stuff
#define glAssert(code) \
    code; \
{\
    GLuint err = glGetError(); \
    if (err != GL_NO_ERROR) { \
    std::cerr<<"erreur OpenGL ("<<__FILE__<<":"<<__LINE__<<", "<<__STRING(code)<<") : "<<(const char*)gluErrorString (err)<<"("<<err<<")"<<std::endl; \
    } \
    }

#define glCheckError() \
    {\
        GLuint err = glGetError(); \
        if (err != GL_NO_ERROR) { \
            std::cerr<<"erreur OpenGL ("<<__FILE__<<":"<<__LINE__<<", "<<__STRING()<<") : "<<(const char*)gluErrorString (err)<<"("<<err<<")"<<std::endl; \
          } \
    }

#endif

#else

// No debug
#define glAssert(code) \
    code;

#endif



#endif

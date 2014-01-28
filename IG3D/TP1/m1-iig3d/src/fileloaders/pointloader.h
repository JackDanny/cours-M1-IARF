#ifndef POINTLOADER_H
#define POINTLOADER_H
#include <iostream>
#include <fstream>
#include <vector>
#include "glm/glm.hpp"


namespace loaders {


/**
  * @ingroup Loaders
  * Text file loader.
  * This namespace contains functions for loading text files.
  */
namespace text {

class PointLoader
{
public:
    PointLoader(const char* filename) : mFilename(filename){};
    ~PointLoader(){}
    int load(const glm::vec3 &min, const glm::vec3 &max);

    const std::vector<glm::vec3> &getPoints(){return mPoints;}
private:
    std::vector<glm::vec3> mPoints;
    std::string mFilename;
};



} // end namespace file
} // end namespace loaders

#endif // POINTLOADER_H

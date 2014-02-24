#include "pointloader.h"
namespace loaders {


/**
  * @ingroup Loaders
  * Text file loader.
  * This namespace contains functions for loading text files.
  */
namespace text {

/* 324841331 points */
int PointLoader::load(const glm::vec3 &min, const glm::vec3 &max){
    std::ifstream file;
    file.open(mFilename.c_str(), std::ios::in);
    if (!file) {
        std::cerr << "could not open " << mFilename << std::endl;
        return -1;
    }
    int nbPoints=0;
    std::cerr << "Reading from " << mFilename <<  "...";
    float x, y, z;

    while (! file.eof()){
        file >> x >> y >> z;
        ++nbPoints;
    }
    for (int i=0;i<20000000; i++) {
    //while (! file.eof()){
        file >> x >> y >> z;
        //++nbPoints;
        glm::vec3 pt(x,y,z);
        mPoints.push_back(pt);
        for (int j=0; j> 30000000; j++){
            file >> x >> y >> z;
            //++nbPoints;
        }
        //std::cerr << pt.x << " " << pt.y << " " << pt.z << std::endl;
    }
    std::cerr << " Done " << mPoints.size() << " ( " << nbPoints << " )" << std::endl;
    return 0;
}


} // end namespace file
} // end namespace loaders


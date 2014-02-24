#ifndef GLDRAWABLE_H
#define GLDRAWABLE_H
#include <vector>

namespace rendersystem {

class GlDrawable
{
public:
    GlDrawable();
    virtual ~GlDrawable(){}

    virtual void drawGL() =0;

    virtual void getData ( std::vector<float> &vertexBuffer,
                           std::vector<int> &triangleBuffer,
                           bool &parametrized
                         ) {}
};

}
#endif // GLDRAWABLE_H

#include "geodesique.h"
#include <iostream>
#include <map>



using namespace std;

namespace rendersystem {

int indiceMap=0;



struct classcomp {
    bool operator() (const glm::vec3 v1, const glm::vec3 v2) const
    {
        if(v1[0]<v2[0]){

            return true;
        }
        else if(v1[0]==v2[0]){
            if(v1[1]<v2[1]){
                return true;
            }
            else if(v1[1]==v2[1]){
                if(v1[2]<v2[2]){
                    return true;
                }
            }

        }

        return false;

    }
};

std::map<glm::vec3,int,classcomp> mymap;

void Geodesique::generateMesh() {

    triangles_.clear();
    vertices_.clear();

    loaders::Mesh::Vertex vert;
    glm::vec3 xyz;



    float phi=(1+sqrt(5))/2.;



    glm::vec3 vdata[12] = {
        glm::vec3(phi,1,0.0),
        glm::vec3(phi,-1,0.0),
        glm::vec3(-phi,1,0.0),
        glm::vec3(-phi,-1,0.0),

        glm::vec3(1,0,phi),
        glm::vec3(1,0,-phi),
        glm::vec3(-1,0,phi),
        glm::vec3(-1,0,-phi),

        glm::vec3(0,phi,1),
        glm::vec3(0,phi,-1),
        glm::vec3(0,-phi,1),
        glm::vec3(0,-phi,-1)
    };
    /*

    myset.insert(glm::vec3(phi,1.,0.));
    myset.insert(glm::vec3(phi,-1.,0.));
    myset.insert(glm::vec3(-phi,1.,0.));
    myset.insert(glm::vec3(-phi,-1.,0.));

    myset.insert(glm::vec3(1,0,phi));
    myset.insert(glm::vec3(1,0,-phi));
    myset.insert(glm::vec3(-1,0,phi));
    myset.insert(glm::vec3(-1,0,-phi));

    myset.insert(glm::vec3(0,phi,1));
    myset.insert(glm::vec3(0,phi,-1));
    myset.insert(glm::vec3(0,-phi,1));
    myset.insert(glm::vec3(0,-phi,-1));

    */



    int i;

    uint tindices[20][3] ={
        {2,8,9},{9,8,0},{0,8,4},{4,8,6},{6,8,2},
        {3,11,10},{10,11,1},{1,11,5},{5,11,7},{7,11,3},
        {3,2,7},{7,2,9},{7,9,5},{5,9,0},{5,0,1},{1,0,4},{1,4,10},{10,4,6},{10,6,3},{3,6,2}
    };

    //rajout pour optimize
    /*
    for(i=0;i<12;i++){
        glm::vec3 pos;
        pos[0]=vdata[i][0];
        pos[1]=vdata[i][1];
        pos[2]=vdata[i][2];
        loaders::Mesh::Vertex vert;
        pos = glm::normalize(pos);
        vert.position_ = pos;
        vert.normal_ = pos;
        vertices_.push_back(vert);


    }
    */

    for(i=0;i<20;i++){
        /*
        float[3] s1;
        float[3] s2;
        float[3] s3;

        it=myset.find(vdata[tindices[i][0]]);

        it=myset.find(vdata[tindices[i][1]]);

        it=myset.find(vdata[tindices[i][1]]);

        ls1[0]=(it+(tindices[i][0]))[0];
        ls1[1]=(it+(tindices[i][0]))[1];
        ls1[2]=(it+(tindices[i][0]))[2];

        ls2[0]=(it+(tindices[i][1]))[0];
        ls2[1]=(it+(tindices[i][1]))[1];
        ls2[2]=(it+(tindices[i][1]))[2];

        ls3[0]=(it+(tindices[i][2]))[0];
        ls3[1]=(it+(tindices[i][1]))[1];
        ls3[2]=(it+(tindices[i][1]))[2];
        */
        /*
        vec1=glm::normalize(vec1);
        vec2=glm::normalize(vec2);
        vec3=glm::normalize(vec3);


        */




        subdivide(vdata[tindices[i][0]],vdata[tindices[i][1]],vdata[tindices[i][2]],10);
        //subdivideOptimize2(tindices[i][0],tindices[i][1],tindices[i][2],9);
    }



    cout << "nb sommet = " << vertices_. size();;
    cout << "\nnb triangles = " << triangles_.size();
    cout << "\n";

    nbVertices_  = vertices_. size();
    nbTriangles_ = triangles_.size();

    hasNormal_        = true;
    hasTextureCoords_ = true;

}


















void Geodesique::drawtriangle(glm::vec3 v1,glm::vec3 v2,glm::vec3 v3){
    std::pair<std::map<glm::vec3,int>::iterator,bool> ret;

    loaders::Mesh::Vertex vert;
    //float length=vertices_.size();
    int ind1;
    int ind2;
    int ind3;
    /*
    float f1[3];

    f1[0]=v1[0];
    f1[1]=v1[1];
    f1[2]=v1[2];
    */
    ret = mymap.insert( std::pair<glm::vec3,int>(v1,indiceMap) );

    if (ret.second==false){
        ind1=ret.first->second;
    }
    else{
        vert.position_ = v1;
        vert.normal_ = v1;
        vertices_.push_back(vert);
        ind1=indiceMap;
        indiceMap++;

    }
    /*
    float f2[3];

    f2[0]=v2[0];
    f2[1]=v2[1];
    f2[2]=v2[2];
    */

    ret = mymap.insert ( std::pair<glm::vec3,int>(v2,indiceMap) );

    if (ret.second==false){
        ind2=ret.first->second;
    }
    else{
        vert.position_ = v2;
        vert.normal_ = v2;
        vertices_.push_back(vert);
        ind2=indiceMap;
        indiceMap++;

    }
    /*
    float f3[3];

    f3[0]=v3[0];
    f3[1]=v3[1];
    f3[2]=v3[2];
    */

    ret = mymap.insert ( std::pair<glm::vec3,int>(v3,indiceMap) );

    if (ret.second==false){
        ind3=ret.first->second;
    }
    else{
        vert.position_ = v3;
        vert.normal_ = v3;
        vertices_.push_back(vert);
        ind3=indiceMap;
        indiceMap++;

    }

    triangles_.push_back(TriangleIndex(ind1, ind2, ind3) );
}

void Geodesique::subdivide(glm::vec3 v1,glm::vec3 v2,glm::vec3 v3,int depth){


    if(depth==0){
        drawtriangle(v1,v2,v3);
        return;
    }
    else{


        glm::vec3 v4;
        glm::vec3 v5;
        glm::vec3 v6;

        v1=glm::normalize(v1);
        v2=glm::normalize(v2);
        v3=glm::normalize(v3);


        v4=v1+v2;
        v5=v2+v3;
        v6=v3+v1;

        v4=glm::normalize(v4);
        v5=glm::normalize(v5);
        v6=glm::normalize(v6);




        subdivide(v1,v4,v6,depth-1);
        subdivide(v4,v2,v5,depth-1);
        subdivide(v6,v5,v3,depth-1);
        subdivide(v4,v5,v6,depth-1);

    }



}


}

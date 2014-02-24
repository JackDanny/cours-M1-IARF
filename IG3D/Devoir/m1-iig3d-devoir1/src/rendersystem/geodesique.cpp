#include "geodesique.h"
#include <iostream>
using namespace std;

namespace rendersystem {

void Geodesique::generateMesh() {

    triangles_.clear();
    vertices_.clear();

    loaders::Mesh::Vertex vert;
    glm::vec3 xyz;


    float phi=(1+sqrt(5))/2.;

    float vdata[12][3] = {
        {phi,1,0.0},
        {phi,-1,0.0},
        {-phi,1,0.0},
        {-phi,-1,0.0},

        {1,0,phi},
        {1,0,-phi},
        {-1,0,phi},
        {-1,0,-phi},

        {0,phi,1},
        {0,phi,-1},
        {0,-phi,1},
        {0,-phi,-1}
    };

    int i;

    uint tindices[20][3] ={
        {2,8,9},{9,8,0},{0,8,4},{4,8,6},{6,8,2},
        {3,11,10},{10,11,1},{1,11,5},{5,11,7},{7,11,3},
        {3,2,7},{7,2,9},{7,9,5},{5,9,0},{5,0,1},{1,0,4},{1,4,10},{10,4,6},{10,6,3},{3,6,2}
    };

    //rajout pour optimize

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


    for(i=0;i<20;i++){
        glm::vec3 vec1;
        glm::vec3 vec2;
        glm::vec3 vec3;

        vec1[0]=vdata[tindices[i][0]][0];
        vec1[1]=vdata[tindices[i][0]][1];
        vec1[2]=vdata[tindices[i][0]][2];

        vec2[0]=vdata[tindices[i][1]][0];
        vec2[1]=vdata[tindices[i][1]][1];
        vec2[2]=vdata[tindices[i][1]][2];

        vec3[0]=vdata[tindices[i][2]][0];
        vec3[1]=vdata[tindices[i][2]][1];
        vec3[2]=vdata[tindices[i][2]][2];

        vec1=glm::normalize(vec1);
        vec2=glm::normalize(vec2);
        vec3=glm::normalize(vec3);







        //subdivide(vec1,vec2,vec3,9);
        subdivideOptimize(tindices[i][0],tindices[i][1],tindices[i][2],9);
    }





    nbVertices_  = vertices_. size();
    nbTriangles_ = triangles_.size();
    cout << "nb sommet = " << nbVertices_;
     cout << "\nnb triangles = " << nbTriangles_;
    hasNormal_        = true;
    hasTextureCoords_ = true;

}


void Geodesique::drawtriangle(glm::vec3 pos1,glm::vec3 pos2,glm::vec3 pos3){
    loaders::Mesh::Vertex vert;
    float length=vertices_.size();


    vert.position_ = pos1;
    vert.normal_ = pos1;


    vertices_.push_back(vert);

    vert.position_ = pos2;
    vert.normal_ = pos2;

    vertices_.push_back(vert);

    vert.position_ = pos3;
    vert.normal_ = pos3;
    vertices_.push_back(vert);

    triangles_.push_back( TriangleIndex(length, length+1, length+2) );
}

void Geodesique::subdivide(glm::vec3 pos1,glm::vec3 pos2,glm::vec3 pos3,int depth){
    glm::vec3 pos4;
    glm::vec3 pos5;
    glm::vec3 pos6;

    if(depth==0){
        drawtriangle(pos1,pos2,pos3);
        return;
    }
    else{
        pos4=pos1+pos2;
        pos5=pos2+pos3;
        pos6=pos3+pos1;
        pos4=glm::normalize(pos4);
        pos5=glm::normalize(pos5);
        pos6=glm::normalize(pos6);
        subdivide(pos1,pos4,pos6,depth-1);
        subdivide(pos4,pos2,pos5,depth-1);
        subdivide(pos6,pos5,pos3,depth-1);
        subdivide(pos4,pos5,pos6,depth-1);

    }



}

void Geodesique::drawtriangleOptimize(int ind1,int ind2,int ind3){

    triangles_.push_back( TriangleIndex(ind1, ind2, ind3) );
}

void Geodesique::subdivideOptimize(int ind1,int ind2,int ind3,int depth){


    glm::vec3 pos1;
    glm::vec3 pos2;
    glm::vec3 pos3;


    glm::vec3 pos4;
    glm::vec3 pos5;
    glm::vec3 pos6;

    if(depth==0){
        drawtriangleOptimize(ind1,ind2,ind3);
        return;
    }



    else{
        float length=vertices_.size();
        loaders::Mesh::Vertex vert;

        glm::vec3 pos1=vertices_.at(ind1).position_;
        glm::vec3 pos2=vertices_.at(ind2).position_;
        glm::vec3 pos3=vertices_.at(ind3).position_;
        glm::vec3 pos4=pos1+pos2;
        glm::vec3 pos5=pos2+pos3;
        glm::vec3 pos6=pos3+pos1;

        pos4=glm::normalize(pos4);
        pos5=glm::normalize(pos5);
        pos6=glm::normalize(pos6);

        vert.position_ = pos4;
        vert.normal_ = pos4;
        vertices_.push_back(vert);

        int ind4 = length;
        vert.position_ = pos5;
        vert.normal_ = pos5;
        int ind5 = length+1;

        vertices_.push_back(vert);

        vert.position_ = pos6;
        vert.normal_ = pos6;
        vertices_.push_back(vert);
        int ind6 = length+2;

        subdivideOptimize(ind1,ind4,ind6,depth-1);
        subdivideOptimize(ind4,ind2,ind5,depth-1);
        subdivideOptimize(ind6,ind5,ind3,depth-1);
        subdivideOptimize(ind4,ind5,ind6,depth-1);

    }



}


}







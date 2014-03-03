#include "geodesique.h"
#include <iostream>
#include <map>



using namespace std;

namespace rendersystem {


//on déclare une structure faisant office d'opérateur < pour des vec3
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



//on déclare une map comme variable globale
//la clef est un vec 3 désignant un sommet, la valeur est un int indiquant l'indice du sommet,
//et on rajoute la structure précédente pour comparer nos vec3 afin de les trier
std::map<glm::vec3,int,classcomp> mymap;

//l'indice du premier sommet est 0. On le met en variable globale lui aussi
int indiceMap=0;

//generateMesh va generer le maillage
void Geodesique::generateMesh() {

    triangles_.clear();
    vertices_.clear();

    loaders::Mesh::Vertex vert;

    //on se sert du nombre d'or pour les coordonnées des sommets
    float phi=(1+sqrt(5))/2.;


    //on déclare nos 12 sommets comme vec3
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





    //on déclare nos triangles initiaux
    uint tindices[20][3] ={
        {2,8,9},{9,8,0},{0,8,4},{4,8,6},{6,8,2},
        {3,11,10},{10,11,1},{1,11,5},{5,11,7},{7,11,3},
        {3,2,7},{7,2,9},{7,9,5},{5,9,0},{5,0,1},{1,0,4},{1,4,10},{10,4,6},{10,6,3},{3,6,2}
    };

    int i;

    //A chaque itération on subdivise
    for(i=0;i<20;i++){
        subdivide(vdata[tindices[i][0]],vdata[tindices[i][1]],vdata[tindices[i][2]],10);

    }


    //A la fin, lorsqu'on ferme la fenêtre etc... on affiche le nb de sommet afin
    //d'être certain.
    cout << "nb sommet = " << vertices_. size();;
    cout << "\nnb triangles = " << triangles_.size();
    cout << "\n";

    nbVertices_  = vertices_. size();
    nbTriangles_ = triangles_.size();

    hasNormal_        = true;
    hasTextureCoords_ = true;

}


//Rajout d'un triangle et éventuellement de sommets dans le maillage
void Geodesique::drawtriangle(glm::vec3 v1,glm::vec3 v2,glm::vec3 v3){
    //structure servant pour l'itération, je le recrache d'un exemple de
    //http://www.cplusplus.com/reference/map/map/insert/
    std::pair<std::map<glm::vec3,int>::iterator,bool> ret;

    loaders::Mesh::Vertex vert;
    //les indices des trois sommets. ça sert pour insérer le triangle.
    int ind1;
    int ind2;
    int ind3;

    //on essaie d'insérer le couple (v1,indiceMap)
    //ret pointe vers la position où se trouve le sommet en question s'il y est
    //et le rajoute à la bonne position sinon
    ret = mymap.insert( std::pair<glm::vec3,int>(v1,indiceMap) );

    //Si le sommet est dans la map...
    if (ret.second==false){
        //on récupère l'indice du sommet correspondant
        ind1=ret.first->second;
    }

    //Sinon
    else{
        vert.position_ = v1;
        vert.normal_ = v1;

        //on rajoute le sommet
        vertices_.push_back(vert);
        //on stocke l'indice du sommet
        ind1=indiceMap;
        //et on incrémente l'indice
        indiceMap++;

    }

    //belote...
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

    //rebelote...
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
    //et 10 de der, on rajoute le triangle
    triangles_.push_back(TriangleIndex(ind1, ind2, ind3) );
}


//on procède ici à une subdivision récursive. On diminue la valeur de la profondeur à chaque
//itération
void Geodesique::subdivide(glm::vec3 v1,glm::vec3 v2,glm::vec3 v3,int depth){

    //on normalize nos sommets
    v1=glm::normalize(v1);
    v2=glm::normalize(v2);
    v3=glm::normalize(v3);

    //si profondeur nulle on trace le triangle
    if(depth==0){
        drawtriangle(v1,v2,v3);

    }
    else{

        //on declare 3 vec3. Ce seront nos prochain sommets, situés chacun au milieu des trois segments
        //formés par v1 v2 et v3
        glm::vec3 v4;
        glm::vec3 v5;
        glm::vec3 v6;



        //on construit les prochains
        v4=v1+v2;
        v5=v2+v3;
        v6=v3+v1;

        //pas besoin de les normaliser ici, car ils se normaliseront dès le debut de
        //subdivide

        //chacune des faces se subdivisent en 4. On diminue aussi la profondeur
        subdivide(v1,v4,v6,depth-1);
        subdivide(v4,v2,v5,depth-1);
        subdivide(v6,v5,v3,depth-1);
        subdivide(v4,v5,v6,depth-1);

    }



}


}

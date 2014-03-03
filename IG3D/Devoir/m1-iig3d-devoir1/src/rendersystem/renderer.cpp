

#define SCENE_CAMEL
//#define SHOWSPHERE
//#define SHOWHCURVE
//#define SHOW_FRAME

#include "tp_defines.h"
#include "renderer.h"

#include "objloader.h"
#include "fileloader.h"




#include "glmaterial.h"
#include "parametricmeshes.h"
#include "geodesique.h"
#include "icosahedre.h"









#include <glm/gtc/matrix_access.hpp>


namespace rendersystem
{





//-------------------------------------------
/** @defgroup RendererGlobalFunctions Global functions for the renderer.
  * @author Mathias Paulin <Mathias.Paulin@irit.fr>
  * @ingroup RenderSystem
  * Global functions for the renderer.
  */
//-------------------------------------------



//-------------------------------------------
// Méthodes de Renderer
//-------------------------------------------

//-------------------------------------------
// Initialisation des resources globales
//-------------------------------------------
void Renderer::initRessources()
{

    // Initialisation des paramètres OpenGL.
    {
        // 1 - Activer le test de profondeur
        glAssert(glEnable(GL_DEPTH_TEST));
        // 2 - Positionner le mode de dessin
        glAssert(glPolygonMode(GL_FRONT_AND_BACK, GL_FILL));
        // Fin du code à écrire

    }

    // Viewing parameters initialisation
    initView();

    // Loading or building geometric data.
    initGeometry();

    // Set up lighting
    initLighting();

    // Shaders initialisation
    initShaders();
}

//-------------------------------------------
// Initialisation des paramètres de vue.
//-------------------------------------------
void Renderer::initView()
{


    // Initialiser la matrice de vue viewMatrix_ à partir des indications :
    // position de vue : 1.f, 0.f, 0.f
    // point visé : 0.0f, 0.0f, 0.0f
    // vecteur up : 0.0f, 1.0f, 0.0f
    // utiliser la fonction glm::lookAt pour calculer la matrice de vue correspondant
    glm::vec3 eye(1.f, 0.25f, 1.f);
    glm::vec3 center(0.0f, 0.0f, 0.0f);
    glm::vec3 up(0.0f, 1.0f, 0.0f);
    viewMatrix_ = glm::lookAt(eye, center, up);


}

//-------------------------------------------
// Chargement et compilation des données géométriques de l'application.
//-------------------------------------------
void Renderer::initGeometry()
{
    glm::mat4 theTransformation(1.0f);
    GlMaterial *defaultMaterial = new GlMaterial(glm::vec3(0.8f, 0.8f, 0.8f), glm::vec3(1.0f, 1.0f, 1.0f), 25.f);

    unsigned char white[3];
    white[0] = white[1] = white[2] = 255;
    Texture *defaultTex = new Texture(white);
    defaultMaterial->setTexture(defaultTex);



#ifdef ASDSI_TP0_G
    // Génération des surfaces paramétriques
    {
        std::vector<glm::vec3> controlMesh;
        controlMesh.push_back(glm::vec3(0.f, 0.f, 0.f));
        controlMesh.push_back(glm::vec3(0.f, 1.f, 0.f));
        controlMesh.push_back(glm::vec3(0.f, 2.f, 0.f));
        controlMesh.push_back(glm::vec3(0.f, 3.f, 0.f));
        controlMesh.push_back(glm::vec3(0.f, 4.f, 0.f));
        controlMesh.push_back(glm::vec3(0.f, 5.f, 0.f));

        controlMesh.push_back(glm::vec3(1.f, 0.f, 0.f));
        controlMesh.push_back(glm::vec3(1.f, 1.f, 1.7f));
        controlMesh.push_back(glm::vec3(1.f, 2.f, 1.f));
        controlMesh.push_back(glm::vec3(1.f, 3.f, 0.f));
        controlMesh.push_back(glm::vec3(1.f, 4.f, 0.f));
        controlMesh.push_back(glm::vec3(1.f, 5.f, 0.f));

        controlMesh.push_back(glm::vec3(2.f, 0.f, 1.f));
        controlMesh.push_back(glm::vec3(2.f, 1.f, 1.6f));
        controlMesh.push_back(glm::vec3(2.f, 2.f, 1.f));
        controlMesh.push_back(glm::vec3(2.f, 3.f, 1.f));
        controlMesh.push_back(glm::vec3(2.f, 4.f, 0.f));
        controlMesh.push_back(glm::vec3(2.f, 5.f, 0.f));

        controlMesh.push_back(glm::vec3(3.f, 0.f, 2.f));
        controlMesh.push_back(glm::vec3(3.f, 1.f, 1.4f));
        controlMesh.push_back(glm::vec3(3.f, 2.f, 2.6f));
        controlMesh.push_back(glm::vec3(3.f, 3.f, 1.f));
        controlMesh.push_back(glm::vec3(3.f, 4.f, 0.f));
        controlMesh.push_back(glm::vec3(3.f, 5.f, 0.f));

        controlMesh.push_back(glm::vec3(4.f, 0.f, 2.f));
        controlMesh.push_back(glm::vec3(4.f, 1.f, 1.4f));
        controlMesh.push_back(glm::vec3(4.f, 2.f, 1.6f));
        controlMesh.push_back(glm::vec3(4.f, 3.f, 1.f));
        controlMesh.push_back(glm::vec3(4.f, 4.f, 0.f));
        controlMesh.push_back(glm::vec3(4.f, 5.f, 0.f));

        BSplinePatch *patch = new BSplinePatch(4, 4, BSplinePatch::OpenUniform, controlMesh, 6, 5);
        ParametricMesh* paramPatch   = new ParametricBSplinePatch(patch);

        paramPatch->generateMesh(32, 32);
        GlMesh *glPatch = new GlMesh(*paramPatch);
        meshes_.push_back(glPatch);
        delete paramPatch;

        theTransformation = glm::mat4(1.0f);
        theTransformation = glm::rotate(theTransformation, -90.0f, glm::vec3(1.f, 0.f, 0.f));
        theTransformation = glm::scale(theTransformation, glm::vec3(1.f, 1.f, .5f));
        theTransformation = glm::translate(theTransformation, glm::vec3(-2.f, -2.f, -1.5f));

        GlEntity *newEntity = new GlEntity(glPatch, defaultMaterial, theTransformation);

        controlPolygon = new GLControlPolygon(theTransformation, patch);
        controlPolygon->compileGL();
        delete patch;
        entities_.push_back(newEntity);

    }
#endif


    /*

    // creation d'un repere a partir des maillage parametrique
    // build the base mesh used after for GLEntities
    ParametricMesh* plane   = new ParametricMesh();
    ParametricMesh* sphere = new ParametricSphere();
    ParametricMesh* cylinder = new ParametricCylindre();
    ParametricMesh* cone   = new ParametricCone();

    plane->generateMesh(10, 10);
    sphere->generateMesh(50,  50);
    cylinder->generateMesh(20, 10);
    cone->generateMesh(20, 10);


    GlMesh *glSphere = new GlMesh(*sphere);
    GlMesh *glPlane = new GlMesh(*plane);
    GlMesh *glCylinder = new GlMesh(*cylinder);
    GlMesh *glCone = new GlMesh(*cone);

    meshes_.push_back(glSphere);
    meshes_.push_back(glPlane);
    meshes_.push_back(glCylinder);
    meshes_.push_back(glCone);
    delete sphere;
    delete plane;
    delete cylinder;
    delete cone;

    // Construction du repère

    theTransformation = glm::scale(glm::mat4(1.0f), glm::vec3(1.f, 1.f, 1.f));

    // La sphère pour noter l'Origine
    GlMaterial *centerMaterial = new GlMaterial(glm::vec3(1.f, 1.f, 0.01f), glm::vec3(1.0f, 1.0f, 1.0f), 25.f);
    unsigned char yellow[3];
    yellow[0] = yellow[1] = 255;
    yellow[2] = 2;
    Texture *centerTex = new Texture(yellow);
    centerMaterial->setTexture(centerTex);

    glm::mat4 sphereTransformation = glm::scale(theTransformation, glm::vec3(0.1f, 0.1f, 0.1f));
    GlEntity * newEntity = new GlEntity(glSphere, centerMaterial, sphereTransformation);
    entities_.push_back(newEntity);


    // Plan sol
    {
        GlMaterial *planeMaterial = new GlMaterial(glm::vec3(0.08f, 0.08f, 1.0f), glm::vec3(1.f, 1.f, 1.f), 50.f);
        unsigned char bluegrey[3];
        bluegrey[0] = bluegrey[1] = 204;
        bluegrey[2] = 255;
        Texture *theTex = new Texture(bluegrey);
        planeMaterial->setTexture(theTex);

        glm::mat4 planeTransformation = glm::rotate(theTransformation, -90.f,  glm::vec3(1.f, 0.f, 0.f));
        planeTransformation = glm::translate(planeTransformation, glm::vec3(0.f, 0.f, -0.25f));
        planeTransformation = glm::scale(planeTransformation, glm::vec3(2.5f, 2.5f, 2.5f));
        newEntity = new GlEntity(glPlane, planeMaterial, planeTransformation);
        entities_.push_back(newEntity);
    }
    // axe Z
    {
        GlMaterial *zAxisMaterial = new GlMaterial(glm::vec3(0.01f, 0.01f, 1.0f), glm::vec3(1.f, 1.f, 1.f), 50.f);

        unsigned char blue[3];
        blue[0] = blue[1] = 2;
        blue[2] = 255;
        Texture *theTex = new Texture(blue);
        zAxisMaterial->setTexture(theTex);

        glm::mat4 cylinderTransformation = glm::scale(theTransformation, glm::vec3(0.03f, 0.03f, 0.9f));
        newEntity = new GlEntity(glCylinder, zAxisMaterial, cylinderTransformation);
        entities_.push_back(newEntity);

        glm::mat4 coneTransformation = glm::rotate(theTransformation, 180.0f, glm::vec3(0.f, 1.f, 0.f));
        coneTransformation = glm::scale(coneTransformation, glm::vec3(0.06f, 0.06f, 0.2f));
        coneTransformation = glm::translate(coneTransformation, glm::vec3(0.f, 0.f, -5.f));

        newEntity = new GlEntity(glCone, zAxisMaterial, coneTransformation);
        entities_.push_back(newEntity);
    }

    // axe X
    theTransformation = glm::rotate(theTransformation, 90.0f, glm::vec3(0.f, 1.f, 0.f));
    {
        GlMaterial *xAxisMaterial = new GlMaterial(glm::vec3(1.0f, 0.01f, 0.01f), glm::vec3(1.f, 1.f, 1.f), 50.f);

        unsigned char red[3];
        red[2] = red[1] = 2;
        red[0] = 255;
        Texture *theTex = new Texture(red);
        xAxisMaterial->setTexture(theTex);

        glm::mat4 cylinderTransformation = glm::scale(theTransformation, glm::vec3(0.03f, 0.03f, 0.9f));
        newEntity = new GlEntity(glCylinder, xAxisMaterial, cylinderTransformation);
        entities_.push_back(newEntity);

        glm::mat4 coneTransformation = glm::rotate(theTransformation, 180.0f, glm::vec3(0.f, 1.f, 0.f));
        coneTransformation = glm::scale(coneTransformation, glm::vec3(0.06f, 0.06f, 0.2f));
        coneTransformation = glm::translate(coneTransformation, glm::vec3(0.f, 0.f, -5.f));

        newEntity = new GlEntity(glCone, xAxisMaterial, coneTransformation);
        entities_.push_back(newEntity);
    }

    // axe Y
    theTransformation = glm::rotate(theTransformation, -90.0f, glm::vec3(1.f, 0.f, 0.f));
    {
        GlMaterial *yAxisMaterial = new GlMaterial(glm::vec3(0.01f, 1.f, 0.01f), glm::vec3(1.f, 1.f, 1.f), 50.f);

        unsigned char green[3];
        green[0] = green[2] = 2;
        green[1] = 255;
        Texture *theTex = new Texture(green);
        yAxisMaterial->setTexture(theTex);

        glm::mat4 cylinderTransformation = glm::scale(theTransformation, glm::vec3(0.03f, 0.03f, 0.9f));
        newEntity = new GlEntity(glCylinder, yAxisMaterial, cylinderTransformation);
        entities_.push_back(newEntity);

        glm::mat4 coneTransformation = glm::rotate(theTransformation, 180.0f, glm::vec3(0.f, 1.f, 0.f));
        coneTransformation = glm::scale(coneTransformation, glm::vec3(0.06f, 0.06f, 0.2f));
        coneTransformation = glm::translate(coneTransformation, glm::vec3(0.f, 0.f, -5.f));

        newEntity = new GlEntity(glCone, yAxisMaterial, coneTransformation);
        entities_.push_back(newEntity);

    }
    */

    /*
    // Début du code à écrire
    // 1 - Construire un vecteur (std::vector<loaders::Mesh*>) de composantes géométriques (des maillages) à partir du fichier "../data/camel.obj"
    //  Créer et utiliser un objet de type loaders::obj_mtl::ObjLoader.
    // Utiliser la méthode load() pour charger le fichier. Si une erreur est intervenue pendant le chargement, afficher cette erreur.
    // S'il n'y a pas d'erreur, utiliser la méthode getObjects() sur l'objet de type loaders::obj_mtl::ObjLoader pour récupérer l'ensemble
    // des maillages chargés dans un vecteur de type std::vector<loaders::Mesh*>
    std::vector<loaders::Mesh*> objects;
    loaders::obj_mtl::ObjLoader *loader;
    QString reason;

    loader = new loaders::obj_mtl::ObjLoader;
    if (!loader->load("../data/camel.obj", reason))
//    if (!loader->load("../data/elephant.obj", reason))
        std::cerr << "File not loaded. Reason : " << std::endl << reason.toStdString() << std::endl;
    else
        loader->getObjects(objects);

    // Définir le matériau (GlMaterial), le meme pour tous les objets du Camel
    GlMaterial *camelMaterial = new GlMaterial(glm::vec3(0.8f, 0.7f, 0.5f), glm::vec3(0.1f, 0.1f, 0.1f), 25.f);




    // 2 - Transformer ces maillages en maillages affichables (stockés dans la variable globale entities_) :
    // Pour chaque Mesh du std::vector<loaders::Mesh*>
    // Créer un GlMesh à partir de loaders::Mesh
    // Transformation
    // Créer une GlEntity avec le maillage, la transformation et le materiau.





    for (std::vector<loaders::Mesh*>::iterator it = objects.begin(); it != objects.end(); ++it) {
        GlMesh *newObject = new GlMesh(*(*it));
        meshes_.push_back(newObject);
        glm::mat4 theTransformation(1.0f);
        theTransformation = glm::translate(theTransformation, glm::vec3(0.f, 0.240f, 0.f));
        //theTransformation = glm::scale(theTransformation, glm::vec3(10.f, 10.f, 10.f));
        GlEntity * newEntity = new GlEntity(newObject, camelMaterial, theTransformation);
        entities_.push_back(newEntity);
        delete(*it);
    }

    delete loader;

    std::vector<loaders::Mesh*> trashbin;
    loader = new loaders::obj_mtl::ObjLoader;
    if (!loader->load("../data/trashbin.obj", reason))
        std::cerr << "File not loaded. Reason : " << std::endl << reason.toStdString() << std::endl;
    else
        loader->getObjects(trashbin);

    GlMaterial *trashMaterial = new GlMaterial(glm::vec3(0.6f, 0.8f, 0.8f), glm::vec3(1.0f, 1.0f, 1.0f), 25.f);
    Texture *trashTex = new Texture("../data/rustbin.jpg");
    trashTex->useMipMap(GL_NEAREST_MIPMAP_LINEAR, GL_LINEAR);
    trashMaterial->setTexture(trashTex);

    for (std::vector<loaders::Mesh*>::iterator it = trashbin.begin(); it != trashbin.end(); ++it) {
        GlMesh *newObject = new GlMesh(*(*it));
        meshes_.push_back(newObject);
        glm::mat4 theTransformation(1.f);
        theTransformation = glm::translate(theTransformation, glm::vec3(-1.f, -0.2f, .5f));
        theTransformation = glm::scale(theTransformation, glm::vec3(0.005f, 0.005f, 0.005f));


        GlEntity * newEntity = new GlEntity(newObject, trashMaterial, theTransformation);
        entities_.push_back(newEntity);
        delete(*it);
    }

    delete loader;

    */

    //Icosahedre *obj = new Icosahedre();
    Geodesique *obj = new Geodesique();
    obj->generateMesh();


    GlMesh *mesh_plane = new GlMesh(*obj);
    meshes_.push_back(mesh_plane);
    delete obj;

    GlEntity *entity = new GlEntity(mesh_plane,defaultMaterial,theTransformation);
    entities_.push_back(entity);






    // 3 - Compiler les maillage pour préparer leur affichage en openGL.
    for (std::vector<GlMesh*>::iterator it = meshes_.begin(); it != meshes_.end(); ++it) {
        (*it)->compileGL();
    }
    // Fin du code à écrire

}

//-------------------------------------------
// Chargement et compilation des shaders
//-------------------------------------------

int Renderer::initShader(std::string vsFileName, std::string fsFileName)
{

    // Les opérations devant être faites pour pouvoir utiliser des shaders OpenGL dans notre application sont les suivantes :
    // 1 - Vertex shader :
    //   1.1 - Charger le source depuis le fichier "../shaders/vertexdefault.glsl" en utilisant la fonction loaders::text::loadFile() de lecture d'un fichier texte
    char* vertexShaderSource = loaders::text::loadFile(vsFileName.c_str());
    //   1.2 - Créer un objet OpenGL VERTEX_SHADER et y associer le source
    int vertexShaderId;
    glAssert(vertexShaderId = glCreateShader(GL_VERTEX_SHADER));
    glAssert(glShaderSource(vertexShaderId, 1, (const GLchar **)&vertexShaderSource, NULL));
    //   1.3 - Compiler le shader
    glAssert(glCompileShader(vertexShaderId));
    //   1.4 - Vérifier les erreurs de compilation
    GLint compiled;
    glAssert(glGetShaderiv(vertexShaderId, GL_COMPILE_STATUS, &compiled));
    if (!compiled) {
        std::cerr << "[" << vsFileName << "] Vertex shader not compiled : " << std::endl;
        printShaderInfoLog(vertexShaderId);
        return 0;
    }

    // 2 - Fragment shader :
    //   2.1 - Charger le source depuis le fichier "../shaders/fragmentdefault.glsl" en utilisant la fonction loaders::text::loadFile() de lecture d'un fichier texte
    char *fragmentShaderSource;
    fragmentShaderSource = loaders::text::loadFile(fsFileName.c_str());
    //   2.2 - Créer un objet OpenGL FRAGMENT_SHADER et y associer le source
    int fragmentShaderId;
    glAssert(fragmentShaderId = glCreateShader(GL_FRAGMENT_SHADER));
    glAssert(glShaderSource(fragmentShaderId, 1, (const GLchar **)&fragmentShaderSource, NULL));
    //   2.3 - Compiler le shader
    glAssert(glCompileShader(fragmentShaderId));
    //   2.4 - Vérifier les erreurs de compilation
    glAssert(glGetShaderiv(fragmentShaderId, GL_COMPILE_STATUS, &compiled));
    if (!compiled) {
        std::cerr << "[" << fsFileName << "] fragment shader not compiled : " << std::endl;
        printShaderInfoLog(fragmentShaderId);
        return 0;
    }

    // 3 - Programme :
    //   3.1 - Créer un programme OpenGL, stocker son identifiant dans g_Program et y associer les shaders
    int program;
    glAssert(program = glCreateProgram());
    glAssert(glAttachShader(program, vertexShaderId));
    glAssert(glAttachShader(program, fragmentShaderId));
    //   3.2 - Fixer les positions des attributs géométriques en accord avec la classe MyGLMesh et les conventions
    //         d'écriture du source GLSL inPosition --> index 0, inNormal --> index 1 et inTexCoord --> index 2.
    glAssert(glBindAttribLocation(program, 0, "inPosition"));
    glAssert(glBindAttribLocation(program, 1, "inNormal"));
    glAssert(glBindAttribLocation(program, 2, "inTexCoord"));
    //   3.3 - Lier le programme
    glAssert(glLinkProgram(program));
    //   3.4 - Vérifier les erreurs d'édition de lien
    GLint linked;
    glAssert(glGetProgramiv(program, GL_LINK_STATUS, &linked));
    if (!linked) {
        std::cerr << "Program not linked" << std::endl;
        printProgramInfoLog(program);
    }
    return program;


}

void Renderer::initShaders()
{
    program_ = initShader("../shaders/vertexdefault.glsl", "../shaders/fragmentdefault.glsl");
    programLine_ = initShader("../shaders/vertexline.glsl", "../shaders/fragmentline.glsl");
    // Fin du code à écrire
}


//-------------------------------------------
// Fonction générale de rendu
//-------------------------------------------
void Renderer::render(const glm::mat4x4 &modelViewMatrix, const glm::mat4x4 &projectionMatrix)
{
    // Début du code à écrire
    // Fonction principale de calcul d'une image, son rôle est de séquencer l'ensemble des ordres de dessin de l'API de bas niveau.
    // 1 -  Préparer de l'image pour le rendu :
    //    1.1 - Effacer les buffers de destination
    glAssert(glClearColor(0.f, 0.3f, 0.3f, 0.f));
    glAssert(glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT));

    // 2 - Construire les matrices de vue et de projection :
    //    2.1 - Définir une matrice de projection perspective
    glm::mat4x4 localprojectionMatrix = glm::perspective(90.f, (float)width_ / (float)height_, 0.1f, 10.0f);
    //    2.2 - Définir la matrice de vue à partir de g_viewMatrix et de modelViewMatrix
    glm::mat4x4 localmodelViewMatrix = viewMatrix_;

    // 3 - Activer et paramétrer les shader par défaut :
    //    3.1 - Activer le programme par défaut
    glAssert(glUseProgram(program_));

    //    3.2 - Récupérer les adresses des paramètres
    GLint transformationLoc[4];
    glAssert(transformationLoc[0] = glGetUniformLocation(program_, "modelViewMatrix"));
    glAssert(transformationLoc[1] = glGetUniformLocation(program_, "projectionMatrix"));
    glAssert(transformationLoc[2] = glGetUniformLocation(program_, "normalMatrix"));
    glAssert(transformationLoc[3] = glGetUniformLocation(program_, "MVP"));

    GLint materialLoc[4];
    glAssert(materialLoc[0] = glGetUniformLocation(program_, "materialKd"));
    glAssert(materialLoc[1] = glGetUniformLocation(program_, "materialKs"));
    glAssert(materialLoc[2] = glGetUniformLocation(program_, "materialNs"));
    glAssert(materialLoc[3] = glGetUniformLocation(program_, "baseTexture"));

    //  3.3 - positionnez les paramètres indépendants des objets (source de lumière, ...)

    // lights Binding
    glAssert(glUniform3fv(glGetUniformLocation(program_, "keyLightPosition"), 1, glm::value_ptr(lights_[0]->getPosition())));
    glAssert(glUniform3fv(glGetUniformLocation(program_, "keyLightColor"), 1, glm::value_ptr(lights_[0]->getColor())));

    glAssert(glUniform3fv(glGetUniformLocation(program_, "fillLightPosition"), 1, glm::value_ptr(lights_[1]->getPosition())));
    glAssert(glUniform3fv(glGetUniformLocation(program_, "fillLightColor"), 1, glm::value_ptr(lights_[1]->getColor())));

    glAssert(glUniform3fv(glGetUniformLocation(program_, "backLightPosition"), 1, glm::value_ptr(lights_[2]->getPosition())));
    glAssert(glUniform3fv(glGetUniformLocation(program_, "backLightColor"), 1, glm::value_ptr(lights_[2]->getColor())));


    // 4 - Dessiner les objets de la scène :
    for (std::vector<GlEntity*>::iterator it = entities_.begin(); it != entities_.end(); ++it) {
        (*it)->drawGL(localmodelViewMatrix, localprojectionMatrix, transformationLoc, materialLoc);
    }
    // Fin du code à écrire


}

void Renderer::renderDebug(const glm::mat4x4 &modelViewMatrix, const glm::mat4x4 &projectionMatrix)
{

    glm::mat4x4 localprojectionMatrix = glm::perspective(90.f, (float)width_ / (float)height_, 0.1f, 10.0f);
    glm::mat4x4 localmodelViewMatrix = viewMatrix_;
    GLint transformationLoc[4];
    GLint colorLocation;

    glAssert(glUseProgram(programLine_));
    glAssert(transformationLoc[0] = glGetUniformLocation(programLine_, "modelViewMatrix"));
    glAssert(transformationLoc[1] = glGetUniformLocation(programLine_, "projectionMatrix"));
    glAssert(transformationLoc[2] = glGetUniformLocation(programLine_, "normalMatrix"));
    glAssert(transformationLoc[3] = glGetUniformLocation(programLine_, "MVP"));
    glAssert(colorLocation = glGetUniformLocation(programLine_, "color"));












}


int Renderer::handleKeyEvent(char key)
{

    switch (key) {
    case 'w':
        glAssert(glPolygonMode(GL_FRONT_AND_BACK, GL_LINE));
        break;
    case 'f':
        glAssert(glPolygonMode(GL_FRONT_AND_BACK, GL_FILL));
        break;

    }
    return 1;
}
int Renderer::handleMouseEvent(const MouseEvent & event)
{
    static int modifiers = 0;
    static int x = 0;
    static int y = 0;
    static int button = 0;
    static bool moved = false;

    if (event.click) {
        x = event.x;
        y = event.y;
        button = event.button;
        modifiers = event.modifiers;
    }

    if (event.button == MouseEvent::MOVE) {
        float dx = (float)(event.x - x) / (float) width_;
        float dy = (float)(event.y - y) / (float) height_;
        switch (button) {
        case MouseEvent::LEFT : {
            // Début du code à écrire
            // 1 - Récupérer les axes xvec et yvec de la caméra
            // 2 - Modifier g_viewMatrix pour y ajouter une rotation de dy*360.f degrés autour de xvec
            // 3 - Modifier viewMatrix_ pour y ajouter une rotation de dx*360.f degrés autour de yvec
            // Fin du code à écrire
            glm::vec3 xvec = glm::vec3(glm::row(viewMatrix_, 0));
            glm::vec3 yvec = glm::vec3(glm::row(viewMatrix_, 1));
            viewMatrix_ = glm::rotate(viewMatrix_, dy * 360.f, xvec);
            viewMatrix_ = glm::rotate(viewMatrix_, dx * 360.f, yvec);

        }
        break;
        case MouseEvent::RIGHT : {
            // Début du code à écrire
            // 1 - Calculer les vecteurs déplacement xvec et yvec selon les axes X et Y de la caméra
            // 2 - Modifier viewMatrix_ pour y ajouter une translation de xvec+yvec
            // Fin du code à écrire
            glm::vec3 xvec = glm::vec3(glm::row(viewMatrix_, 0)) * dx * 10.f;
            glm::vec3 yvec = glm::vec3(glm::row(viewMatrix_, 1)) * dy * 10.f;
            glm::vec3 tvec = xvec + yvec;
            viewMatrix_ = glm::translate(viewMatrix_, tvec);

        }
        break;
        case MouseEvent::MIDDLE : {
            // Début du code à écrire
            // 1 - Calculer le vecteur déplacement zvec selon l'axe Z de la caméra
            // 2 - Modifier viewMatrix_ pour y ajouter une translation de zvec
            // Fin du code à écrire
            glm::vec3 zvec = glm::vec3(glm::row(viewMatrix_, 2)) * dy * 10.f;
            viewMatrix_ = glm::translate(viewMatrix_, zvec);

        }
        break;
        }
        x = event.x;
        y = event.y;
        moved = true;
        return 1;
    } else {
        moved = false;
    }

    if (event.button == MouseEvent::WHEEL) {
        return 1;
    }

    if (!event.click) {
        button = 0;
        modifiers = 0;
    }

    return 1;
}

void Renderer::setViewport(int width, int height)
{
    width_ = width;
    height_ = height;
    glAssert(glViewport(0, 0, width_, height_));
}

void Renderer::initLighting()
{
    // Key light
    glm::vec3 keyLightPosition =  glm::vec3(0., 2.f, 0.f);
    glm::vec3 keyLightColor =  glm::vec3(0.6f, 0.7f, 0.8f); // Key light

    // Fill light
    glm::vec3 fillLightPosition =  glm::vec3(1.f, 0.5f, 0.f);
    glm::vec3 fillLightColor = 0.75f * keyLightColor;

    // Back light
    glm::vec3 backLightPosition =  glm::vec3(-1.f, .5f, -2.f);
    glm::vec3 backLightColor =  0.75f * keyLightColor; // Back light

    MyGlLight *light;
    light = new MyGlLight(keyLightPosition, keyLightColor, true);
    lights_.push_back(light);

    light = new MyGlLight(fillLightPosition, fillLightColor, true);
    lights_.push_back(light);

    light = new MyGlLight(backLightPosition, backLightColor, false);
    lights_.push_back(light);

}

} // namespace rendersystem

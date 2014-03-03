//
// General documentation and assesments

/**
   @mainpage
   @author Mathias Paulin <Mathias.Paulin@irit.fr>
  *
   @section intro_sec Introduction
   Cette documentation correspond à l'environnement de développement d'un logiciel d'informatique graphique 3D utilisé
   pour les travaux pratiques de l'UE "Introduction à l'Informatique Graphique 3D" en Master 1 informatique
   de l'université Paul Sabatier, Toulouse.
  *
  \section install_sec Installation
  Télécharger l'archive <A HREF="http://www.irit.fr/~Mathias.Paulin/M1Info/IG3D/TP/m1-ii3D">m1-iig3d.tgz</a>
  et la décompresser dans un répertoire spécifique.
  Après décompression : les répertoires suivants seront générés :
  \li \c src : Répertoire contenant les source C++ du logiciel. Certains de ces sources devront être complétés et modifiés pour la réalisation
  des travaux pratiques
  \li \c shaders : Répertoire contenant les sources GLSL des shader qui seront utilisés et modifiés pendant les TPs
  \li \c data : Répertoire contenant des fichier 3D exemples
  \li \c doc : Répertoire contenant cette documentation
 *
  \subsection dependances Dépendances
 *
  Le code fourni, écrit en C++ n'a été testé que sous Linux et mac OS X et nécessite les environnement de développement
  suivant pour être exploité :
  @li Un compilateur C++
  @li L'environement de compilation cmake (version 2.6 au moins)
  @li L'environement de développement et d'éxécution OpenGL supportant OpenGL 3.2 - core. L'installation de l'environnement de développement
  et d'éxécution OpenGL 3.2 - core n'est pas décrite ici et nécessite la disponibilité d'une carte graphique récente (dite DirectX 10),
  l'instalation d'un driver adapté et des bibliothèques de développement associée. Se référer au site
  <A HREF="http://www.opengl.org/">opengl.org</a> pour toute documentation concernant openGL.
  @li L'environnement de développement QT 4.7 au moins avec, au moins, les modules QTCore, QTGui et QTOpenGL.
  @li Bien que non nécessaire pour la réalisation des travaux pratiques, nous invitons les étudiants à installer le logiciel de création 3D Blender
  pour créer et éditer les objets et scènes qui seront visualisées par le logiciel développé en TP.
 *
  \subsection compilation Compilation
  Le système de compilation utilisé par ce code est le système <A HREF="http://www.cmake.org/">cmake</a>.
  L'ensemble des sources de ce logiciel d'infographie 3D est composé de fichiers C++ définissant l'architecture de base et placés
  dans le répertoire \c src . Le répertoire \c glm contient une bibliothèque de gestion de vecteurs et de matrices en C++,
  développée pour être utilisée avec OpenGL puisque suivant les mêmes spécification que le langage GLSL. Voir le site
  <A HREF="http://glm.g-truc.net/">glm.g-truc.net</a> pour tout renseignements sur cette bibliothèque.
 *
  Le répertoire \c fileloaders contient le code source C++ nécessaire au chargement de fichiers de données pour le logiciel. Le code de
  ce répertoire ne sera pas édité ou modifié pour les TPs mais uniquement utilisé et étendu.
 *
  Le répertoire \c rendersystem contient le code C++ principal de l'aplication. Ce code C++ est composé d'une partie IHM dévelopée
  avec QT (qui ne fera pas l'objet de modification pour les TPs) et d'une partie \c renderer correspondant au code source C++ de
  l'application qui sera développée pendant les TPs. Seuls les fichiers renderer.h et renderer.cpp devront être modifiés pendant les TPs et
  remis à l'enseignant pour évaluation des travaux.
 *
  Pour compiler le programme, nous utiliserons la possibilité offerte par cmake de compiler en dehors de l'arborescence des sources.
  Les étudiants sont libres d'utiliser l'EDI qu'ils souhaitent (QTCreator, kdevelop, ...) mais aucune assistance ne sera apportée sur
  l'utilisation d'un EDI quelconque.
  Voici la marche à suivre pour compiler votre programme :
 *
  \subsubsection compilation_premiere Première compilation
  \li Créer (la première fois) un répertoire \c build dans le répertoire d'extraction de l'archive
  <A HREF="http://www.irit.fr/~Mathias.Paulin/M1Info/IG3D/TP/minimalrenderer.tgz">minimalrenderer.tgz</a>
  (au même niveau que les répertoires \c src, \c shaders, \c data et \c doc)
  \li Dans un terminal, se positionner dans ce répertoire et taper la commande de génération des makefiles : <b>cmake ../main</b>
  \li Compiler le programme par la commande \b make

  \subsubsection compilation_toutes Toutes les autres compilations
  \li Compiler le programme par la commande \b make lancée dans le répertoire \c build

  \subsection execution Exécution
  \li Executer le programme en tapant la commande <b>./minimalRenderer</b> dans le répertoire \c bin
  (ou ../bin/minimalRenderer depuis le répertoire \c build)
 */

//-------------------------------------------

/**
   @page TP1 Scéance 1 : mise en place d'un environnement logiciel.

  L'objectif de cette séance et de comprendre et de mettre en place l'architecture générale d'une
  application de synthèse d'images 3D. Une telle application est généralement développée selon le motif de conception
  Modèle-Vue-Contrôleur

  @li Le modèle est la scène 3D et est représenté par des classes gérant les maillages, les textures, les caméra, ...
  @li La vue est implantée par un system de rendu construit au dessus des interfaces de programmation d'application de bas niveau (OpenGL ou
  DirectX).
  @li Le contrôleur est l'interface entre le système et la vue et gère les interactions avec l'utilisateur.

  Dans notre application, le modèle est écrit en C++, la vue en C++/OpenGL et le contrôleur utilise l'API Qt.
  
  Nous nous fondons sur la spécification <a href="http://www.opengl.org/registry/doc/glspec32.core.20091207.pdf">OpenGL 3.2 core</a> comme API de bas niveau. Il est recommandé de consulter cette spécification ainsi que le  <a href="http://www.opengl.org/sdk/docs/man3/">manuel de référence</a> de cette API pour bien comprendre les concepts manipulés.
 

@section managingGeometries 1 - Représentation de la géométrie pour un affichage par OpenGL.

Fichier glmesh.cpp, classe rendersystem::GlMesh.

Les données géométriques affichées par notre application sont des maillages, définis dans le code source ou chargés depuis des fichiers externes,
qui doivent être préparés pour un affichage par OpenGL.

La première étape de cette séance de travaux pratiques concerne la programmation de la classe rendersystem::GlMesh,
qui est chargée de faire ces opérations. Cette classe est déclarée (et partielement vide) dans le fichier glmesh.cpp.
rendersystem::GlMesh hérite de la classe loaders::Mesh et rajoute à la représentation des maillages les fonctionalités nécessaires pour un affichage par OpenGL.

Pour pouvoir être affiché en OpenGL, un maillage doit être représenté sous la forme d'un <b>Vertex Array Object</b>, objet abstrait
OpenGL permettant de décrire l'organisation des données du maillage en mémoire et comment y accéder. Lorsque notre maillage est ainsi
représenté, son tracé peut alors être réalisé simplement en demandat à OpenGL d'utiliser l'objet et d'en dessiner les éléments.

Deux méthodes doivent être programmées pour implanter la classe rendersystem::GlMesh :
@li rendersystem::GlMesh::compileGL()

Le rôle de cette fonction est de créer les objets OpenGL et de décrire l'organisation des données dans ces objets pour en permettre le tracé.
Nous utilisons dans notre application les notions de VertexArrayObject et de VertexBufferObject pour représenter nos maillages. Les explications concernant l'utilisation
de ces objets vous seront données en scéance. La spécification de ces concepts est sur le site <A HREF="http://www.opengl.org/">opengl.org</a>.
Se reporter aux commentaires de la fonction dans le fichier glmesh.cpp ou dans la documentation de la fonction pour avoir des indications sur la marche à suivre.

@li rendersystem::GlMesh::drawGL()

Le rôle de cette fonction est de donner les ordres OpenGL pour le dessin d'un maillage. 


<b>Avant de continuer</b>, vous devez ecrire le code de ces deux fonctions et compiler votre programme. Se reporter aux commentaires de la fonction dans le fichier glmesh.cpp ou dans la documentation de la fonction pour avoir des indications sur la marche à suivre.


@section initOpenGL 2 - Initialisation générale de l'application.

Fichier renderer.cpp, fonction rendersystem::Renderer::initRessources()

Au lancement de l'application, les différents paramètres et états du pipeline de discrétisation OpenGL
doivent être définis et initialisés. Ces états vont paramétrer le pipeline ou le contrôleur
pour permettre à l'application de réaliser ses tâches. Dans notre cas, les paramètres et états à initialiser concernent
@li le mode de rendu OPENGL_H
@li les paramètres de caméra pour la visualisation de la scène

Toute application de synthèse d'images nécessite l'utilisation de resources externes pour fonctionner.
Lors de l'initialisation de l'application, les resources dont la durée de vie est celle de l'application doivent être initialisées.
Dans le cas de notre applicaiton exemple, développée dans le cadre de ces travaux pratiques, ces resources seront :
@li le maillage à visualiser
@li les shaders pour les étages \c Vertex et \c Fragment
@li les paramètres d'apparence de l'objet à visualiser (textures, materiau, ...)


@subsection generalSttings 2.1 - Initialisation des paramètres OpenGL.

Dans notre application, nous souhaitons visualiser nos modèles sous forme de faces pleines avec élimination des parties cachées. 
 Cette initialisation est réalisée dans la fonction  rendersystem::Renderer::initRessources() les états OpenGL nécessaires.

@subsection viewSettings 2.2 - Initialisation des paramètres de vue.

La fonction rendersystem::Renderer::initView() permet de définir les paramètres par défaut pour la visualisation d'un maillage.
La matrice de vue rendersystem::Renderer::g_viewMatrix est initialisée dans la fonction rendersystem::Renderer::initView() et peut être changée si vous souhaitez un autre point de vue par défaut.

@subsection loadingGeometry 2.3 - Chargement et compilation des données géométriques de l'application.

 Cet exercice n'est pas à faire pour ce TP
 
En utilisant la classe loaders::obj_mtl::ObjLoader de chargement de fichier Alias/Wavefront OBJ,
charger l'objet  "../data/camel.obj" et stockez ses différentes composantes dans un vecteur (std::vector<loaders::Mesh*>).
Transformez ces composantes en vecteur de primitives affichables en utilisant votre classe rendersystem::MyGLMesh.

@subsection loadingShaders 2.4 - Chargement et compilation des shaders.

 Cet exercice n'est pas à faire pour ce TP

La spécification OpenGL 3.2 core nécessite la définition de \c shaders pour la gestion des
différentes données transitant dans le pipeline de discrétisation. Dans notre application, les shaders
sont définis dans des fichiers sources glsl qui doivent être chargés, compilés et liés avant de pouvoir
être utilisés pour le rendu. L'objectif de la fonction rendersystem::Renderer::initShaders() est de préparer l'application
afin qu'elle utilise par défaut les shaders "../shaders/vertexdefault.glsl" et "../shaders/fragmentdefault.glsl".
Il est à noter qu'un shader doit être vue comme une unité de compilation qui est ensuite intégrée dans un programme.

Les opérations devant être faites pour pouvoir utiliser des shaders OpenGL dans notre application sont les suivantes :
<ol>
<li> Vertex shader :
    <ol>
        <li> Charger le source depuis le fichier "../shaders/vertexdefault.glsl"
        <li> Créer un objet OpenGL VERTEX_SHADER et y associer le source
        <li> Compiler le shader
        <li> Vérifier les erreurs de compilation
    </ol>
<li> Fragment shader :
    <ol>
        <li> Charger le source depuis le fichier "../shaders/fragmentdefault.glsl"
        <li> Créer un objet OpenGL FRAGMENT_SHADER et y associer le source
        <li> Compiler le shader
        <li> Vérifier les erreurs de compilation
    </ol>
<li> Programme :
    <ol>
        <li> Créer un programme OpenGL et y associer les shaders
        <li> Fixer les positions des attributs géométriques en accord avec la classe rendersystem::MyGLMesh et les convention d'écriture
du source GLSL
        <ul>
            <li> inPosition --> index 0
            <li> inNormal --> index 1
            <li> inTexCoord --> index 2.
        </ul>
        <li> Lier le programme
        <li> Vérifier les erreurs d'édition de lien
    </ol>
</ol>

@section mainRenderfunction 3 - Fonction générale de rendu.

La fonction rendersystem::Renderer::render() est la fonction principale de calcul d'une image de synthèse. Appelée à chaque
rafraichissement de l'image son rôle est de séquencer l'ensemble des ordres de dessin de l'API de bas niveau.
Dans notre application simple, cette fonction à le rôle suivant.

<ol>
<li> Préparer de l'image pour le rendu :
    <ul>
        <li> Effacer les buffers de destination
    </ul>
<li> Construire les matrices de vue et de projection :
    <ul>
        <li> Définir une matrice de projection perspective
        <li> Définir la matrice de vue
        <li> Calculer la matrice de transformation des normales
        <li> Calculer la matrice MVP de passage du repère objet au repère image
    </ul>
<li> Activer et paramétrer les shader par defaut :
    <ul>
        <li> Activer le programme par défaut
        <li> Positionner les paramètres indépendants des objets : les matrices dans notre cas
    </ul>
<li> Dessiner les objets de la scène :
    <ul>
        <li> Dessiner tous les objets de la collection rendersystem::Renderer::entities_
    </ul>
</ol>


*/



//-------------------------------------------

/**
   @page TP2 Scéance 2 : navigation et exploration dans la scène.

   La navigation et l'exploration d'une sc!ène 3D pass par la gestion d'une métaphore abstraite de Caméra.
   Dans notre application, cette notion est simplement représentée par la matrice rendersystem::Renderer::g_viewMatrix, définissant la transformation permettant de passer du repère scène au repère camera.

   La navigation et l'exploration d'une scène correspond à la modification de cette matrice en fonction des interactions utilisateur. Ces
   interactions sont capturées par l'interface QT et transmises à la fonction rendersystem::Renderer::handleMouseEvent() que vous allez compléter afin de permettre une exploration
   simple d'un objet.

   Trois type de mouvements sont gérés par notre système initial :
   <ol>
   <li> Mouvement de type "Observe" (bouton gauche de la souris). Ce mouvement consiste à effectuer une rotation centrée de la scène autour des axes X et Y de la caméra </li>
   <li> Mouvement de type "Pan"  (bouton droit de la souris). Ce mouvement consiste à effectuer une translation de la scène dans le plain (X, Y) de la caméra </li>
   <li> Mouvement de type "Zoom" (bouton central de la souris). Ce mouvement consiste à réaliser une translation de la scène selon l'axe Z de la caméra </li>
   </ol>
   La matrice rendersystem::Renderer::g_viewMatrix a été initialisée dans l'exercice @ref viewSettings et défini les proriétés de la caméra. Afin de pouvoir réaliser
   les transformation, il faut récupérer les axes X, Y et Z du repère de cette caméra. Les rotations et les translations seront réalisées en
   fonction des valeurs des variables @c dx et @c dy
   contenant le déplacement normalisé de la souris dans le repère de l'image.


*/

//-------------------------------------------

/**
   @page TP3 Scéance 3 : génération procédurale de maillage.

Le sujet de cette séance est disponible dans ce <a href="../../sujetTP3.pdf">document</a>

*/

//-------------------------------------------

/**
   @page DV1 Devoir 1 : construction d'une sphère géodésique.

   L'objectif de ce devoir est de programmer et d'ajouter à la liste des objets que l'on peut visualiser dans notre
application un solide Platonique, l'icosahèdre et d'utiliser ce solide comme élément de base pour la construction d'une sphère géodésique.

Dans ce devoir programmerez 2 classes, Icosahèdre et Geodesique permettant de construire un icosahedre selon la définition de ce solide accessible
<A HREF="http://fr.wikipedia.org/wiki/Icosa%C3%A8dre">ici</a>.
La sphère géodésique sera obtenue en divisant récursivement jusqu'à un niveau N les faces de l'icosahèdre et en projettant les sommets sur la sphère.


*/

//-------------------------------------------

/**
   @page TP4 Scéance 4 : calcul de l'éclairage.

Lors de cette scéance, nous allons programmer, à l'aide des <i>shaders</i>, le calcul de l'éclairage d'une scène.

Tout d'abord, récupérer <a href="../../corrigeTP1a3.tgz">ici</a> le corrigé des 3 premières scéances de TP, corrigé étendu afin de préparer le
calcul de l'éclairage. Les fichiers renderer.cpp renderer.h doivent remplacer les anciens fichiers dans le
répertoire src/rendersystem, les fichiers vertexdefault.glsl et fragmentdefault.glsl doivent remplacer
les anciens fichiers dans le répertoire shaders.
Nous vous encourageons à regarder de près les modifications qui ont été faites, principalement l'introduction
des classes rendersystem::MyGLMaterial et rendersystem::MyGlEntity.

Dans la nouvelle mouture de notre moteur minimal, le Renderer dessine une liste d'entités (instances de la
classe rendersystem::MyGlEntity). Une entité Correspond à un maillage, auquel est associé une apparence (un matériau
défini par la classe rendersystem::MyGLMaterial) et une transformation géométrique pour la disposer dans la scène.
Ainsi, il est possible de construire des scènes complexes simplement, en plaçant différents objets 3D dans
l'espace.

Afin de mieux apréhender le principe de composition de scène, étudier, dans la méthode rendersystem::Renderer::initGeometry()
comment est créé le repère OXYZ de la scène.

L'objectif de cette séance de TP est d'implanter, dans les shader, le calcul de l'éclairage par le modèle
de Blinn-Phong. Ce modèle repose sur le calcul et la combinaison de deux types de réflexions de la lumière :
une réflexion diffuse, proportionelle au cosinus de l'angle entre la normale à la surface et la direction de
lumière, et une reflexion spéculaire, proportionelle au cosinus de l'angle entre la normale et la bissectrice des
directions de vue et d'éclairage.

Dans ce modèle d'éclairage, les matériaux sont définis par trois propriétés : la couleur de base de l'objet,
contrôlant la réflexion diffuse et notée <b>materialKd</b>, la couleur de la reflexion spéculaire, notée
<b>materialKs</b>, et la rugosité de la réflexion spéculaire, notée <b>materialNs</b>.

En un point \f$X\f$, de normale \f$\overrightarrow{N}\f$, vu depuis la position \f$O\f$ et éclairé depuis
la position \f$S\f$, la couleur se calcule de la manière suivante :

<ol>
 <li>Calcul de la direction de vue \f$\overrightarrow{V} = \frac{\overrightarrow{XO}}{|\overrightarrow{XO}|}\f$</li>
 <li>Calcul de la direction de d'éclairage \f$\overrightarrow{L} = \frac{\overrightarrow{XS}}{|\overrightarrow{XS}|}\f$</li>
 <li>Calcul de la bissectrice \f$\overrightarrow{H} = \frac{\overrightarrow{V}+\overrightarrow{L}}{|\overrightarrow{V}+\overrightarrow{L}|}\f$</li>
 <li>Calcul de \f$cosTheta = \overrightarrow{N}.\overrightarrow{L}\f$ et de \f$cosAlpha = \overrightarrow{N}.\overrightarrow{H}\f$
 <li>Calcul de la couleur : \f$Color = \left( materialKd + materialKs \times cosAlpha^{materialNs}\right) \times cosTheta\f$
</ol>


A la fin de cette séance de travaux pratiques, vos shaders sauront exploiter les paramètres d'éclairage définis par la
méthode rendersystem::Renderer::render() et correspondant à un éclairage photographique 3 points (Key, Fill, Back)
utilisé en studio photo ou en extérieur. Nous laissons les étudiants se renseigner sur cette technique d'éclairage
qui fera l'objet de devoir numéro 2. Nous attirons l'attention que ni les positions des sources, ni leur couleurs sont
correctement positionnées pour le moment mais que l'on pourra observer, en fin de séance, les avantages de cette technique
d'éclairage.

\section sujet Travail à réaliser

\subsection bootstrap Mise en place des fonctions

Dans un premier temps, nous allons programmer, dans les shaders, le calcul de l'éclairage pour une source de type headlight,
dont la position est, dans le repère de vue, \f$(0.0, 0.0, 0.0)\f$ et dont la couleur est \f$(1.0, 1.0, 1.0)\f$

Les opérations de calcul vont être séparées en deux groupes, un groupe calculée dans le vertex shader, l'autre calculé dans le
fragment shader. Ce découpage est lié aux données manipulées lors des différents calcul.

Les opérations 1, 2 et 3 de l'algorithme de calcul décrit ci-dessus vont être programmées dans le vertex shader.
En effet, ces opérations reposent sur une données liée au sommet : sa position.
Dans le fichier vertexdefault.glsl, programmez en GLSL la fonction
\verbatim
void computeLightingVectorsInView(in vec3 posInView, in vec3 lightPosition, out vec3 lightDir, out vec3 halfVec)
\endverbatim

qui, à partir des positions du sommet <i>posInView</i> et de la source de lumière <i>lightPosition</i>, toutes deux
exprimées dans le repère de la vue, calcule les
vecteur <i>lightDir</i> et <i>halfVec</i> représentant la direction d'éclairage et la bissectrice.

Dans la fonction main, calculer dans les paramètres en sortie <i>lightDirInView[0]</i> et <i>halfVecInView[0]</i>
les informations pour une source headlight.


Les opérations 4 et 5 vont êtres programmées dans le fragment shaders puisqu'elle calculent la couleur du fragment.
Elles seront calculées à partir des informations calculées par sommet et interpolées par le rasterizer sur chaque fragment.
Dans un premier temps, on n'utilisera que les informations <i>lightDirInView[0]</i> et <i>halfVecInView[0]</i>.
Dans le fichier fragmentdefault.glsl, programmez en GLSL la fonction
\verbatim
vec3 blinnPhongLighting (in vec3 kd, in vec3 ks, in float ns, in vec3 normal, in vec3 lightVector, in vec3 halfVector)
\endverbatim
qui, à partir des données de matériau <i>kd</i>, <i>ks</i> et <i>ns</i>, des données géométriques <i>normal</i>,
<i>lightVector</i> et <i>halfVector</i> calcule la couleur d'un point.
Dans la fonction maindu fragment shader, calculer la couleur du fragment en utilisant votre fonction <i>blinnPhongLighting</i>.

Observer sur les images que vous obtenez les contributions individuelles des différentes composantes du modèle d'éclairage

\subsection light Eclairage 3 points : Key, Fill, Back
En utilisant les paramètres et variables uniformes définies dans les shaders et positionnées par le renderer, mettez en place l'éclairage 3 points de notre chameau.


*/

// Light sources : 3 sources
// Key light
// Position, puissance et couleur détermine l'amboiance principale de l'éclairage
// ex : soleil pour scènes extérieures, flash pour scènes interieures
//
// Fill light
// Corrige les défauts engendrés par key light: ombres portées trop fortes, parties sombres , ...
// Position : sur le coté par rapport à la fill light, moins haute (au niveau de la face du sujet)
// Puissance : 2 fois moins importante que la key light.
// Couleur : plus douce que la key light.
//
// Back light
// Permet de mettre en évidence les contours de l'objet et de le détacher de l'arrière plan.
//

//-------------------------------------------

/**
   @page TP5 Scéance 5 : textures pour le contrôle de l'apparence.
	sujet à venir ...
*/

//-------------------------------------------

/**
   @page TP6 Scéance 6 : subdivision de Loop.
	sujet à venir ...

*/

//-------------------------------------------

/**
   @page DV2 Devoir 2 : sujet à venir ...

*/

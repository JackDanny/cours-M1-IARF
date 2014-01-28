#version 150
/*
 * Paramètres généraux
 */
// Matrices
uniform mat4 modelViewMatrix;
uniform mat4 projectionMatrix;
uniform mat4 MVP;
uniform mat4 normalMatrix;

// Position des sources
uniform vec3 keyLightPosition;
uniform vec3 fillLightPosition;
uniform vec3 backLightPosition;

/*
 * Données en entrée
 */
in vec3 inPosition;
in vec3 inNormal;
in vec4 inTexCoord;

/*
 * Données en sortie
 */
// Sommet
out vec3 varNormal;
out vec4 varTexCoord;

// Eclairage
out vec3 lightDirInView[3];
out vec3 halfVecInView[3];


void main(void) {
   varNormal = inNormal;
    gl_Position = MVP*vec4(inPosition.xyz, 1.0);
}

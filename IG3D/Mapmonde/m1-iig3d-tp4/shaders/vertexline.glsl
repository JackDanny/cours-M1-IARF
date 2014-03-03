#version 150
/*
 * Paramètres généraux
 */
// Matrices
uniform mat4 modelViewMatrix;
uniform mat4 projectionMatrix;
uniform mat4 MVP;
uniform mat4 normalMatrix;

/*
 * Données en entrée
 */
in vec3 inPosition;

/*
 * Données en sortie
 */

void main(void) {
    gl_Position = MVP*vec4(inPosition.xyz, 1.0);
}

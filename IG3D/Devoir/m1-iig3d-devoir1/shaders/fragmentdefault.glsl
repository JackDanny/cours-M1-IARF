#version 150
const float globalColorFactor = 0.75;

// material
uniform vec3 materialKd;
uniform vec3 materialKs;
uniform float materialNs;

// texture
uniform sampler2D baseTexture;

// fragment
in vec3 varNormal;
in vec4 varTexCoord;

// lumieres
in vec3 lightDirInView[3];
in vec3 halfVecInView[3];

// material
uniform vec3 keyLightColor;
uniform vec3 fillLightColor;
uniform vec3 backLightColor;

// resultat
out vec4 outColor;


void main(void) {
        outColor = vec4(varNormal, 1);
}


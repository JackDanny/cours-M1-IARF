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

vec3 blinnPhongLighting (in vec3 kd, in vec3 ks, in float ns, in vec3 normal, in vec3 lightVector, in vec3 halfVector){
    lightVector = normalize(lightVector);
    halfVector = normalize(halfVector);

    float puiss=pow(dot(normal,halfVector),ns);
    float cosTheta=dot(normal,lightVector);

    vec3 color=(kd+(ks*(puiss)))*cosTheta;

    return color;
}

void main(void) {
    outColor = vec4(varNormal, 1);


    //vec3 normal= vec3 varNormal* vec4(modelViewMatrix);

    //outColor[1] = blinnPhongLighting (materialKd, materialKs, materialNs, varNormal, lightDirInView[1], halfVecInView[1]);
   /*
    vec3 phongres[3];

    phongres[0]=blinnPhongLighting (materialKd, materialKs, materialNs, varNormal, lightDirInView[0], halfVecInView[0]);
    phongres[1]=blinnPhongLighting (materialKd, materialKs, materialNs, varNormal, lightDirInView[1], halfVecInView[1]);
    phongres[2]=blinnPhongLighting (materialKd, materialKs, materialNs, varNormal, lightDirInView[2], halfVecInView[2]);
    //fillLightColor = blinnPhongLighting (materialKd, materialKs, materialNs, varNormal, lightDirInView[1], halfVecInView[1]);
    //backLightColor = blinnPhongLighting (materialKd, materialKs, materialNs, varNormal, lightDirInView[1], halfVecInView[1]);
    phongres[0]= phongres[0]*keyLightColor;
    phongres[1]= phongres[1]*fillLightColor;
    phongres[2]= phongres[2]*backLightColor;

    outColor = vec4( (phongres[0]+phongres[1]+phongres[2]) * globalColorFactor ,1.);
    */

//    outColor = vec4( varNormal , 1.);
}




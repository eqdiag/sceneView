#version 330 core

in vec3 Position;
in vec3 Normal;

out vec4 outColor;

//Eye
uniform vec3 eye;

//phong material colors
uniform vec3 emissive;
uniform vec3 ambient;
uniform vec3 diffuse;
uniform vec3 specular;

//light properties
uniform vec4 lightPosition;
uniform vec3 lightColor;
uniform float shininess;


void main()
{
	vec3 lightDir = normalize(lightPosition.xyz - Position.xyz*lightPosition.w);
	vec3 viewVec = normalize(eye - Position);
	vec3 halfVec = normalize(viewVec + lightDir);

	float diffuseAmt = max(0.0,dot(Normal,lightDir));
	float specAmt = max(0.0,pow(dot(Normal,halfVec),shininess));
	
	vec3 color = emissive + lightColor*(ambient + diffuse*diffuseAmt + specAmt*specular);
	outColor = vec4(color,1.0);
}
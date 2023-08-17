#version 330 core

in vec3 Position;
in vec3 Normal;

out vec4 outColor;


void main()
{
	vec3 normalColor = (Normal + vec3(1.0))*0.5;
	outColor = vec4(normalColor,1.0);
}
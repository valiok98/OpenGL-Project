#version 430

layout(location = 0) in vec3 position;
layout(location = 1) in vec3 colors;
layout(location = 2) in mat4 fullMatrix;


out vec3 outputColors;

void main() {


	vec4 expand = vec4(position, 1.0);
	gl_Position = fullMatrix * expand;;
	outputColors = colors;

}
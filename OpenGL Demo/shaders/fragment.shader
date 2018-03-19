#version 430

in vec3 outputColors;

out vec4 colorss;


void main() {

	colorss = vec4(outputColors, 1.0);

}
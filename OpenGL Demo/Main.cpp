#include<GL\glew.h>
#include<GLFW\glfw3.h>
#include<iostream>
#include<glm\glm.hpp>
#include<glm\gtc\matrix_transform.hpp>
#include "utils\Source.h"
#include "utils\readFiles.h"

unsigned int program;

struct tocast {

	glm::vec3 postions;
	glm::vec3 colors;

};
bool check_shader(unsigned int shaderId);
void loadShaders();
void MessageCallback(GLenum source,
	GLenum type,
	GLuint id,
	GLenum severity,
	GLsizei length,
	const GLchar* message,
	const void* userParam);

int main() {
	
	if (!glfwInit()) {

		std::cout << "Could not initialize GLFW ! " << std::endl;
		glfwTerminate();
		return 1;

	}

	GLFWwindow* window;
	window = glfwCreateWindow(1200, 1000, "Hello window", NULL, NULL);

	if (!window) {
		
		std::cout << "Could not initialize a window " << std::endl;
		glfwTerminate();
		return 1;

	}

	glfwMakeContextCurrent(window);
	int width, height;
	glfwGetWindowSize(window, &width, &height);
	if (glewInit() != GLEW_OK) {

		std::cout << "Could not initialize GLEW " << std::endl;
		glfwTerminate();
		return 1;

	}

	Data generated;
	generated.makeCube();


	float arr[] = {

		-1.0f,-1.0f,-1.0f,
		1.0f,-1.0f,-1.0f,
		0.0f,1.0f, - 1.0f

	};



	unsigned int vbo;
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, generated.getVectorSize(), generated.getVector(), GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 6, 0);
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 6, (char*)(sizeof(float) * 3));




	unsigned int ibo;
	glGenBuffers(1, &ibo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, generated.getIndexBufferSize(), generated.getindexBuffer(), GL_STATIC_DRAW);


	int getTranslationUniformLocation = glGetUniformLocation(program, "fullMatrix");
	
	glm::mat4 projection = glm::perspective(60.0f, ((float)width) / height, 0.1f, 10.0f);

	glm::mat4 matrixSource[] = {

		projection * glm::translate(glm::mat4(), glm::vec3(-1.0f, 0.0f, -1.6f)) * glm::rotate(glm::mat4(), 36.0f, glm::vec3(1.0f, 0.0f, 0.0f)),
		projection * glm::translate(glm::mat4(), glm::vec3(1.0f, 0.0f, -1.75f)) * glm::rotate(glm::mat4(), 126.0f, glm::vec3(0.0f,1.0f,0.0f))
	};


	unsigned int instanced;
	glGenBuffers(1, &instanced);
	glBindBuffer(GL_ARRAY_BUFFER, instanced);
	glBufferData(GL_ARRAY_BUFFER, sizeof(matrixSource), matrixSource, GL_STATIC_DRAW);
	glVertexAttribPointer(2, 4, GL_FLOAT, GL_FALSE, sizeof(glm::mat4), (void*)(sizeof(float) * 0));
	glVertexAttribPointer(3, 4, GL_FLOAT, GL_FALSE, sizeof(glm::mat4), (void*)(sizeof(float) * 4));
	glVertexAttribPointer(4, 4, GL_FLOAT, GL_FALSE, sizeof(glm::mat4), (void*)(sizeof(float) * 8));
	glVertexAttribPointer(5, 4, GL_FLOAT, GL_FALSE, sizeof(glm::mat4), (void*)(sizeof(float) * 12));
	glEnableVertexAttribArray(2);
	glEnableVertexAttribArray(3);
	glEnableVertexAttribArray(4);
	glEnableVertexAttribArray(5);
	glVertexAttribDivisor(2, 1);
	glVertexAttribDivisor(3, 1);
	glVertexAttribDivisor(4, 1);
	glVertexAttribDivisor(5, 1);


	glClearColor(0.1, 0.1, 0.1, 1.0);

	glEnable(GL_DEPTH_TEST);

	loadShaders();

	while (!glfwWindowShouldClose(window)) {

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glfwGetWindowSize(window, &width, &height);
		glViewport(0, 0, width, height);
		//glDrawArrays(GL_TRIANGLES, 0, generated.getIndexBufferSize());
		glDrawElementsInstanced(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0,2);

	
		glfwSwapBuffers(window);


		//glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, generated.getindexBuffer());

		glfwPollEvents();

	}


	return 0;
}
void loadShaders() {

	///Shaders
	std::string ans1 = readFile("shaders\\vertex.shader");
	std::string ans2 = readFile("shaders\\fragment.shader");


	std::cout << ans1 << std::endl;
	std::cout << ans2 << std::endl;


	unsigned int vertexShaderId = glCreateShader(GL_VERTEX_SHADER);
	unsigned int fragmentShaderId = glCreateShader(GL_FRAGMENT_SHADER);



	const GLchar* arr;
	arr = ans1.c_str();
	glShaderSource(vertexShaderId, 1, &arr, 0);
	glCompileShader(vertexShaderId);
	arr = ans2.c_str();
	glShaderSource(fragmentShaderId, 1, &arr, 0);


	glCompileShader(fragmentShaderId);


	

	program = glCreateProgram();

	glAttachShader(program, vertexShaderId);
	glAttachShader(program, fragmentShaderId);

	glLinkProgram(program);
	glValidateProgram(program);


	if (check_shader(vertexShaderId) == false)
		std::cout << "error in vertexshader" << std::endl;
	if(check_shader(fragmentShaderId) == false)
		std::cout << "error in fragmentshader" << std::endl;



	glDeleteShader(vertexShaderId);
	glDeleteShader(fragmentShaderId);


	glUseProgram(program);

	std::cout << "success" << std::endl;
}
void MessageCallback(GLenum source,
	GLenum type,
	GLuint id,
	GLenum severity,
	GLsizei length,
	const GLchar* message,
	const void* userParam)
{
	fprintf(stderr, "GL CALLBACK: %s type = 0x%x, severity = 0x%x, message = %s\n",
		(type == GL_DEBUG_TYPE_ERROR ? "** GL ERROR **" : ""),
		type, severity, message);
}

// During init, enable debug output

bool check_shader(unsigned int shaderId) {


	int compileStatus;
	glGetShaderiv(shaderId, GL_COMPILE_STATUS, &compileStatus);
	if (compileStatus != GL_TRUE) {
		int infoLoglen;
		glGetShaderiv(shaderId, GL_INFO_LOG_LENGTH, &infoLoglen);
		char* buffer = new char[infoLoglen];

		glGetShaderInfoLog(shaderId, infoLoglen, &infoLoglen, buffer);
		std::cout << buffer << std::endl;
		delete[] buffer;
		return false;
	}
	return true;
}

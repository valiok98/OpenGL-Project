#include "Source.h"


Data::Data() {
	
	myInfo = nullptr;
	indexBuffer = nullptr;

	genData();
}

Data::~Data() {

	delete[] myInfo;
	delete[] indexBuffer;

}

void Data::makeCube(){

	form = true;

	genData();

}

void Data::makeTriangle() {

	form = false;

	genData();

}

void Data::genData() {


	vectorInfo cube_tmp[] = {
		glm::vec3(-1.0f, +1.0f, +1.0f), // 0
		glm::vec3(+1.0f, +0.0f, +0.0f), // Colour
		glm::vec3(+1.0f, +1.0f, +1.0f), // 1
		glm::vec3(+0.0f, +1.0f, +0.0f), // Colour
		glm::vec3(+1.0f, +1.0f, -1.0f), // 2
		glm::vec3(+0.0f, +0.0f, +1.0f), // Colour
		glm::vec3(-1.0f, +1.0f, -1.0f), // 3
		glm::vec3(+1.0f, +1.0f, +1.0f), // Colour

		glm::vec3(-1.0f, +1.0f, -1.0f), // 4
		glm::vec3(+1.0f, +0.0f, +1.0f), // Colour
		glm::vec3(+1.0f, +1.0f, -1.0f), // 5
		glm::vec3(+0.0f, +0.5f, +0.2f), // Colour
		glm::vec3(+1.0f, -1.0f, -1.0f), // 6
		glm::vec3(+0.8f, +0.6f, +0.4f), // Colour
		glm::vec3(-1.0f, -1.0f, -1.0f), // 7
		glm::vec3(+0.3f, +1.0f, +0.5f), // Colour

		glm::vec3(+1.0f, +1.0f, -1.0f), // 8
		glm::vec3(+0.2f, +0.5f, +0.2f), // Colour
		glm::vec3(+1.0f, +1.0f, +1.0f), // 9
		glm::vec3(+0.9f, +0.3f, +0.7f), // Colour
		glm::vec3(+1.0f, -1.0f, +1.0f), // 10
		glm::vec3(+0.3f, +0.7f, +0.5f), // Colour
		glm::vec3(+1.0f, -1.0f, -1.0f), // 11
		glm::vec3(+0.5f, +0.7f, +0.5f), // Colour

		glm::vec3(-1.0f, +1.0f, +1.0f), // 12
		glm::vec3(+0.7f, +0.8f, +0.2f), // Colour
		glm::vec3(-1.0f, +1.0f, -1.0f), // 13
		glm::vec3(+0.5f, +0.7f, +0.3f), // Colour
		glm::vec3(-1.0f, -1.0f, -1.0f), // 14
		glm::vec3(+0.4f, +0.7f, +0.7f), // Colour
		glm::vec3(-1.0f, -1.0f, -1.0f), // 15
		glm::vec3(+0.2f, +0.5f, +1.0f), // Colour

		glm::vec3(+1.0f, +1.0f, +1.0f), // 16
		glm::vec3(+0.6f, +1.0f, +0.7f), // Colour
		glm::vec3(-1.0f, +1.0f, +1.0f), // 17
		glm::vec3(+0.6f, +0.4f, +0.8f), // Colour
		glm::vec3(-1.0f, -1.0f, +1.0f), // 18
		glm::vec3(+0.2f, +0.8f, +0.7f), // Colour
		glm::vec3(+1.0f, -1.0f, +1.0f), // 19
		glm::vec3(+0.2f, +0.7f, +1.0f), // Colour

		glm::vec3(+1.0f, -1.0f, -1.0f), // 20
		glm::vec3(+0.8f, +0.3f, +0.7f), // Colour
		glm::vec3(-1.0f, -1.0f, -1.0f), // 21
		glm::vec3(+0.8f, +0.9f, +0.5f), // Colour
		glm::vec3(-1.0f, -1.0f, +1.0f), // 22
		glm::vec3(+0.5f, +0.8f, +0.5f), // Colour
		glm::vec3(+1.0f, -1.0f, +1.0f), // 23
		glm::vec3(+0.9f, +1.0f, +0.2f), // Colour
	};

	unsigned int cube_buffer[] = {
		0,  1,  2,  0,  2,  3, // Top
		4,  5,  6,  4,  6,  7, // Front
		8,  9, 10,  8, 10, 11, // Right
		12, 13, 14, 12, 14, 15, // Left
		16, 17, 18, 16, 18, 19, // Back
		20, 22, 21, 20, 23, 22, // Bottom
	};



	vectorInfo cube[] = {

		glm::vec3(-1.0f,-1.0f,-1.0f),
		glm::vec3(0.5f,0.3f,0.7f),
		glm::vec3(-1.0f, -1.0f,1.0f),
		glm::vec3(0.5f,0.3f,0.7f),
		glm::vec3(-1.0f, 1.0f,-1.0f),
		glm::vec3(0.5f,0.3f,0.7f),
		glm::vec3(-1.0f, 1.0f,1.0f),
		glm::vec3(0.5f,0.3f,0.7f),
		glm::vec3(1.0f, -1.0f,-1.0f),
		glm::vec3(0.5f,0.3f,0.7f),
		glm::vec3(1.0f, -1.0f,1.0f),
		glm::vec3(0.5f,0.3f,0.7f),
		glm::vec3(1.0f, 1.0f,-1.0f),
		glm::vec3(0.5f,0.3f,0.7f),
		glm::vec3(1.0f, 1.0f,1.0f),
		glm::vec3(0.5f,0.3f,0.7f)
		
		


	};

	vectorInfo triangle [] = {

		glm::vec3(-1.0,-1.0,-1.0),
		glm::vec3(0.5f,0.4f,0.1f),
		glm::vec3(1.0,-1.0,-1.0),
		glm::vec3(0.5f,0.4f,0.1f),
		glm::vec3(0.0,0.0,-1.0),
		glm::vec3(0.5f,0.4f,0.1f)

	};

	unsigned int indexCube[] = {

		0,4,6, 6,4,5,
		6,5,7, 0,4,5,
		0,1,5, 1,5,7,

		7,1,3, 3,7,6,
		6,3,2, 2,3,1,
		1,2,0, 0,2,6

	};

	unsigned int indexTriangle[] = {

		0,1,2 

	
	};

	


	vecSize = form ? sizeof(cube_tmp) : sizeof(triangle);

	indSize = form ? sizeof(cube_buffer) : sizeof(indexTriangle);
	
	indexBuffer = form ? new unsigned int[sizeof(cube_buffer)] : new unsigned int[sizeof(indexTriangle)];
	
	myInfo = form ? new vectorInfo[sizeof(cube_tmp)] : new vectorInfo[sizeof(triangle)];

	form ? memcpy(myInfo, cube_tmp, sizeof(cube_tmp)) : memcpy(myInfo, triangle, sizeof(triangle));

	form ? memcpy(indexBuffer, cube_buffer, sizeof(cube_buffer)) : memcpy(indexBuffer, indexTriangle, sizeof(indexTriangle));


}
vectorInfo* Data::getVector() {

	return myInfo;

}
unsigned int* Data::getindexBuffer() {

	return indexBuffer;

}
unsigned int Data::getVectorSize() {

	return vecSize;

}
unsigned int Data::getIndexBufferSize() {

	return indSize;
}


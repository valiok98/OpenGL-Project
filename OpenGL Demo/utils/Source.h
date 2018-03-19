#pragma once
#include<glm\glm.hpp>

struct vectorInfo {

	glm::vec3 positions;
	glm::vec3 colors;

};
class Data {

	vectorInfo* myInfo;
	unsigned int* indexBuffer;
	void genData();
	bool form;
	unsigned int vecSize;
	unsigned int indSize;

public:

	Data();
	~Data();
	void makeTriangle();
	void makeCube();
	vectorInfo* getVector();
	unsigned int* getindexBuffer();
	unsigned int getVectorSize();
	unsigned int getIndexBufferSize();



};




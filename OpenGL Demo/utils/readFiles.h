#pragma once
#include<fstream>
#include<string>

static std::string readFile(const char* filepath) {

	std::ifstream file(filepath);
	
	std::string content(
		std::istreambuf_iterator<char>(file.rdbuf()),
		std::istreambuf_iterator<char>()
	);

	return content;

}

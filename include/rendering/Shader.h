#pragma once
#include <glad/glad.h>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include "GLM/matrix.hpp"


class Shader
{
public:
	unsigned int ID;
	Shader(const std::string &vertexPath, const std::string &fragmentPath);
	void use();
	void setBool(const std::string& name, bool value) const;
	void setInt(const std::string& name, int value) const;
	void setFloat(const std::string& name, float value) const;
	void setMat4(const std::string& name, glm::mat4) const;
	void setVec3(const std::string& name, float x, float y, float z) const;
	void setVec3(const std::string& name, const glm::vec3& value) const;
};

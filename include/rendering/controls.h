#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/common.hpp>
#include <glm/matrix.hpp>
#include <glm/ext/matrix_clip_space.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <iostream>

class Controls {
public:
	Controls(GLFWwindow &win);
	glm::vec3 getViewDirection();
	glm::vec3 getPosition();
	glm::vec3 getRightVector();
	glm::vec3 getUpVector();
	glm::vec3 getForwardVector();
	float getDeltaTime();
	float getFoV();
	glm::mat4 getProjectionMatrix();
	glm::mat4 getViewMatrix();
	void updateInputs();
private:
	GLFWwindow* window;
	glm::vec3 position, direction, right, up, forward;
	float horizontalAngle;
	float verticalAngle;
	float initialFoV;
	float speed;
	float mouseSpeed;
	float deltaTime;
	float lastTime;
	float FoV;
	float FoVchange;
};

glm::mat4 computeMVP(GLFWwindow& win, Controls& inputControls);

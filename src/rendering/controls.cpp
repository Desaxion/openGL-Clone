#include <rendering/controls.h>

float Controls::getDeltaTime()
{
	
	float currentTime = float(glfwGetTime());
	deltaTime = float(currentTime - lastTime);
	lastTime = currentTime;
	return deltaTime;
}

float Controls::getFoV()
{
	if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS) {
		FoV += FoVchange;
	}
	if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS) {
		FoV-= FoVchange;
	}
	return FoV;
}

glm::mat4 Controls::getProjectionMatrix()
{
	getFoV();
	return glm::perspective(glm::radians(FoV), 4.0f / 3.0f, 0.1f, 100.0f);
}

glm::mat4 Controls::getViewMatrix()
{
	//getPosition();
	getViewDirection();
	return glm::lookAt(position, position+direction, up);
}

void Controls::updateInputs()
{
	getDeltaTime();
	getRightVector();
	getViewDirection();
	getForwardVector();
	getPosition();
	getUpVector();
	getFoV();
}

Controls::Controls(GLFWwindow& win) : window{ &win }, lastTime{ 0 }, position{ glm::vec3(0, 0, 5) }, FoVchange{ 0.5f }, direction{ glm::vec3(0,0,0) }, forward{ glm::vec3(0,0,0) }, right{ glm::vec3(0,0,0) }, up{ glm::vec3(0,0,0) }, horizontalAngle{ 3.14f }, verticalAngle{ 0.0f }, initialFoV{ 45.0f }, speed{ 6.0f }, mouseSpeed{ 0.002f }, deltaTime{ 0.0f }, FoV{ 45.0f }
{
}

glm::vec3 Controls::getViewDirection()
{
	double xpos, ypos;
	int width, height;

	glfwGetWindowSize(window, &width, &height);
	glfwGetCursorPos(window, &xpos, &ypos);
	
	glfwSetCursorPos(window, width / 2, height / 2);

	horizontalAngle += mouseSpeed * float(width / 2 - xpos);
	verticalAngle += mouseSpeed * float(height / 2 - ypos);
	
	direction = glm::vec3(
		cos(verticalAngle)*sin(horizontalAngle),
		sin(verticalAngle),
		cos(verticalAngle) * cos(horizontalAngle));
	
	return direction;
}

glm::vec3 Controls::getPosition()
{
	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) {
		position += glm::vec3(direction.x, 0 , direction.z) * deltaTime * speed;
	}
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) {
		position -= glm::vec3(direction.x, 0, direction.z) * deltaTime * speed;
	}
	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) {
		position += right * deltaTime * speed;
	}
	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) {
		position -= right * deltaTime * speed;
	}
	if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS) {
		position += up * deltaTime * speed;
	}
	if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS) {
		position -= up * deltaTime * speed;
	}
	return position;
}

glm::vec3 Controls::getRightVector()
{
	right = glm::vec3(
		sin(horizontalAngle - 3.14f / 2.0f),
		0,
		cos(horizontalAngle - 3.14f / 2.0f));
	return right;
}

glm::vec3 Controls::getUpVector()
{
	up = glm::cross(right, direction);
	return up;
}

glm::vec3 Controls::getForwardVector()
{
	forward = glm::vec3(direction.x, 0, direction.z);
	return forward;
}

glm::mat4 computeMVP(GLFWwindow& win, Controls& inputControls)
{
	inputControls.updateInputs();
	glm::mat4 V = inputControls.getViewMatrix();
	glm::mat4 P = inputControls.getProjectionMatrix();
	glm::mat4 M = glm::mat4(1.0);
	glm::mat4 MVP = P * V * M;
	return MVP;
}

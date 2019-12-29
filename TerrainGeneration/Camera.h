#pragma once
#include <GL\glew.h>
#include <GLFW\glfw3.h>
#include <glm\glm.hpp>
#include <glm\fwd.hpp>
#include <glm\ext\matrix_transform.hpp>
#include "InputManager.h"
#include "Observer.h"
#include "Time.h"

class Camera : public Observer
{
public:
	Camera(InputManager* _inputManager, Time* _time);
	glm::mat4 getPosition();

	virtual void notify() override;
private:
	InputManager* inputManager;
	Time* time;

	// cam positions
	glm::vec3 position = glm::vec3(0.0f, 0.0f, 3.0f);
	glm::vec3 forward = glm::vec3(0.0f, 0.0f, -1.0f);
	glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f);

	// cam cofig
	GLfloat speed = 2.5f;
	GLfloat yaw = -90.0f;
	GLfloat pitch = 0.0f;
	GLfloat sensitivity = 0.05;

	// mouse position details
	GLboolean firstMouse = true;

	GLfloat lastX;
	GLfloat lastY;

	void registerKeypressCallbacks();
	void updateCameraPosition(GLdouble mousePosX, GLdouble mousePosY);
};


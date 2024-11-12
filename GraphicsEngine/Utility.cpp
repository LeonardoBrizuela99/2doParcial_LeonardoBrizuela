#include "Utility.h"
#include "GL/glew.h"
#include "GLFW/glfw3.h"
#include <iostream>
float deltaTime = 0.0f;
float lastFrame = 0.0f;
void UpdateDeltaTime()
{
	float currentFrame = glfwGetTime();
	deltaTime = currentFrame - lastFrame;
	lastFrame = currentFrame;
}
float DeltaTime()
{
	return deltaTime;
}
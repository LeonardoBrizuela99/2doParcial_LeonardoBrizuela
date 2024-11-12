#ifndef WINDOW_H
#define WINDOW_H
#include "Export.h"

struct GLFWmonitor;
struct GLFWwindow;

class ENGINE_API Window
{
private:
	GLFWwindow* window;
public:
	Window();
	Window(int width, int height, const char* title, GLFWmonitor* monitor, GLFWwindow* share);
	void WindowContext();
	bool ShouldClose();
	GLFWwindow* GetWindow();
	void ClearBackground();
	void SwapBuffer();
};
#endif
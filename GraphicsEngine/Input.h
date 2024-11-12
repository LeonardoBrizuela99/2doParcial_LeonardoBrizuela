#ifndef INPUT_H
#define INPUT_H
#include "Keycode.h"
struct GLFWwindow;
class Input
{
private:

public:
	bool GetKey(int keycode, GLFWwindow* window);
	Input();
	~Input();
};
#endif
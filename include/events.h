#ifndef EVENTS_H
# define EVENTS_H

#include <GLFW/glfw3.h>

class EventMaster
{
public:
	bool keys[1024];
public:
	EventMaster();
	void get_events();
};

void	key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);

#endif
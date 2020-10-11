#include "events.h"
#include <iostream>

void	key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
	EventMaster *ev;
	ev = (EventMaster *)glfwGetWindowUserPointer(window);

	if(key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
    	glfwSetWindowShouldClose(window, GL_TRUE);
	if (key >= 0 && key < 1024)
    {
        if (action == GLFW_PRESS)
            ev->keys[key] = true;
        else if (action == GLFW_RELEASE)
            ev->keys[key] = false;
    }
	scancode = 0;
	mode = 0;
}

EventMaster::EventMaster()
{
	for (int i = 0; i<1024; ++i)
		keys[i] = false;

}

void EventMaster::get_events()
{
	glfwPollEvents();
}

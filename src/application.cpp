# define GL_SILENCE_DEPRECATION
# define GLFW_INCLUDE_GLCOREARB

#include <GLFW/glfw3.h>
#include "42run.h"
#include "application.h"
#include "utils.h"

static bool		init_glfw()
{
	if (!glfwInit())
        return 1;
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	return 0;
}

static	void	key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
	application* app = (application*)glfwGetWindowUserPointer(window);
	if(key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
    	glfwSetWindowShouldClose(window, GL_TRUE);
	if (key >= 0 && key < 1024)
    {
        if (action == GLFW_PRESS)
            app->keys[key] = true;
        else if (action == GLFW_RELEASE)
            app->keys[key] = false;
    }
	scancode = 0;
	mode = 0;
}

application::application()
{
	if (init_glfw())
		error("glfw's initialization failed");
	window = glfwCreateWindow(WIDTH, HEIGHT, "42run", NULL, NULL);
	if (!window)
		error("window's creation failed");
	glfwSetWindowUserPointer(window, this);
	glfwMakeContextCurrent(window);
}

application::~application()
{
	logln("app closed");
	glfwTerminate();
}
void application::run()
{
	// temporary mesh
	float vertices[] = {
    -0.5f, -0.5f, 0.0f,
     0.5f, -0.5f, 0.0f,
     0.0f,  0.5f, 0.0f
	};
	vertices[0] = -0.5f;
	rend.createShader((char *)"res/shaders/vertex.shader", (char *)"res/shaders/fragment.shader");
    while (!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT);
        glfwSwapBuffers(window);

		if (!rend.getStatus())
			break ;

		glfwSetKeyCallback(window, key_callback);
        glfwPollEvents();
    }
}
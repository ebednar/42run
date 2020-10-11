# define GL_SILENCE_DEPRECATION
# define GLFW_INCLUDE_GLCOREARB

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
	
	logln("glfw terminated");
}
void application::run()
{
	Model cube;
	rend.set_model(&cube);
	rend.createShader((char *)"res/shaders/vertex.shader", (char *)"res/shaders/fragment.shader");
	rend.vertexBuffer();
	EventMaster ev;
	glfwSetWindowUserPointer(window, &ev);
	glfwSetKeyCallback(window, key_callback);
    while (!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        
		if (!rend.getStatus())
		{
			log("can`t draw object - ");
			logln(cube.name);
			break ;
		}
		rend.draw_frame();
		glfwSwapBuffers(window);
		ev.get_events();
        
    }
	logln("------end of cycle------");
	glfwTerminate();
}
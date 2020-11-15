#include "42run.h"
#include "Events.h"
#include "Render.h"
#include "Shader.h"

int main(void)
{
	GLFWwindow* window;
	if (!glfwInit())
		exit(EXIT_FAILURE);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	window = glfwCreateWindow(WIDTH, HEIGHT, "42 run", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		exit(EXIT_FAILURE);
	}
	glfwMakeContextCurrent(window);
	glfwSetKeyCallback(window, key_callback);
	glViewport(0, 0, 1280, 720);

	Model mod;
	mod.LoadMesh();
	mod.VertexBuffer();
	Render rend;
	rend.AddModel(&mod);
	CreateShader(&(mod.shader_id), "res/shaders/vertex.shader", "res/shaders/fragment.shader");

	while (!glfwWindowShouldClose(window))
	{
		glClear(GL_COLOR_BUFFER_BIT);
		glClearColor(0.3f, 0.4f, 0.9f, 1.0f);

		rend.DrawModels();

		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	glfwTerminate();
	return 0;
}

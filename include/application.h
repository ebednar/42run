#ifndef APPLICATION_H
# define APPLICATION_H

# include "render.h"

struct GLFWwindow
{
};

class application
{
public:
	render rend;
	bool keys[1024];

private:
	GLFWwindow* window;
public:
	application();
	~application();
	void	run();
};

#endif
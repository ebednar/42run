#ifndef APPLICATION_H
# define APPLICATION_H

# include "render.h"
# include "events.h"

struct GLFWwindow
{
};

class application
{
public:
	render rend;

private:
	GLFWwindow *window;
public:
	application();
	~application();
	void	run();
};

#endif
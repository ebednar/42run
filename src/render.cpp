#define GL_SILENCE_DEPRECATION

#include <OpenGL/gl.h>
#include "render.h"
#include "shader.h"
#include "utils.h"

render::render()
:stat(SUCCESS){}

render::~render()
{
	logln("render closed");
}

void	render::vertexBuffer(float* vertices)
{
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
}

void	render::createShader(char* vertShader, char* fragShader)
{
	shader sh(vertShader, fragShader);
	shader_id = sh.getProgramID();
	if (!shader_id)
		stat = FAIL;
}

bool	render::getStatus()
{
	return (stat == SUCCESS ? true : false);
}
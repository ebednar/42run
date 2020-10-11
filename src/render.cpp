#define GL_SILENCE_DEPRECATION

#include <OpenGL/gl3.h>
#include "render.h"
#include "shader.h"
#include "utils.h"

render::render()
:stat(SUCCESS){}

render::~render()
{
	logln("render closed");
}

void	render::set_model(Model *model)
{
	this->mod = model;
}

void	render::vertexBuffer()
{
	glGenVertexArrays(1, &mod->vao);
	glBindVertexArray(mod->vao);
	glGenBuffers(1, &mod->vbo);
	glBindBuffer(GL_ARRAY_BUFFER, mod->vbo);
	glBufferData(GL_ARRAY_BUFFER, mod->vert_number * 3 * sizeof(float), mod->vertices, GL_STATIC_DRAW);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, mod->vert_number, GL_FLOAT, GL_FALSE, 3 * sizeof(float), 0);
	glBindVertexArray(0);
}

void	render::createShader(char* vertShader, char* fragShader)
{
	shader sh(vertShader, fragShader);
	mod->shader_id = sh.getProgramID();
	if (!mod->shader_id)
	{
		stat = FAIL;
		// sh.~shader();
	}
}

bool	render::getStatus()
{
	return (stat == SUCCESS ? true : false);
}

void	render::draw_frame()
{
	glUseProgram(mod->shader_id);
	glBindVertexArray(mod->vao);
	glDrawArrays(GL_TRIANGLES, 0, 3);
	glBindVertexArray(0);
	
}
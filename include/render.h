#ifndef RENDER_H
# define RENDER_H

enum status
{FAIL, SUCCESS};

class render
{
private:
	unsigned int	vbo;
	unsigned int	shader_id;
	status			stat;
public:
	render();
	void			vertexBuffer(float* vertices);
	void			createShader(char* vertShader, char* fragShader);
	bool			getStatus();
	~render();
};

#endif
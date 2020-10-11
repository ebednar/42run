#ifndef RENDER_H
# define RENDER_H

# include "model.h"

enum status
{FAIL, SUCCESS};

class render
{
public:
	Model* mod;
private:
	status			stat;
public:
	render();
	void			set_model(Model *mod);
	void			vertexBuffer();
	void			createShader(char *vertShader, char *fragShader);
	bool			getStatus();
	void			draw_frame();
	~render();
};

#endif
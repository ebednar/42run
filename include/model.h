#ifndef MODEL_H
# define MODEL_H

class Model
{
public:
	char			*name;
	float			*vertices;
	unsigned int	*indices;
	unsigned int	vert_number;
	unsigned int	ind_number;
	unsigned int	vbo;
	unsigned int	vao;
	unsigned int	shader_id;
public:
					Model();
	void			load(char* path);
};

#endif
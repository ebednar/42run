#ifndef MODEL_H
# define MODEL_H
# define GL_SILENCE_DEPRECATION

class Model
{
public:
	float			*vertices;
	unsigned int	*indices;
	unsigned int	vert_number;
	unsigned int	ind_number;
	unsigned int	vbo;
	unsigned int	vao;
	unsigned int	ibo;
	int	shader_id;
public:
	Model();
	void LoadMesh();
	void SetShader();
	void VertexBuffer();

private:

};

#endif
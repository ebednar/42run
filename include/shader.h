#ifndef SHADER_H
# define SHADER_H

class shader
{
private:
	unsigned int	program;
public:
	shader(const char* vertexPath, const char* fragmentPath);
	~shader();
	unsigned int	getProgramID() const;
};

#endif
#define GL_SILENCE_DEPRECATION

#include <OpenGL/gl.h>
#include <fstream>
#include <sstream>
#include "shader.h"
#include "utils.h"

static std::string loadShader(const char *filepath)
{
	std::ifstream data(filepath);
	std::string line;
	std::stringstream str;

	if (data.fail())
		error(".shader file not found");
	while (std::getline(data, line))
	{
		str << line << '\n';
	}
	return str.str();
}

static unsigned int compileShader(unsigned int type, const std::string source)
{
	unsigned id = glCreateShader(type);
	const char* src = source.c_str();
	glShaderSource(id, 1, &src, NULL);
	glCompileShader(id);
	int result;
	glGetShaderiv(id, GL_COMPILE_STATUS, &result);
	if (result == GL_FALSE)
	{
		int length;
		glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
		char* message = new char[length + 1];
		glGetShaderInfoLog(id, length, &length, message);
		error("");
		type == GL_VERTEX_SHADER ? log("vertex ") : log("fragment ");
		logln("shader compilation failed");
		log(message);
		delete[](message);
		glDeleteShader(id);
		return 0;
	}
	return id;
}

shader::shader(const char* vertexPath, const char* fragmentPath)
{	
	std::string vertexShader = loadShader(vertexPath);
	std::string fragmentShader = loadShader(fragmentPath);
	if (vertexShader.empty() || fragmentShader.empty())
	{
		program = 0;
		return ;
	}
	program = glCreateProgram();
	unsigned int vs = compileShader(GL_VERTEX_SHADER, vertexShader);
	unsigned int fs = compileShader(GL_FRAGMENT_SHADER, fragmentShader);
	if (vs == 0 || fs == 0)
	{
		program = 0;
		return ;
	}
	glAttachShader(program, vs);
	glAttachShader(program, fs);
	glLinkProgram(program);
	int result;
	glGetProgramiv(program, GL_LINK_STATUS, &result);
	if (!result)
	{
		int length;
		glGetProgramiv(program, GL_INFO_LOG_LENGTH, &length);
		char* message = new char[length + 1];
		glGetProgramInfoLog(program, length, &length, message);
		error("link error");
		log(message);
		delete[](message);
	}
	glValidateProgram(program);
	glDeleteShader(vs);
	glDeleteShader(fs);
}

unsigned int shader::getProgramID() const
{
	return program;
}

shader::~shader()
{
	logln("shader deleted");
}
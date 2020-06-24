#include "utils.h"
#include <iostream>

void	log(const char* message)
{
	std::cout << message;
}

void	log(int message)
{
	std::cout << message;
}

void	log(float message)
{
	std::cout << message;
}

void	logln(const char* message)
{
	std::cout << message << std::endl;
}

void	logln(int message)
{
	std::cout << message;
}

void	logln(float message)
{
	std::cout << message;
}

void	error(const char* message)
{
	std::cout << "ERROR: " << message << std::endl;
}
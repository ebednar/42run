#include "model.h"

Model::Model()
{
	float default_vert[9] = {
    -0.5f, -0.5f, 0.0f,
     0.5f, -0.5f, 0.0f,
     0.0f,  0.5f, 0.0f
	};
	name = (char *)"Default model";
	vertices = new float(9);
	vert_number = 3;
	for(int i = 0; i < 9; ++i)
		vertices[i] = default_vert[i];
}
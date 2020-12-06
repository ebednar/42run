#include "render.h"
#define GL_SILENCE_DEPRECATION
#include <OpenGL/gl3.h>
#include <iostream>

void Render::draw_scene(std::vector<Entity *> scene, glm::vec3 **lights, Camera *cam, bool free_cam)
{
	int length = scene.size();
	if (free_cam)
		cam->update_free();
	else
		cam->update_follow(player->position);
	glm::mat4 projection;
	projection = glm::perspective(glm::radians(60.0f), 640.0f / 480.0f, 0.1f, 100.0f);

	float test[9];
	test[0] = lights[0]->x;
	test[1] = lights[0]->y;
	test[2] = lights[0]->z;
	test[3] = lights[1]->x;
	test[4] = lights[1]->y;
	test[5] = lights[1]->z;
	test[6] = lights[2]->x;
	test[7] = lights[2]->y;
	test[8] = lights[2]->z;
	//std::cout << sizeof(glm::vec3) << std::endl;

	for (int i = 0; i < length; ++i)
	{
		Entity	*ent = scene[i];
		Model	*mod = ent->mod;
		glUseProgram(mod->shader_id);
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, mod->texture);
		glBindVertexArray(mod->vao);

		glm::mat4 model = glm::mat4(1.0f);
		model = glm::translate(model, ent->position);
		model = glm::rotate(model, glm::radians(ent->angle[0]), glm::vec3(1.0f, 0.0f, 0.0f));
		model = glm::rotate(model, glm::radians(ent->angle[1]), glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::rotate(model, glm::radians(ent->angle[2]), glm::vec3(0.0f, 0.0f, 1.0f));
		model = glm::scale(model, ent->e_scale);

		unsigned int model_loc = glGetUniformLocation(mod->shader_id, "u_M");
		glUniformMatrix4fv(model_loc, 1, GL_FALSE, glm::value_ptr(model));
		unsigned int view_loc = glGetUniformLocation(mod->shader_id, "u_V");
		glUniformMatrix4fv(view_loc, 1, GL_FALSE, glm::value_ptr(cam->view));
		unsigned int proj_loc = glGetUniformLocation(mod->shader_id, "u_P");
		glUniformMatrix4fv(proj_loc, 1, GL_FALSE, glm::value_ptr(projection));

		glUniform1i(glGetUniformLocation(mod->shader_id, "lightNumb"), 3);
		glUniform3fv(glGetUniformLocation(mod->shader_id, "lightPos"), 3, test);
		glUniform3f(glGetUniformLocation(mod->shader_id, "viewPos"), cam->pos.x, cam->pos.y, cam->pos.z);
		glUniform1i(glGetUniformLocation(mod->shader_id, "material.diffuse"), 0);
		glUniform3f(glGetUniformLocation(mod->shader_id, "material.specular"), 0.5f, 0.5f, 0.5f);
		glUniform1f(glGetUniformLocation(mod->shader_id, "material.shininess"), 16.0f);
		glUniform3f(glGetUniformLocation(mod->shader_id, "light.ambient"), 0.2f, 0.2f, 0.2f);
		glUniform3f(glGetUniformLocation(mod->shader_id, "light.diffuse"), 0.7f, 0.7f, 0.7f);
		glUniform3f(glGetUniformLocation(mod->shader_id, "light.specular"), 0.7f, 0.7f, 0.7f);
		glUniform1f(glGetUniformLocation(mod->shader_id, "light.constant"), 1.0f);
		glUniform1f(glGetUniformLocation(mod->shader_id, "light.linear"), 0.07f);
		glUniform1f(glGetUniformLocation(mod->shader_id, "light.quadratic"), 0.017f);
		glDrawArrays(GL_TRIANGLES, 0, 36);
	}
}

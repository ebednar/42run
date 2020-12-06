#include "42run.h"
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

void	shift_player_l(Engine* eng)
{
	eng->state->shifting = false;
	if (eng->state->p_pos == left_r || eng->state->shift > 0)
		return ;
	if (eng->state->p_pos == center_r)
		eng->state->p_pos = left_r;
	else
		eng->state->p_pos = center_r;
	eng->state->shifting_x = -sin(glm::radians(eng->player->angle[1]));
	eng->state->shifting_y = -cos(glm::radians(eng->player->angle[1]));
	eng->state->shift = 20;
}

void	shift_player_r(Engine* eng)
{
	eng->state->shifting = false;
	if (eng->state->p_pos == right_r || eng->state->shift > 0)
		return ;
	if (eng->state->p_pos == center_r)
		eng->state->p_pos = right_r;
	else
		eng->state->p_pos = center_r;
	eng->state->shifting_x = sin(glm::radians(eng->player->angle[1]));
	eng->state->shifting_y = cos(glm::radians(eng->player->angle[1]));
	eng->state->shift = 20;
}

void	controls(Engine* eng)
{
	float speed = glm::pi<float>() * eng->delta_time;
	eng->player->move(speed * cos(glm::radians(eng->player->angle[1])), 0.0f, -speed * sin(glm::radians(eng->player->angle[1])));
	if (eng->free_cam)
	{
		eng->cam.speed = 8.0f * eng->delta_time;
		if (eng->controls.keys[GLFW_KEY_W])
			eng->cam.pos += eng->cam.speed * eng->cam.front;
		if (eng->controls.keys[GLFW_KEY_S])
			eng->cam.pos -= eng->cam.speed * eng->cam.front;
		if (eng->controls.keys[GLFW_KEY_A])
			eng->cam.pos -= eng->cam.speed * glm::normalize(glm::cross(eng->cam.front, eng->cam.up));
		if (eng->controls.keys[GLFW_KEY_D])
			eng->cam.pos += eng->cam.speed * glm::normalize(glm::cross(eng->cam.front, eng->cam.up));
		eng->cam.yaw = eng->controls.yaw;
		eng->cam.pitch = eng->controls.pitch;
	}
	else
	{
		std::cout << "ss" << std::endl;
		eng->cam.pos.x = eng->player->position[0];
		eng->cam.pos.z = eng->player->position[2];
		eng->cam.yaw = -eng->player->angle.y;
		if (eng->state->shift > 0)
		{
			eng->state->shift--;
			eng->player->move(0.05 * eng->state->shifting_x, 0.0f, 0.05 * eng->state->shifting_y);
		}
		else
			eng->state->shifting = true;
		if (eng->state->shifting == false || eng->state->shift_rotate)
			return ;
			std::cout << "wait" << std::endl;
		if (eng->controls.keys[GLFW_KEY_A])
			shift_player_l(eng);
		if (eng->controls.keys[GLFW_KEY_D])
			shift_player_r(eng);
	}
}

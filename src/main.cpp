#include "42run.h"
#include <time.h>

int		main(int argc, char **argv)
{
	Engine	engine;
	state	state;
	
	srand(time(NULL));
	engine.init_engine(WIDTH, HEIGHT);
	engine.state = &state;
	if (argc == 2 && !strcmp(argv[1], "-f"))
	{
			engine.free_cam = true;
	}
	init_game(&engine, &state);
	engine.run_engine(game_loop);
	delete(engine.state->current_plat);
	delete(engine.state->next_plat);
	delete(engine.state->obst1);
	delete(engine.state->obst2);
	return 0;
}

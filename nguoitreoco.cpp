
#include "SDLL.h"
Game* game = NULL;


int main(int argc, char* args[]){
	const int FPS = 120;
	const int FPS_Delay = 1000 / FPS;
	Uint32 Frame_Start, Frame_Time;
	game = new Game();
	game->initSDL();
	while (game->running()) {
		Frame_Start = SDL_GetTicks();
		game->handle_event();
		game->update();
		game->render();
		Frame_Time = SDL_GetTicks() - Frame_Start;
		//cout << Frame_Time << endl;
		if (FPS_Delay > Frame_Time) {
			SDL_Delay(FPS_Delay - Frame_Time);
		}
	}
	game->clean();
	
	
	return 0;
}

#include "Screen.h"
#include <SDL.h>
using namespace std;

int TestingMain()
{
	Screen testScreen(640, 800, "Testing...1 2 3");
	bool escKey = false;
	while(escKey == false)
	{
		SDL_Event keyevent; 
		SDL_PollEvent(&keyevent);
		if(keyevent.key.keysym.sym == SDLK_ESCAPE)
		{
			escKey = true;
		}
	}

	testScreen.closeScreen();

	return 0;
}
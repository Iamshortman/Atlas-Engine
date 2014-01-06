#include "Screen.h"

#include <SDL.h>
#include <SDL_opengl.h>
#include <SDL_image.h>

using namespace std;

int TestingMain()
{
	AE_String Title = "Test Game";
	int SCREEN_WIDTH = 640;
	int SCREEN_HEIGHT = 400;

	Screen testScreen(SCREEN_WIDTH, SCREEN_HEIGHT, Title);

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

#include "Screen.h"

#include <iostream>

#include <SDL.h>
#include <SDL_opengl.h>
#include <SDL_image.h>

using namespace std;

int TestingMain()
{
	AE_String str;
	cout << "Enter Window Title:";
	std::getline(std::cin, str);

	Screen testScreen(640, 400, str);
	
	bool escKey = false;
	while(escKey == false)
	{
		SDL_Event keyevent; 
		SDL_PollEvent(&keyevent);
		if(keyevent.key.keysym.sym == SDLK_ESCAPE)
		{
			escKey = true;
		}

		//OpenGL Crap
		//Clear color buffer 
		glClear( GL_COLOR_BUFFER_BIT );

		 glBegin( GL_QUADS ); 
		 glVertex2f( -0.5f, -0.5f ); 
		 glVertex2f( 0.5f, -0.5f ); 
		 glVertex2f( 0.5f, 0.5f ); 
		 glVertex2f( -0.5f, 0.5f ); 
		 glEnd();

		 //Update screen 
		 testScreen.updatedScreen();
	}

	testScreen.closeScreen();

	return 0;
}
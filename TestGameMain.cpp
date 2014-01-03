#include "Screen.h"

#include <SDL.h>
#include <SDL_opengl.h>
#include <SDL_image.h>

using namespace std;

int TestingMain()
{
	AE_String Title = "Test Game";
	int SCREEN_WIDTH = 640;
	int SCREEN_HEIGHT = 500;

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

		//OpenGL Crap
		//Clear color buffer  
		glClear( GL_COLOR_BUFFER_BIT ); 
		
		//Pop default matrix onto current matrix 
		glMatrixMode( GL_MODELVIEW ); 
		glPopMatrix(); 
		
		//Save default matrix again 
		glPushMatrix();

		//Red quad 
		glBegin( GL_QUADS ); 
		glColor3f( 1.f, 0.f, 0.f ); 
		glVertex2f( -SCREEN_WIDTH / 4.f, -SCREEN_HEIGHT / 4.f ); 
		glVertex2f( SCREEN_WIDTH / 4.f, -SCREEN_HEIGHT / 4.f ); 
		glVertex2f( SCREEN_WIDTH / 4.f, SCREEN_HEIGHT / 4.f ); 
		glVertex2f( -SCREEN_WIDTH / 4.f, SCREEN_HEIGHT / 4.f ); 
		glEnd(); 
		
		//Move to the right of the screen 
		glTranslatef( SCREEN_WIDTH, 0.f, 0.f ); 
		//Green quad 
		
		glBegin( GL_QUADS ); 
		glColor3f( 0.f, 1.f, 0.f ); 
		glVertex2f( -SCREEN_WIDTH / 4.f, -SCREEN_HEIGHT / 4.f ); 
		glVertex2f( SCREEN_WIDTH / 4.f, -SCREEN_HEIGHT / 4.f ); 
		glVertex2f( SCREEN_WIDTH / 4.f, SCREEN_HEIGHT / 4.f ); 
		glVertex2f( -SCREEN_WIDTH / 4.f, SCREEN_HEIGHT / 4.f ); 
		glEnd(); 
		
		//Move to the lower right of the screen 
		glTranslatef( 0.f, SCREEN_HEIGHT, 0.f ); 
		
		//Blue quad 
		glBegin( GL_QUADS ); 
		glColor3f( 0.f, 0.f, 1.f ); 
		glVertex2f( -SCREEN_WIDTH / 4.f, -SCREEN_HEIGHT / 4.f ); 
		glVertex2f( SCREEN_WIDTH / 4.f, -SCREEN_HEIGHT / 4.f ); 
		glVertex2f( SCREEN_WIDTH / 4.f, SCREEN_HEIGHT / 4.f ); 
		glVertex2f( -SCREEN_WIDTH / 4.f, SCREEN_HEIGHT / 4.f ); 
		glEnd(); 
		
		//Move below the screen 
		glTranslatef( -SCREEN_WIDTH, 0.f, 0.f ); 
		//Yellow quad 
		glBegin( GL_QUADS ); 
		glColor3f( 1.f, 1.f, 0.f ); 
		glVertex2f( -SCREEN_WIDTH / 4.f, -SCREEN_HEIGHT / 4.f ); 
		glVertex2f( SCREEN_WIDTH / 4.f, -SCREEN_HEIGHT / 4.f ); 
		glVertex2f( SCREEN_WIDTH / 4.f, SCREEN_HEIGHT / 4.f ); 
		glVertex2f( -SCREEN_WIDTH / 4.f, SCREEN_HEIGHT / 4.f ); 
		glEnd();

		 //Update screen 
		 testScreen.updatedScreen();
	}

	testScreen.closeScreen();

	return 0;
}

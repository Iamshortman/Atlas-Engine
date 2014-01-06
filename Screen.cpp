#include "Screen.h"

Screen::Screen(int width, int height, AE_String windowTitle)
{
	SDL_Init(SDL_INIT_VIDEO); 

	// Create an application window with the following settings:
    window = SDL_CreateWindow(
        windowTitle.c_str(),
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        width,
        height,
        SDL_WINDOW_OPENGL|SDL_WINDOW_RESIZABLE
    );

	// Create an OpenGL context associated with the window.
	glcontext = SDL_GL_CreateContext(window);

	initGL(width, height);
}

void Screen::initGL(int width, int height) 
{
	//Initialize Projection Matrix 
	glMatrixMode( GL_PROJECTION ); 
	glLoadIdentity(); 
	
	glOrtho(0, width, height, 0, 1, -1);

	//Initialize Modelview Matrix 
	glMatrixMode( GL_MODELVIEW ); 
	glLoadIdentity();

	 //Initialize clear color 
	glClearColor( 0.0f, 0.0f, 0.0f, 1.0f );

	//  Enable Z-buffer depth test
	//glEnable(GL_DEPTH_TEST);

	/*glClearColor(0, 0, 0, 0);
	glClearDepth(1.0f);
 
	glViewport(0, 0, width, height);
 
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
 
	glOrtho(0, width, height, 0, 1, -1);
 
	glMatrixMode(GL_MODELVIEW);
 
	glEnable(GL_TEXTURE_2D);
 
	glLoadIdentity();*/
}

void Screen::updatedBuffer()
{
	SDL_GL_SwapWindow(window);
}

void Screen::setBufferClearColor(GLclampf red, GLclampf green, GLclampf blue,
GLclampf alpha)
{
	 glClearColor(red, green, blue, alpha);
}

void Screen::clearBuffer()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Screen::setTitleString(AE_String title)
{
	SDL_SetWindowTitle(window, title.c_str());
}

const AE_String Screen::getTitleString()
{
	AE_String title = SDL_GetWindowTitle(window);
	return title;
}

void Screen::closeScreen()
{
	SDL_DestroyWindow(window);
}

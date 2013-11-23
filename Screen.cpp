
#include "Screen.h"

Screen::Screen(int width, int height, AE_String windowTitle)
{
	SDL_Init(SDL_INIT_VIDEO); 

	// Create an application window with the following settings:
    window = SDL_CreateWindow(
        windowTitle.c_str(),
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        640,
        480,
        SDL_WINDOW_OPENGL
    );

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

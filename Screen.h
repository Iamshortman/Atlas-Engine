#include <SDL.h>
#include <stdio.h>
#include <string>

#ifndef SCREEN_H
#define SCREEN_H

typedef std::string AE_String;  

class Screen
{
	public:
		Screen(int width = 640 , int height = 480, AE_String windowTitle = "");
		const AE_String getTitleString();
		void setTitleString(AE_String title);
		void closeScreen();

	private:
		SDL_Window *window;

};

#endif
#include <SDL.h>
#include <SDL_opengl.h>
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
		void updatedBuffer();
		void clearBuffer();
		void setBufferClearColor(GLclampf red, GLclampf green, GLclampf blue,
GLclampf alpha);

	private:
		SDL_Window *window;
		SDL_GLContext glcontext;
		void initGL(int width, int height);
};

#endif
#include "Screen.h"
#include <SDL.h>
using namespace std;

int TestingMain()
{
	Screen testScreen(640, 800, "Testing...1 2 3");

	_sleep(3000);
	testScreen.setTitleString("The Cake is a lie");
	_sleep(3000);

	return 0;
}
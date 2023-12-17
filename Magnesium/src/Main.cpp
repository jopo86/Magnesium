#include <iostream>

#include "MgWindow.h"
#include "MgErrorHandler.h"

void windowTest();

int main()
{
	windowTest();

	return 0;
}

void windowTest()
{
	MgErrorHandler errorHandler = MgErrorHandler(true, false);

	MgWindow window;
	window.init(errorHandler);

	while (window.isOpen())
	{
		window.startRender();
		window.endRender();
	}

	window.cleanup();
	errorHandler.cleanup();
}

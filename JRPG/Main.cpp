#include <windows.h>
#include <wincon.h>
#include "App.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	{
		AllocConsole();
		freopen("CONIN$", "r", stdin); 
		freopen("CONOUT$", "w", stdout); 
		freopen("CONOUT$", "w", stderr); 
		//JUST FOR FUN
		std::cout << " ____  ____  ____  __  __  ___ " << std::endl;
		std::cout << "(  _ \\( ___)(  _ \\(  )(  )/ __)" << std::endl;
		std::cout << " )(_) ))__)  ) _ < )(__)(( (_-." << std::endl;
		std::cout << "(____/(____)(____/(______)\\___/\n" << std::endl;
		std::cout << "-Launching Application-\n" << std::endl;
	}

	App application;

	application.Init();

	application.Run();

	return 0;
};


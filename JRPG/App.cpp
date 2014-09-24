#include "App.h"
#include "XMLToMemoryHelper.h"

App::App()
{
	renderManager = new RenderManager();
	game = XMLToMemoryHelper::GetGame();
}

App::~App()
{
	delete renderManager;
}

void App::Run()
{
	while(renderManager->WindowIsOpen()){
		renderManager->PollEvent();
		renderManager->Update();
	}
}

/*
I keep that in a corner in case of need
it retrives the size of a file without opening it (maybe...I should investigate on how stat work behind the scene)
#include <sys\stat.h>;

size_t filesize(char *filename){
	struct stat st;
	size_t retval =0;
	if(stat(filename, &st)){
		printf("can't use stat on %s\n", filename);
	}else{
		retval=st.st_size;
	}
	return retval;
}
*/
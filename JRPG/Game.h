#include <list>

class Game{

public:
	Game();
	Game(int);
	~Game();
	Game(const Game&);

private:
	int actualScene;
	

};
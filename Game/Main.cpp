#include "Game.h"

void main()
{
	Game* myGame = new Game();
	myGame->Play();
	if (myGame != nullptr) delete myGame;
}
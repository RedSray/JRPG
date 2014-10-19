#include "InfoBoard.h"

InfoBoard::InfoBoard()
{
	font.loadFromFile("linowrite.ttf");
	test.setFont(font);
	test.setColor(sf::Color::Red);
	test.setString("TEST");
}

InfoBoard::~InfoBoard()
{

}

void InfoBoard::ExplorationUpdate(sf::RenderWindow&)
{

}

void InfoBoard::InteractionUpdate(sf::RenderWindow&)
{

}

void InfoBoard::ExplorationRender(sf::RenderWindow&)
{

}

void InfoBoard::InteractionRender(sf::RenderWindow&)
{

}

void InfoBoard::ExplorationGUIRender(sf::RenderWindow& window)
{
	
}

void InfoBoard::InteractionGUIRender(sf::RenderWindow& window)
{
	window.draw(test);
}
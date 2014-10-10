#include "MenuState.h"

MenuState::MenuState()
{
	
}

MenuState::~MenuState()
{

}

void MenuState::OnEnter(sf::RenderWindow& window)
{
	titleFont.loadFromFile("LEVIBRUSH.TTF");
	menuFont.loadFromFile("linowrite.ttf");

	title.setFont(titleFont);
	title.setString("Monsters Get Slain");
	title.setColor(sf::Color::White);
	title.setCharacterSize(50);
	title.setOrigin(title.getLocalBounds().width/2.0f,title.getLocalBounds().height/2.0f);
	title.setPosition(0.0f,-150.0f);

	menuItems.resize(2);
	menuItems[0].setFont(menuFont);
	menuItems[0].setString("Play");
	menuItems[0].setCharacterSize(20);
	menuItems[0].setColor(sf::Color::White);
	menuItems[0].setOrigin(menuItems[0].getLocalBounds().width/2,menuItems[0].getLocalBounds().height/2);
	menuItems[0].setPosition(0.0f,0.0f);

	menuItems[1].setFont(menuFont);
	menuItems[1].setString("Quit");
	menuItems[1].setCharacterSize(20);
	menuItems[1].setColor(sf::Color::White);
	menuItems[1].setOrigin(menuItems[1].getLocalBounds().width/2,menuItems[1].getLocalBounds().height/2);
	menuItems[1].setPosition(0.0f,menuItems[0].getLocalBounds().height+10);

	selectionAnimationInterverted = false;
	selectedItem = 0;
}

void MenuState::OnExit(sf::RenderWindow& window)
{

}

StateType MenuState::Update(sf::RenderWindow& window, sf::Time lastFrameDuration)
{
	//Update selection according to input
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
	{
		return StateType::Splash;
		std::cout << menuItems[selectedItem].getString().toAnsiString() << std::endl;
	}

	//pressing down
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		if(selectionChangeRepetitionTime.asSeconds() <= 0.0f)
		{
			selectedItem++;
			if(selectedItem >= menuItems.size()) selectedItem = 0;

			selectionChangeRepetitionTime = sf::seconds(0.5f);
			selectionAnimationInterverted = false;
			selectionAnimationTime = sf::Time::Zero;
		}
		else 
		{
			selectionChangeRepetitionTime -= lastFrameDuration;
		}
	}
	
	//pressing up
	if(!sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		if(selectionChangeRepetitionTime.asSeconds() <= 0.0f)
		{
			selectedItem--;
			if(selectedItem < 0) selectedItem = menuItems.size()-1;

			selectionChangeRepetitionTime = sf::seconds(0.3f);
			selectionAnimationInterverted = false;
			selectionAnimationTime = sf::Time::Zero;
		}
		else 
		{
			selectionChangeRepetitionTime -= lastFrameDuration;
		}
	}
	
	if(selectionChangeRepetitionTime > sf::Time::Zero && !sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		selectionChangeRepetitionTime = sf::Time::Zero;
	}
	

	//Update Selection Animation
	selectionAnimationTime += lastFrameDuration;
	if(selectionAnimationTime.asSeconds() >= selectionAnimationDuration) 
	{
		selectionAnimationTime = sf::Time::Zero;
		selectionAnimationInterverted = !selectionAnimationInterverted;
	}

	sf::Color color;
	if(selectionAnimationInterverted) color = sf::Color(255-(255*(selectionAnimationTime.asSeconds()/selectionAnimationDuration)),255,255-(255*(selectionAnimationTime.asSeconds()/selectionAnimationDuration)),255);
	else color = sf::Color(255*(selectionAnimationTime.asSeconds()/selectionAnimationDuration),255,255*(selectionAnimationTime.asSeconds()/selectionAnimationDuration),255);

	for(int i=0; i < menuItems.size(); ++i)
	{
		if(selectedItem == i) menuItems[i].setColor(color);
		else menuItems[i].setColor(sf::Color::White);
	}

	return StateType::NoState;
}

void MenuState::Render(sf::RenderWindow& window)
{
	window.draw(title);

	for(int i=0; i < menuItems.size(); ++i)
	{
		window.draw(menuItems[i]);
	}
}
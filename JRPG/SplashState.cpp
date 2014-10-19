#include "SplashState.h"

SplashState::SplashState()
{

}

SplashState::~SplashState()
{

}

void SplashState::OnEnter(sf::RenderWindow& window)
{
	sf::View view(sf::Vector2f(0,0),sf::Vector2f(WINDOW_WIDTH,WINDOW_HEIGHT));
	window.setView(view);
	if(!splashTexture.loadFromFile("splash.png"))
	{
		std::cout << "Error loading splash.png" << std::endl;
	}
	splash.setTexture(splashTexture);
	splash.setOrigin(splash.getTextureRect().width/2.0f,splash.getTextureRect().height/2.0f);  
	transparency = 0;
	splash.setColor(sf::Color(255,255,255,transparency));
}

void SplashState::OnExit(sf::RenderWindow& window)
{

}

StateType SplashState::Update(sf::RenderWindow& window, sf::Time lastFrameDuration)
{
	totalduration += lastFrameDuration;
	if(totalduration.asSeconds() <= 2.0f)
	{
		//transparency goes up
		transparency = 255*(totalduration.asSeconds()/2.0f);
		
		splash.setColor(sf::Color(255,255,255,transparency));
	}
	else if(totalduration.asSeconds() <= 4.0f)
	{
		//transparency goes down
		transparency = 255-255*((totalduration.asSeconds()-2.0f)/2.0f);
		splash.setColor(sf::Color(255,255,255,transparency));
	}
	else
	{
		return StateType::Menu;
	}

	return StateType::NoState;
}

void SplashState::Render(sf::RenderWindow& window)
{
	window.draw(splash);
}

void SplashState::RenderGUI(sf::RenderWindow&)
{

}
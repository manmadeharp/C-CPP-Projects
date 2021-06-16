#include<iostream>
#include<SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include<vector>
#include"Interface.h"



GUI::GUI(sf::RenderWindow& window):
	windowSession(window)
{
	window.clear();
}

void GUI::event(sf::RenderWindow& window, bool e)
{
	sf::Event event;
	while(window.pollEvent(event))	{
		if (!e)	{
			window.close();	
		}
	}
}

void GUI::Session(bool state)
{			
	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window", sf::Style::Default);

}

void GUI::Close(sf::RenderWindow& window)
{
	window.close();
}

// Drawing Shapes
void GUI::drawCircle(float r)
{
	sf::CircleShape circle;
	circle.setRadius(150);
	circle.setPosition(400, 300);
	windowSession.draw(circle);
}

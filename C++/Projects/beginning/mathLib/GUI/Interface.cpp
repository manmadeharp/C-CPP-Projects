#include<iostream>
#include<SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include<vector>
#include"Interface.h"



GUI::GUI(sf::RenderWindow& window)
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

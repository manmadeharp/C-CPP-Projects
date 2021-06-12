#include<iostream>
#include<SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include<vector>
#include"Interface.h"



GUI::GUI()
{
	std::cout << "Test";
}

void GUI::event(sf::RenderWindow& window)
{
	sf::Event event;
	while(window.pollEvent(event))	{
		if (event.type == sf::Event::Closed)	{
			window.close();	
		}
	}
}
void GUI::Session(std::string& state)
{			
	std::cout << "test1";
	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window", sf::Style::Default);
	while (window.isOpen())	{
		GUI::event(window);

		// This clears the previos frame
		window.clear();
		
		// This displays the current frame	
		window.display();
	}	
}

#include<SFML/Graphics.hpp>
#include<vector>
#include<random>
#include<iostream>

sf::RenderWindow window(sf::VideoMode(1280, 720), "SFML window", sf::Style::Default);



void event()
{
	sf::Event event;
	while(window.pollEvent(event))	{
		if (event.type == sf::Event::Closed)	{
			window.close();	
		}
	}
}
int main()
{
			

	while (window.isOpen())	{
		event();

		

		// This clears the previos frame
		window.clear();
		
		// This displays the current frame	
		window.display();
	}	
}



#include<SFML/Graphics.hpp>
#include<vector>
#include<random>
#include<iostream>

std::random_device rng;
std::mt19937_64 dev(rng());


sf::RenderWindow window(sf::VideoMode(1280, 720), "SFML window", sf::Style::Default);

sf::Clock ctr;

sf::CircleShape circle;
sf::Vector2f pos;
sf::Vector2f vel;

bool mpressed;
sf::Vector2i mpos;
sf::Vector2f setPosition(sf::CircleShape circle, float x, float y)
{
		circle.setPosition(x, y);
		//std::cout << circle.getPosition().x << circle.getPosition().y;
		//std::cout << "test";
		return circle.getPosition();
}

sf::Vector2f ToMouse(sf::Vector2f circle)	{
	if (mpressed)	{
		sf::Vector2f dif = circle - sf::Vector2f(mpos);	
		vel.x = dif.x + 0.1;
		vel.y = dif.y + 0.1;
		
		//std::cout << " x: "<< dif.x << " y: " << dif.y << " \n Circle Position: " << circle.x << circle.y;
	}
	return vel;
}

int main()
{
	circle.setRadius(20);
	circle.setFillColor(sf::Color::White);
	circle.setOutlineThickness(5);
	mpos = sf::Mouse::getPosition(window);
	while (window.isOpen())	{
		sf::Event event;
		while(window.pollEvent(event))	{
			if (event.type == sf::Event::Closed)	{
				window.close();	
			}
			if(event.type == sf::Event::MouseMoved)
				mpos = sf::Mouse::getPosition(window);
		}

		mpressed = sf::Mouse::isButtonPressed(sf::Mouse::Left);
		

		// This clears the previos frame
		window.clear();
		// Circles position set no gradual change in position therefore no perceived velocity.
		//setPosition(circle, 100, 500);
		circle.setPosition(ToMouse(setPosition(circle, 100, 500)).x,ToMouse(setPosition(circle, 100, 500)).y);
		window.draw(circle);

		// This displays the current frame	
		window.display();
	}	
}



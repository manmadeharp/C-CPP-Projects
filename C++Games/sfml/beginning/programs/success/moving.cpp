// simple moving circle with WASD.
#include<SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include<vector>
#include<random>
#include<iostream>
// functions
void update();

sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "SFML window", sf::Style::Default);

// object position
sf::Vector2f pos = sf::Vector2f(200, 200);;
sf::Vector2f vel;
sf::CircleShape circle;
struct keys  {
	bool W = false;
	bool A = false;
	bool S = false;	
	bool D = false;
};
keys k;

void update()
{
	if(k.W || k.A || k.S || k.D)
		circle.setPosition(pos);	
}

keys actions(keys& k)
{
	if(k.W == true)	{
		//std::cout << "W key is pressed";
		pos += sf::Vector2f(0, -0.01);
	}
	if(k.A == true)	{
		pos += sf::Vector2f(-0.01, 0);
	}
	if(k.S == true)	{
		pos += sf::Vector2f(0, 0.01);
	}
	if(k.D == true)	{
		pos += sf::Vector2f(0.01, 0);
	}
	return k;
}

void events()
{
	sf::Event event;
	while(window.pollEvent(event))	{
		if	(event.type == sf::Event::Closed)	{
			window.close();	
		}
	}
}


int main()
{
	circle.setRadius(10);
	circle.setPosition(200, 200);
	while (window.isOpen())	{
		events();
		actions(k);
		update();
		k.W = sf::Keyboard::isKeyPressed(sf::Keyboard::W);
		k.A = sf::Keyboard::isKeyPressed(sf::Keyboard::A);
		k.S = sf::Keyboard::isKeyPressed(sf::Keyboard::S);
		k.D = sf::Keyboard::isKeyPressed(sf::Keyboard::D);

		// This clears the previos frame
		window.clear();
		window.draw(circle);
		// This displays the current frame	
		window.display();
	}	
}



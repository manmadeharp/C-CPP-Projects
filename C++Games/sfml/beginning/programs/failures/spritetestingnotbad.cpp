#include<SFML/Graphics.hpp>
#include<vector>
#include<random>
#include<iostream>
#include<thread>
#include<chrono>

sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "SFML window", sf::Style::Default);
// Sprites.
sf::Texture borgimg;
sf::Texture borgimg2;
sf::Sprite borgcomp;
sf::Sprite borg;
sf::Sprite borg2;
std::vector<sf::Texture> borgrunningup (5);
std::vector<sf::Texture> borgrunningdown(5);
std::vector<sf::Texture> borgrunningleft(5);
std::vector<sf::Texture> borgrunningright(5);
std::vector<int> test;
// Clock
sf::Clock ctr;
bool lpressed;

sf::Vector2i mpos;


struct keys {
	bool W;
	bool A;
	bool S;
	bool D;
};
keys k;


sf::Vector2i mouseposition()
{
	if(lpressed)	{
		mpos = sf::Vector2i(sf::Mouse::getPosition(window));
		//std::cout << " X: " << mpos.x << " Y: " << mpos.y << '\n';
	}
	return mpos;
}



void moveSprite()
{
	if ((k.W = sf::Keyboard::isKeyPressed(sf::Keyboard::W)) == true)	{
		borg.move(0, -0.5);
	}
	if ((k.A = sf::Keyboard::isKeyPressed(sf::Keyboard::A)) == true)	{
		borg.move(-0.5, 0);
	}
	if ((k.S = sf::Keyboard::isKeyPressed(sf::Keyboard::S)) == true)	{
		borg.move(0, 0.5);
	}
	if ((k.D = sf::Keyboard::isKeyPressed(sf::Keyboard::D)) == true)	{
		borg.move(0.5, 0);
	}
}



void displaysprite()
{
	//borgrunning[1].loadFromFile("/home/Finbar/CLionProjects/C++Games/sfml/assets/MiniWorldSprites/Characters/Champions/Borg.png", sf::IntRect(16, 0, 19, 17));
	for(float i = 0; i < 90; i+= 16)	{
		borgrunningdown[i/16].loadFromFile("/home/Finbar/CLionProjects/C++Games/sfml/assets/MiniWorldSprites/Characters/Champions/Borg.png", sf::IntRect(i, 0, 16, 16));
		borgrunningup[i/16].loadFromFile("/home/Finbar/CLionProjects/C++Games/sfml/assets/MiniWorldSprites/Characters/Champions/Borg.png", sf::IntRect(i, 16, 16, 16));
		borgrunningleft[i/16].loadFromFile("/home/Finbar/CLionProjects/C++Games/sfml/assets/MiniWorldSprites/Characters/Champions/Borg.png", sf::IntRect(i, 32, 16, 16));
		borgrunningright[i/16].loadFromFile("/home/Finbar/CLionProjects/C++Games/sfml/assets/MiniWorldSprites/Characters/Champions/Borg.png", sf::IntRect(i, 48, 16, 16));
	}
	
	if(k.W == true)	{
		sf::Time initTime = ctr.getElapsedTime();
		if(initTime > sf::seconds(1))
			std::cout << initTime.asSeconds() << '\n';

		for(int i = 0; i < 6; i++)	{
				if (initTime > sf::seconds(i) && initTime < sf::seconds(i + 1))	{
					borg.setTexture(borgrunningup[i]);
					window.draw(borg);
				}
		}
	
		for(int i = borgrunningup.size(); i > 2; i--)	{
				if (initTime > sf::seconds((6 + (i*-1) + 4)) && initTime < sf::seconds((6 + (i*-1) + 5)))	{
					borg.setTexture(borgrunningup[i - 2]);
					window.draw(borg);
				}
		}

		if(initTime > sf::seconds(8))	{
				ctr.restart();
		}
	}
	else	{
		borg.setTexture(borgrunningup[0]);
		window.draw(borg);
	}
}

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
	// For non-cut sprite	
	if (!borgimg.loadFromFile("/home/Finbar/CLionProjects/C++Games/sfml/assets/MiniWorldSprites/Characters/Champions/Borg.png"))
   		return -1;

	borgcomp.setTexture(borgimg);
	borgcomp.setScale(2, 2);
	// For Cut sprite
	if (!borgimg2.loadFromFile("/home/Finbar/CLionProjects/C++Games/sfml/assets/MiniWorldSprites/Characters/Champions/Borg.png", sf::IntRect(0,0,15,18)))
   		return -1;

	borgimg2.setSmooth(true);
	borg.setTexture(borgimg2);
	borg.setPosition(200, 200);
	borg2.setPosition(250, 250);
	borg.setScale(4, 4);

	while (window.isOpen())	{
		event();
		mouseposition();
		lpressed = sf::Mouse::isButtonPressed(sf::Mouse::Left);

		// This clears the previos frame
		window.clear();
		
		window.draw(borgcomp);
		
		displaysprite();
		
		moveSprite();
		// This displays the current frame	
		window.display();
	}	
}



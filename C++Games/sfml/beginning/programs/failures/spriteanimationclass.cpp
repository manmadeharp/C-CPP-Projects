#include<SFML/Graphics.hpp>
#include<vector>
#include<random>
#include<iostream>

sf::RenderWindow window(sf::VideoMode(1280, 720), "SFML window", sf::Style::Default);
sf::Clock ctr;

struct spritesheet	{
	int wcol;
	int wrow;
	int acol;
	int arow;	
};
spritesheet sprite;
struct keyboard {
	bool W, S, A, D;
};

class characters	
{
	private:
		spritesheet charactersheet;
		std::string characterurl;
	public:
		characters(std::string spriteurl, spritesheet spriteactions);
		sf::Sprite character;
		void test();
		void draw();
		
		// characters constructor needs to take the file location and store necessary sprites in array.
		// `--> different number of sprites depending on action (walking attacking) therefore need to take in more than 1 int for number of sprites for different actions
		
		// need to define struct or enum for different actions 
		// need to define how sprites are animated
		
		// need to be able to draw the characters based on input
	
};

characters::characters(std::string spriteurl, spritesheet sprite):
	charactersheet(sprite),
	characterurl(spriteurl)
{
	
	//std::vector<std::vector<sf::Texture>> charwalk(sprite.wrow, std::vector<sf::Texture>(sprite.wcol));
	//std::vector<std::vector<sf::Texture>> charattack(sprite.arow, std::vector<sf::Texture>(sprite.acol));
	//charwalk.resize(sprite.wrow, std::vector<sf::Texture>(sprite.wcol));
	//charattack.resize(sprite.arow, std::vector<sf::Texture>(sprite.acol));
//	for(int i = 0; i < sprite.wrow; i++)	{
//		for(int j = 0; j < sprite.wcol; j+=16)	{
//			charwalk[i][j/16].loadFromFile(spriteurl, sf::IntRect(j, i*16, 16, 16));
//		}
//	}
//	for(int i = 0; i <= sprite.arow; i++)	{
//		for(int j = 0; j <= sprite.acol; j+=16)	{
//			charattack[i][j/16].loadFromFile(spriteurl, sf::IntRect(j, 60+i*16, 16, 16)); 
//		}
//	}
}

void characters::draw()
{
	//character.setTexture(charwalk[0][0]);
	window.draw(character);
}

void characters::test()
{
	std::cout << charactersheet.wcol << charactersheet.acol << characterurl;
}

class champion : public characters	
{
	private:
		// define characters own clock
	public:
		// define move animations
		
		champion(std::string spriteurl, spritesheet spriteactions);

};

champion::champion(std::string spriteurl, spritesheet spriteactions):
	characters(spriteurl, spriteactions)
{
}

std::vector<sf::Sprite> borg;

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
	spritesheet borgsheet = {5, 4, 6, 4};
	characters borg{"/home/Finbar/CLionProjects/C++Games/sfml/assets/MiniWorldSprites/Characters/Champions/Borg.png", borgsheet};
	
	borg.character.setPosition(200, 200);
	
	borg.test();
	
	while (window.isOpen())	{
		event();

		

		// This clears the previos frame
		window.clear();
		borg.draw();
		// This displays the current frame	
		window.display();
	}	
}



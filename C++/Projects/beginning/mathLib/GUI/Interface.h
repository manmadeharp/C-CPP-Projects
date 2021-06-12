#ifndef Interface_h
#define Interface_h
#include<string>
#include<iostream>
#include<SFML/Window.hpp>
#include<SFML/Graphics.hpp>
void GUI_Window(std::string& state);
class GUI	
{
	public:	
		int i = 0;
		std::iostream* OStream;
		GUI();
		void Session(std::string& state);
	private:
		void event(sf::RenderWindow& window);	
		std::string OpenOrClose;
};
#endif

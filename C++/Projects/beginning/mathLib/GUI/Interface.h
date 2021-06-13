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
		GUI(sf::RenderWindow&);
		virtual void Session(bool state = true);
		void Close(sf::RenderWindow& window);
	private:
		void event(sf::RenderWindow& window, bool e);	
		std::string OpenOrClose;
};
#endif

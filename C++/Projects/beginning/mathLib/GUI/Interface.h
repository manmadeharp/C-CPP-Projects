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
		sf::RenderWindow& windowSession;
		GUI(sf::RenderWindow&);
		virtual void Session(bool state = true);
		void Close(sf::RenderWindow& window);
		// Drawing
		void drawCircle(float r);
	private:
		void event(sf::RenderWindow& window, bool e);	
		std::string OpenOrClose;
};
#endif

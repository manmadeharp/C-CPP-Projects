#include <SFML/Graphics.hpp>
#include <Windows.h>

int main()
{
	const int screenWidth = 800;
	const int screenHeight = 800;

	sf::RenderWindow Window (sf::VideoMode (screenWidth, screenHeight, 32), "Clock");

	float clockRadius = 350;
	float clockX = (screenWidth - 2 * clockRadius) / 2;
	float clockY = (screenHeight - 2 * clockRadius) / 2;

	float centerX = clockX + clockRadius;
	float centerY = clockY + clockRadius;

	sf::CircleShape clock (clockRadius, 360U);
	clock.setPosition (clockX, clockY);
	clock.setOutlineThickness (1.0f);
	clock.setOutlineColor (sf::Color::Black);
	clock.setFillColor (sf::Color::White);

	float centerRadius = 20;

	sf::CircleShape centerCircle = sf::CircleShape(centerRadius, 360);
	centerCircle.setPosition (centerX - centerRadius, centerY - centerRadius);
	centerCircle.setFillColor (sf::Color::Black);

	float hourHandLength = (10.0f/16.0f) * clockRadius;
	float minuteHandLength = (14.0f/16.0f) * clockRadius;
	float secondHandLength = (15.0f/16.0f) * clockRadius;

	float hourHandWidth = 6.0f;
	float minuteHandWidth = 6.0f;
	float secondHandWidth = 3.0f;

	float hour = 0.0f;
	float minute = 0.0f;
	float second = 0.0f;

	float hourHandAngle = 0.0f;
	float minuteHandAngle = 0.0f;
	float secondHandAngle = 0.0f;

	sf::RectangleShape hourHand;
	hourHand.setPosition (centerX, centerY - hourHandWidth / 2);
	hourHand.setSize (sf::Vector2f (hourHandLength, hourHandWidth));
	hourHand.setFillColor (sf::Color::Black);

	sf::RectangleShape minuteHand;
	minuteHand.setPosition (centerX, centerY - minuteHandWidth / 2);
	minuteHand.setSize (sf::Vector2f (minuteHandLength, minuteHandWidth));
	minuteHand.setFillColor (sf::Color::Black);
	
	sf::RectangleShape secondHand;
	secondHand.setPosition (centerX, centerY - secondHandWidth / 2);
	secondHand.setSize (sf::Vector2f (secondHandLength, secondHandWidth));
	secondHand.setFillColor (sf::Color::Black);

	while (Window.isOpen ())
	{
		sf::Event Event;

		// save the current system time (using windows.h)
		SYSTEMTIME systime;
		GetLocalTime(&systime);
		second = systime.wSecond;
		minute = systime.wMinute + second / 60;
		hour   = systime.wHour + minute / 60;
		
		// change the angle of the hour, minute and second hand
		hourHandAngle = (hour / 12.0f) * 360.0f - 90.0f;
		minuteHandAngle = (minute / 60.0f) * 360.0f - 90.0f;
		secondHandAngle = (second / 60.0f) * 360.0f - 90.0f;
		hourHand.setRotation (hourHandAngle);
		minuteHand.setRotation (minuteHandAngle);
		secondHand.setRotation (secondHandAngle);

		while(Window.pollEvent (Event))
		{
			switch(Event.type)
			{
				case sf::Event::Closed:
					Window.close ();
				break;
			}
		}

		Window.clear (sf::Color::White);
		Window.draw (clock);
		Window.draw (centerCircle);
		Window.draw (hourHand);
		Window.draw (minuteHand);
		Window.draw (secondHand);
		Window.display ();
	}

	return 0;
}
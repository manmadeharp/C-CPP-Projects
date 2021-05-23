// Simple Critter
// Demonstrates how to use classes
#include<iostream>

class Critter
{
	public:
		int m_hunger;
		void Greet();
};
void Critter::Greet()
{
	std::cout << "hello i am a critter my hunger level is " << m_hunger << ".\n";
}

int main()
{
	Critter crit1;
	Critter crit2;

	crit1.m_hunger = 9;
	std::cout << "crti1's hunger is " << crit1.m_hunger << std::endl;
	
	crit2.m_hunger = 3;
	std::cout << "crit2's hunger is " << crit2.m_hunger << std::endl;

	crit1.Greet();
	crit2.Greet();

	return 0;
}

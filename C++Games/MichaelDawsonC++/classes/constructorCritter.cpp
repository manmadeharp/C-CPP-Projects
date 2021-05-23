// demonstrates constructors

#include<iostream>

using namespace std;

class Critter
{
	public:
		int m_hunger;
		Critter(int hunger = 0); // Constructor Prototype must be the same name as class
		void Greet();
};

Critter::Critter(int hunger)
{
	std::cout << "A new critter has been born!" << endl;
	m_hunger = hunger; 
}

void Critter::Greet()
{
	std::cout << " my hunger level is" << m_hunger;
}

int main()
{
	Critter crit(7);
	crit.Greet();

	return 0;
}

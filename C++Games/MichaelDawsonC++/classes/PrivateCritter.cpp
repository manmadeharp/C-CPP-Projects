// demonstrates use of private in classes and also demonstrates constructor member initialization.

#include<iostream>

using namespace std;

class Critter
{
	public:
		Critter(int hunger = 0);
		int GetHunger() const;
		void SetHunger(int hunger);
	private:
		int m_hunger;
};
Critter::Critter(int hunger):
	m_hunger(hunger)
{
	std::cout << " A new Critter has been born" << std::endl;
}

int Critter::GetHunger() const 
{
	return m_hunger;
}

void Critter::SetHunger(int hunger)
{
	if(hunger<0)	{
		std::cout << "critters number can't be negative";
	}
	else	{
		m_hunger = hunger;
	}
}

int main()
{
	Critter crit(5);
	std::cout << "getNumber" << crit.GetHunger() << std::endl;

	Critter crit2(-5);
	crit.SetHunger(9);
	std::cout << "SetNumber to 9 now getting hunger" << crit.GetHunger() << std::endl;
}


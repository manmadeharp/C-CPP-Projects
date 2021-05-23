// demonstrates static initialization in classes
#include <iostream>


class Critter
{
	public:
		static int s_Total; // static member;

		Critter(int hunger = 0);
		static int GetTotal();
	private:
		int m_hunger;
};

int Critter::s_Total = 0; // static member initialization.

Critter::Critter(int hunger):
	m_hunger(hunger)
{
	std::cout << "A Critter has been bron!" << std::endl;

	++s_Total;
}

int Critter::GetTotal()
{
	return s_Total;
}

int main()
{
	std::cout << "Total number of Critters is: " << std::endl;
	std::cout << Critter::s_Total << "\n\n";

	Critter crit1, crit2, crit3;

	std::cout << "Total number of critters now is: "
			  << Critter::s_Total << "\n";
	return 0;
}

// putting it all together to make a game

#include<iostream>

using namespace std;


class Critter
{
	public:
		Critter(int hunger = 0, int boredom = 0);
		void Talk();
		void Eat(int food = 4);
		void Play(int fun = 4);
		
	private:
		int m_hunger;
		int m_boredom;
		int GetMood() const;
		void PassTime(int time = 1);
};

Critter::Critter(int hunger , int boredom):
	m_hunger(hunger),
	m_boredom(boredom)
{}

inline int Critter::GetMood() const
{
	return (m_hunger + m_boredom);
}

void Critter::PassTime(int time)
{
	m_hunger += time;
	m_boredom+= time;
}
void Critter::Talk()
{
	std::cout << "I feel";

	int mood = GetMood();
	if (mood > 15)	{
		std::cout << " Mad. \n";
	}
	if (mood>10)	{
		std::cout << " Sad. \n";
	}
	else	{
		std::cout << " Pretty Good. \n";
	}
}


void Critter::Eat(int food)
{
	std::cout << "yum \n";
	
	m_hunger -= food;
	if (m_hunger < 0)	{
		m_hunger = 0;
	}
	PassTime();
}


void Critter::Play(int fun)
{
	std::cout << "We are currently in the process of play\n";

	m_boredom -= fun;
	if(m_boredom < 0)	{
		m_boredom = 0;
	}
	
	PassTime();
}


int main()
{
	Critter crit;
	
	crit.Talk();
		
	int choice;
	do	{
		std::cout << "Welcome to Critter CareTaker\n";
		std::cout << "0 - Quit\n";
		std::cout << "1 - Listen to your critter\n";
		std::cout << "2 - Feed your critter\n";
		std::cout << "3 - Play with your critter\n";
		std::cout << "Choice: ";
		std::cin >> choice;

		switch(choice)	{
			case 0:
				std::cout << "Goodbye."; break;
			case 1:
				crit.Talk(); break;
			case 2:
				crit.Eat(); break;
			case 3:
				crit.Play(); break;
			default:
				std::cout << "\nSorry, but " << choice << " isn't a valid choice. \n";
 
		}

	} while(choice != 0);
}





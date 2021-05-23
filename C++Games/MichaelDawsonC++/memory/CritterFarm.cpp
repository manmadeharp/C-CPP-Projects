// Demonstrates Aggregation + Object containment.

#include<iostream>
#include<string>
#include<vector>


class Critter
{
	public:	
		Critter(const std::string& name  = "");
		std::string GetName() const;

	private:
		std::string m_name;
};

Critter::Critter(const std::string& name):
	m_name(name)
{}

inline std::string Critter::GetName() const
{
	return m_name;
}

class Farm
{
	public:
		Farm(int spaces = 1);
		void Add(const Critter& aCritter);
		void RollCall() const;
	
	private:
		std::vector<Critter> m_Critters;
};

Farm::Farm(int space)
{
	m_Critters.reserve(space); // Reserves space for the critter to be added to the vector.
}

void Farm::Add(const Critter& aCritter)
{
	m_Critters.push_back(aCritter);
}

void Farm::RollCall() const
{
	for(std::vector<Critter>::const_iterator iter = m_Critters.begin();
		iter != m_Critters.end();
		++iter)	{
		std::cout << iter->GetName() << ". here.\n";
	}
}

int main()
{
	Critter crit("Poochie");
	std::cout << "My critters name is " << crit.GetName() << std::endl;
	
	std::cout << "Creating Critter Farm\n";
	
	Farm myFarm(3);

	std::cout << "Adding 3 Critters to my farm \n";
	myFarm.Add(Critter("Moe"));		
	myFarm.Add(Critter("Jamie"));		
	myFarm.Add(Critter("Finbar"));		
	
	myFarm.RollCall();

	return 0;
}






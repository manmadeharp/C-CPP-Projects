// demonstrates friend functions + Operator Overloading.

#include<iostream>
#include<string>

class Critter
{
	// make global functions 'Friends' of the critter class.
	friend void Peek(const Critter& aCritter);
	friend std::ostream& operator << (std::ostream& os, const Critter& aCritter);
	
	public:
		Critter(const std::string& name = "");
	
	private:
		std::string m_name;
};	

Critter::Critter(const std::string& name):
	m_name(name)
{}

void Peek(const Critter& aCritter);
std::ostream& operator << (std::ostream& os, const Critter& aCritter);
	
int main()
{
	Critter crit("poochie");
	
	std::cout << "calling Peek to access critter private data\n";
	Peek(crit);

	std::cout << "\nsending crit object to cout with << operator: \n";
	std::cout << crit;
}

void Peek(const Critter& aCritter)
{
	std::cout << aCritter.m_name << std::endl;
}


// overloads the operator so you can send a critter object to cout
std::ostream& operator<<(std::ostream& os, const Critter& aCritter)
{
	os << "Critter Object - ";
	os << " m_name: " << aCritter.m_name;
	return os;
}


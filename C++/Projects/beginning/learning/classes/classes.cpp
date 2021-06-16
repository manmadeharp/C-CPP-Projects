// All about classes in general
// Section 1
// --------------------------------
// What are classes how do they work what are the things that I can do with them
// Not just classes but all class-like mechanisms
#include<iostream>
#include<vector>

// Structs are classes where the members are public therefore they can use constructors
struct Structure	
{
	int i = 0;
	std::vector<int> Vec;
	Structure(int& SO) ;
};
Structure::Structure(int& SO)
{
	Vec.push_back(SO);
}
enum class EnumClass	
{
	
};

class SuperClass
{
	public:
		SuperClass(int& i); // constructor
		Structure* p;
	private:
		int notouchy;
	
};

SuperClass::SuperClass(int& i):
	notouchy(i)
{
	std::cout << "this class was instantiated in an object" << '\n';
}

// Shows the enum class and struct uses
class DerivedClass1 : SuperClass
{
	public:
		int i = 5;
		Structure SI{i};
		void PrintStruct();
		DerivedClass1();
	private:
		std::string privateWord;
};

DerivedClass1::DerivedClass1():
	SuperClass(i)
{}

void DerivedClass1::PrintStruct()
{
	std::cout << SI.Vec[0] << " Contents \n";
}

class DerivedClass2 : SuperClass
{
	public:
		DerivedClass2(); 
		void populate();
		std::vector<std::vector<int>> TDIntVec;
		int i = 5;
	private:
};

DerivedClass2::DerivedClass2():
	SuperClass(i)
{
	TDIntVec.resize(5, std::vector<int>(5));
}

void DerivedClass2::populate()
{
	for(int i = 0; i < TDIntVec.size(); i++)	{
		for(int j = 0; j < TDIntVec[i].size(); j++)	{
			TDIntVec[i][j] = (i*j*16+1);
			std::cout << TDIntVec[i][j] << '\n';
		}
	}
}

int main()
{
	DerivedClass1 example1;
	example1.PrintStruct();
	
	DerivedClass2 example2;

	example2.populate();
	
	
}

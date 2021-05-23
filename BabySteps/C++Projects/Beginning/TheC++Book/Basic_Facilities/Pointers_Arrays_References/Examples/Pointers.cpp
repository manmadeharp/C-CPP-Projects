#include <iostream>

int main()
{
	char c = 'a';
	char* p = &c;
	char c2 = *p;
	std::cout << c2 << "\n";
}



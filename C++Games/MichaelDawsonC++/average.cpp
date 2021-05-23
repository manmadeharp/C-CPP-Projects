// This simple program takes 3 Ints and provides the average of them
#include<iostream>

int main()
{
	int first, second, third;
	std::cout << "Please enter the first integer";
	std::cin >>	first;	
	std::cout << "Please enter second integer";
	std::cin >> second;
	std::cout << "Please enter third integer";
	std::cin >> third;
	
	std::cout << (third+second+first)/3 << '\n';
}

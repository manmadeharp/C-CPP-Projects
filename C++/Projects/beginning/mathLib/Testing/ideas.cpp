#include<iostream>

// I want to learn how to handle a function argument error so that when I setup the function in the parser of the calculator I can return an error
// if there arn't enough arguments
// 
int returnerrorarguments(int n, int i, int j)
{
	return n + i + j;
}


int main()
{
	std::cout << returnerrorarguments(5, 6) << '\n';
}

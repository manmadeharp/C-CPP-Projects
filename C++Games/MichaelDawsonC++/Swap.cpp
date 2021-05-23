// Demonstrates Reference use
// they are used with functions when you want to change the variable value in the function instead of copying it

#include<iostream>

void badSwap(int x, int y);
void goodSwap(int& x, int& y);

int main()
{
	int x = 100;
	int y = 350;
	std::cout << x << y << '\n';
	badSwap(x, y);
	std::cout << x << y << '\n';
	goodSwap(x, y);
	std::cout << x << y << '\n'; 
}

void badSwap(int x, int y)
{
	int temp = x;
	x = y;
	y = temp;
}

void goodSwap(int& x, int& y)
{
	int temp = x;
	x = y;
	y = temp;
}

#include<iostream>

int main()
{
	const int Rows = 3;
	const int Columns = 3;
	char boards[Rows][Columns] = { {'O', 'X', 'O'}, {'O', 'X', 'X'}, {' ', 'X', ' '} };
	

	std::cout << "Here is the tic tac board \n \n \n";
	for (int i = 0; i < Rows; ++i)	{
		for (int j = 0; j < Columns; ++j)	{
				std::cout << boards[i][j];
			}
		std::cout << std::endl;	
	}
	std::cout << "\n 'X' wins!";
	return 0;

}


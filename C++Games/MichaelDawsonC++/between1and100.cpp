// this game is based upon the game 
// Told by the Microsoft CEO gues the number between 1 and 100
// If you take more than 4 guess you pay me $10 for each extra guess
// if you guess less than 4 times I pay you $10 for each guess above 0
#include<iostream>
#include<cstdlib>
#include<ctime>
#include<cctype>
int main()
{
	std::srand(static_cast<unsigned int>(time(0)));
	
	int secretNumber = rand() % 100 + 1;
	int tries {0};
	int guess;

	std::cout << "welcome to the guessing game" << '\n';
	
	do	{
		std::cout <<"Enter your Guess ";
		std::cin >> guess;
		++tries;
		if (guess > secretNumber)	{
			std::cout << "Too high \n \n";
		}
		else if ( guess < secretNumber)	{
			std::cout << "Too Low \n \n";
		}
		else	{
			std::cout << "you got it in " << tries << " tries"<< '\n';
		}
	} while(guess != secretNumber);
}

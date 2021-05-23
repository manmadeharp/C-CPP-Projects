/*
Pseudocode example
Hangman
Big programs like this need planning if I am to save time.
*/
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<ctime>
#include<cctype>

int main()
{
	//setup
	const int MAX_WRONG = 8;
	
	std::vector<std::string> words;
	words.push_back("GUESS");
	words.push_back("HANGMAN");
	words.push_back("WORD");
	
	srand(static_cast<unsigned int>(time(0)));

	random_shuffle(words.begin(), words.end());

	const std::string THE_WORD = words [0];
	int wrong = 0;

	std::string soFar(THE_WORD.size(), '-');
	std::string used = "";
	
	std::cout << "Welcome to Hangman \n";

	while ((wrong < MAX_WRONG) && (soFar != THE_WORD))	{
		std::cout << "\n You have" << (MAX_WRONG - wrong);
		std::cout << "  guesses left. \n";
		std::cout << "you've used the following letters: \n " << used << std::endl;
		std::cout << "so far you got " << soFar << std::endl;	

		char guess;
		std::cout << "\n\nEnter The Guess ";
		std::cin >> guess;
		guess = std::toupper(guess);
		while (used.find(guess) != std::string::npos)	{
				std::cout << "\nYou've already guess " << guess << std::endl;
				std::cout << "Enter your Guess: ";
				std::cin >> guess;
				guess = std::toupper(guess);
		}
		used += guess;

		if (THE_WORD.find(guess) != std::string::npos)	{
			std::cout << "That's Right!" << guess << " is in the word \n";
			
			for (int i = 0; i < THE_WORD.length(); ++i)	{
				if (THE_WORD[i] == guess)	{
					soFar[i] = guess;
				}
			}
		}
		else	{
			std::cout << "Sorry, " << guess << " isn't in the word. \n";
			++wrong;
		}
		
	}
	std::cout << "congratulations you guessed the word " << THE_WORD << " as " << soFar;
	
}

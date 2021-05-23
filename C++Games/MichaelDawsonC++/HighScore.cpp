// High Scores
#include<vector>
#include<iostream>
#include<algorithm>
#include<ctime>
#include<cstdlib>

int main()
{
	std::vector<int>::const_iterator iter;
	std::cout << "creating a list of scores.";
	std::vector<int> scores;
	scores.push_back(1500);
	scores.push_back(3500);
	scores.push_back(5000);
	scores.push_back(4040);
	scores.push_back(5030);
	scores.push_back(9280);
	scores.push_back(3839);
	scores.push_back(4983);
	std::cout << "\n High Scores \n";
	for (iter = scores.begin(); iter != scores.end(); ++iter)
		std::cout << *iter << std::endl;
	int score;
	std::cout << "Please Enter a Score to find";
	std::cin >> score;
	iter = std::find(scores.begin(), scores.end(), score);
	if (iter != scores.end())	{
		std::cout << "Score Found \n";
	}
	else	{
		std::cout << "score not found \n";
	}
	
	std::cout << "\n Randomizing scores.";
	std::srand(static_cast<unsigned int>(time(0)));
	std::random_shuffle(scores.begin(), scores.end());
	std::cout << "\n High Scores \n";
	for (iter = scores.begin(); iter != scores.end(); ++iter)	{
		std::cout << *iter << std::endl;
	}
	
	std::cout << "\n using sort algorithm that People made for You.";
	std::sort(scores.begin(), scores.end());
	std::cout << "\n High Scores\n";
	for (iter = scores.begin(); iter != scores.end(); ++iter)
		std::cout << *iter << std::endl;
		
}

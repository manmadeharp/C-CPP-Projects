// Tic-Tac-Toe
//
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

const char X = 'X';
const char O = 'O';
const char EMPTY = ' ';
const char TIE = 'T';
const char No_One = 'N';

void instructions();
char askYesNo(string question);
int askNumber(string question, int high, int low = 0);
char humanPiece();
char opponent(char piece);
void displayBoard(const vector<char>& board);
char winner(const vector<char>& board);
bool isLegal(const vector<char>& board, char human);
int humanMove(const vector<char>& board, char human);
int computerMove(vector<char> board, char computer);
void announceWinner(char winner, char computer, char human);

int main()
{
	int move;
	const int NUM_SQUARES = 9;
	vector<char> board(NUM_SQUARES, EMPTY);
	
	instructions();
	char human = humanPiece();
	char computer = opponent(human);
	char turn = X;
	
	displayBoard(board);

	while (winner(board) == No_One)	{
		if (turn == human)	{
			move = humanMove(board, human);
			board[move] = human;
		}
		else	{
			move = computerMove(board, computer);
			board[move] = computer;
		}
		displayBoard(board);
		turn = opponent(turn);
	}
	announceWinner(winner(board), computer, human);
	
	return 0;
}

void instructions()
{
	std::cout << "Welcome to the ultimate man-machine showdown:"
			  << "\nchoose the move by entering 0-8 corresponging to each slot";
		
}

char askYesNo(string question)
{
	char response;
	do	{
		std::cout << question << " (y/n); ";
		cin >> response;
	} while(response != 'y' && response != 'n');
	return response;
}
	

int askNumber(string question, int high, int low)
{
	int number;
	do	{
		std::cout << low << '-' << high << ": ";
		std::cin >> number;
	} while (number > high || number < low);
	return number;
}
	


char humanPiece()	{
	char go_first = askYesNo("do you require the first move");
	if (go_first == 'y')	{
		std::cout << "\n then take the firs tmove. You will need it. \n";
		return X;
	}
	else	{
		std::cout << "I will go first \n"	;
		return O;
	}
	
	
}

char opponent(char piece)
{
	if(piece == X)
		return O;
	else
		return X;
}

void displayBoard(const vector<char>& board)
{
	int i = 0;
	std::cout << "\n\t" << "---------";
	while (i < board.size())	{
		std::cout << "\n\t" << board[i++] << " | " << board[i++] << " | " << board[i++];
		std::cout << "\n\t" << "---------";

	}
	std::cout << "\n\n";
}


char winner(const vector<char>& board)
{
	const int WINNING_ROWS[8][3] = { {0, 1, 2},
									 {3, 4, 5},
									 {6, 7, 8},
									 {0, 3, 6},
									 {1, 4, 7},
									 {2, 5, 8},
									 {0, 4, 8},
									 {2, 4, 6} };
	const int TOTAL_ROWS = 8;
	for(int row = 0; row < TOTAL_ROWS; ++row)	{
		if ((board[WINNING_ROWS[row][0]] !=EMPTY) &&
			(board[WINNING_ROWS[row][0]] == board[WINNING_ROWS[row][1]]) &&
			(board[WINNING_ROWS[row][1]] == board[WINNING_ROWS[row][2]])	)	{
			return board[WINNING_ROWS[row][0]];
		}
	}
	if (count(board.begin(), board.end(), EMPTY) == 0)
		return TIE;
		 
	return No_One;
}


inline bool isLegal(int move, const vector<char>& board)
{
	return (board[move] == EMPTY);
}

int humanMove(const vector<char>& board, char human)
{
	int move = askNumber("where will you move?", (board.size() - 1));
	while (!isLegal(move, board))
	{
		std::cout << "that square is occupied";
		move = askNumber ("where will you move", (board.size() -1));
	}
	std::cout << "moving";

	return move;	
}


int computerMove(vector<char> board, char computer)
{
	unsigned int move = 0;
	bool found = false;
	
	while (!found && move < board.size()){
		if(isLegal(move, board))	{
			board[move] = computer;
			found = winner(board) == computer;
			board[move] = EMPTY;
		}
		
		if (!found)	{
			++move;
		}
	}
	if (!found)	{
		move = 0;
		char human = opponent(computer);
		
		while(!found && move < board.size())	{
			if (isLegal(move, board))	{
				board[move] = human;
				found = winner(board) == human;
				board[move] = EMPTY;
			}

			if (!found)	{
				++move;
			}
		}
	}
	if(!found)	{
		move = 0;	
		unsigned int i = 0;
		
		const int BEST_MOVES[] = {4, 0, 2, 6, 8, 1, 3, 5, 7};
		
		while(!found && i < board.size())	{
			move = BEST_MOVES[i];
			if (isLegal(move, board))	{
				found = true;
			}
			++i;
		}
	}
	std::cout << "I shall take number " << move << std::endl;
	return move;
}

void announceWinner(char winner, char computer, char human)
{
	if (winner == computer)	
		std::cout << winner << "'s won!\n";
	
	
	else if (winner == human)
		std::cout << winner << "'s won \n";
	else
		std::cout << "it's a tie\n";
	

}







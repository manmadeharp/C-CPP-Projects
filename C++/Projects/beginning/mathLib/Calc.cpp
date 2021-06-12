// Calculator that uses the Math Lib
// Recursive Descent

// Compile Commands - g++  Calc.cpp  ./ALvlMath/SurdsIndices.cpp ./GUI/Interface.cpp -o Calculator -lsfml-graphics -lsfml-window -lsfml-system

// - g++  Calc.cpp  ./ALvlMath/SurdsIndices.cpp -o Calculator

#include<iostream>
#include<string>
#include<cctype>
#include<complex>
#include<map>
#include<sstream>
#include "./ALvlMath/SurdsIndices.h"
#include "./GUI/Interface.h"

// Functions
double term(bool get);
double expr(bool);

// Function Pointer
typedef float(*FnPtr)(std::map<int, float> arg);

// Maps
std::map<std::string, double> table;
std::map<int, float> arguments;
std::map<std::string, FnPtr> myMap;


int no_of_errors;

enum class Kind:char	{
	name, number, end, funct,
	plus='+',minus='-',mul='*',div='/',print=';',assign='=',lp='(',rp=')'
};

struct Token	{
	Kind kind;
	std::string string_value;
	double number_value;
};

// Function is here because it uses Token struct
double functParser(Token curTok, std::istream* ip, char ch, int c);

// error Message
double error(const std::string& s)
{
	no_of_errors++;
	std::cerr << "error: " << s << '\n';
	return 1;
}

class Token_stream	{
	public:
		Token_stream(std::istream& s) : ip{&s}, owns{false} {}
		Token_stream(std::istream* p) : ip{p}, owns{true} {}

		~Token_stream() { close(); }

		Token get();				// read and return next token
		const Token& current() { return ct; };		// most recently read token

		void set_input(std::istream& s)	{ close(); ip = &s; owns=false; }
		void set_input(std::istream* p)	{ close(); ip = p; owns=true; }
	private:
		void close() { if (owns) delete ip; }

		std::istream* ip;
		bool owns;
		Token ct {Kind::end};
};

Token Token_stream::get()
{
	char ch = 0;

	do	{
		if (!ip->get(ch)) return ct={Kind::end};
	} while (ch!='\n' && isspace(ch));

	switch(ch)	{
		case ';':
		case '\n':
			return ct={Kind::print};
		case '*':
		case '/':
		case '+':
		case '-':
		case '(':
		case ')':
		case '=':
			return ct={static_cast<Kind>(ch)};
		case '0':case '1':case '2':case '3':case '4':case '5':case '6':case '7':case '8':case '9':
		case '.':
			ip->putback(ch);
			*ip >> ct.number_value;
			ct.kind=Kind::number;
			return ct;
		default:
			if(isalpha(ch))	{
				ct.string_value = ch;
				while (ip->get(ch)) // same as *ip.get gets the next character
					if (isalnum(ch))
						ct.string_value += ch; // appends the letters to the current string value
					else if(ct.string_value == "GUI"){
						GUI UI; 
						UI.Session(ct.string_value);
						return ct;
					}
					else if (ch == '(') {
						ct.kind = Kind::funct;
						int c = 0;
						//while(ip ->get(ch))	{
						while(ch != '\n')	{
							ip->get(ch);
							if (ch == ',') c++;
							ct.number_value = functParser(ct, ip, ch, c);
							if(ct.number_value != 0 && ct.number_value != 5)
								return ct;
							if(ct.number_value == 0)
								return ct={Kind::print};
						}
						if(ct.number_value == 5)
							error("No ) detected");
						break;
					}
					
					else	{
						ip->putback(ch);
						break;
					}
				if(ct.kind != Kind::funct)
					ct.kind = Kind::name;
				return ct;
			}
			error("bad token");
			return ct={Kind::print};
	}
}

std::map<std::string, FnPtr> FunctList()
{
	std::map<std::string, FnPtr> functs;
	functs["root"] = root;	
	return functs;
}

double functGenerator(std::map<int, float> arg, Token tok)
{	
	// In order to execute the inputted function I need to point to the function that matches the variable input
	// I also need to pass the arguments from arg to the function. - try to find out if I can return the number of arguments required from a function

	std::map<std::string, FnPtr> functs = FunctList();
	
	float v = functs[tok.string_value](arg);
	//std::cout << '\n' << v << '\n';
	return v;
}

double functParser(Token curTok, std::istream* ip, char ch, int c)
{
	//std::cout << '\n' << curTok.string_value << '\n';

	//std::cout << '\n' << ch << '\n';


	if(isdigit(ch))	{
		ip->putback(ch);
		*ip >> arguments[c];
	}

	else if (isalpha(ch) && ch != ',')	{
		error("function cannot take string characters");
		return 0;
	}
	
	else if (ch == ')')	{
		return functGenerator(arguments, curTok);
	}

	//std::cout << '\n' << ch << '\t' << c << '\t' << arguments[c] << '\n';
	return 5;
	// return functGenerator;
}

Token_stream ts { std::cin };

double prim(bool get)
{
	if (get) ts.get();
	
	switch (ts.current().kind)	{
		case Kind::number:
		{	double v = ts.current().number_value;
			ts.get();
			return v;
		}
		case Kind::name:
		{
			double& v = table[ts.current().string_value];
			if (ts.get().kind == Kind::assign) v = expr(true);
			return v;
		}
		case Kind::lp:
		{
			auto e = expr(true);
			if (ts.current().kind != Kind::rp) return error(" ')' expected ");
			ts.get();
			return e;
		}
		case Kind::funct:
		{
			if(ts.current().number_value == 5)
				error("error with function calling");
			
			//std::cout << '\n' << "Function Value: " << ts.current().number_value << '\n'; 
			double v = ts.current().number_value;
			ts.get();
			return v;
		}
		default:
			return error("primrary expected");
	}
}

double term(bool get)
{
	double left = prim(get);
	
	for(;;)	{
		switch	(ts.current().kind)	{
			case Kind::mul:
				left*= prim(true);
				break;
			case Kind::div:
				if	(auto d = prim(true))	{
					left /= d;
					break;
				}
				return error("divide by 0");
			default:
				return left;
		}
	}
}

double expr(bool get)
{
	double left = term(get);

	for(;;)	{
		switch	(ts.current().kind)	{
			case Kind::plus:
				left += term(true);
				break;
			case Kind::minus:
				left -= term(true);
				break;
			default:
				return left;
		}
			
	}
}

// entry Point
void calculate()
{
	for (;;)	{
		ts.get();
		if (ts.current().kind == Kind::end) break;
		if (ts.current().kind == Kind::print) continue;
		std::cout << expr(false) << '\n';
	}
}

void constFunctions()
{
	// Constants
	table["pi"] = 3.1415926535897932385;
	table["e"] = 2.7182818284590452354;

	// Functions
}

int main(int argc, char* argv[])
{
	switch (argc)	{
		case 1:
			break;
		case 2:
			ts.set_input(new std::istringstream{argv[1]});
			break;
		default:
			error("Too many arguments");
			return 1;
	}
	constFunctions();

	calculate();
	return no_of_errors;
}	


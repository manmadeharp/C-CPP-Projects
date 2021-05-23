#include <iostream>
bool accept2();
int main()
{
	
	bool answer = accept2();
	if (answer == false)
		std::cout << "ok no then \n";
	if (answer == true)
		std::cout << "ok yes then \n";


}



// 

bool accept2()
{
		std::cout << "Do you want to proceed (y or n)?\n";
		char answer = 0;
		std::cin >> answer;
		switch (answer) {
		case 'y':
				return true;
		case 'n':
				return false;
		default:
				std::cout << "I'll take that for a no.\n";
				return false;
		}
}



void print()
{
	 
     int v[] = {0,1,2,3,4,5,6,7,8,9};
	
	 int* p = &v[3];          // p points to v's fourth element
	 int x = *p;
     for (auto x : v)            // for each x in v
           std::cout << x << '\n';

     for (auto x : {10,21,32,43,54,65})
           std::cout << x << '\n';
     // ...
}



void increment()
{
     int v[] = {0,1,2,3,4,5,6,7,8,9};

     for (auto& x : v)
           ++x;
     // ...
}



int count_x(char* p, char x)
     // count the number of occurrences of x in p[]
     // p is assumed to point to a zero-terminated array of char (or to nothing)
{
     if (p==nullptr) return 0;
     int count = 0;
     for (; *p!=0; ++p)
           if (*p==x)
                 ++count;
     return count;
}

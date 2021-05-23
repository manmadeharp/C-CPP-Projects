// demonstrates dynamically allocation memory / Memory Leaks / Heaps
#include<iostream>

int* intOnHeap();
void leak1();
void leak2();

int main()
{
	int* pHeap = new int;
	*pHeap = 10;
	std::cout << "*pheap: " << *pHeap << "\n\n";
	
	int* pHeap2 = intOnHeap();
	std::cout << "*pHeap2: " << *pHeap2 << std::endl;

	std::cout << "Freeing memory point to by pHeap." << std::endl;
	delete pHeap;

	std::cout << "Freeing memory pointed to by pHeap2." << std::endl;
	delete pHeap2;
		
	// Gets rid of pointers to nothing
	pHeap = 0;
	pHeap2 = 0;
}	

int* intOnHeap()
{
	int* pTemp = new int(20);
	return pTemp;
}

void leak1()
{
	int* drip1 = new int(30);
}

void leak2()
{
	int* drip2 = new int(50);
	drip2 = new int(100);
	delete drip2;
}	

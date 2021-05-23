#include <stdio.h>

// Statements and blocks
// expressions such as x = 0 become statements when x=0; the semi colon is added
// Binary Search
// It checks if x occurs in v (containing elements of increasing order) 
// It returns 0 - n-1 or -1 if nothing was found
int binsearch(int x, int v[], int n);
int main()
{
		int x = 4;
		int v[10];
		int n = 8;
		int answer = binsearch(x, v, n);
}

int binsearch(int x, int v[], int n)
{
		int low, high, mid;

		low = 0;
		high = n - 1;
		while (low <= high) {
				mid = (low+high)/2;
				if (x < v[mid])
						high = mid + 1;
				else if (x > v[mid])
						low = mid + 1;
				else  // found match
						return mid;
		}
		return -1; // no match
}

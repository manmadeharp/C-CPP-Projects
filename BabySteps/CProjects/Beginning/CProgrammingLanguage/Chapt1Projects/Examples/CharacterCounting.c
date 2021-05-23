#include <stdio.h>

// count the characters in input

int main()
{
	// First Version
//	long nc;
//	
//	nc = 0;
//	while (getchar() != EOF)
//		++nc;
//	printf("%ld\n", nc); //%ld for long integer
		
	// Second Version
	
	double nc;
	for (nc = 0; getchar() != EOF; ++nc)
		; // null statement
	printf("%.0f\n", nc); // %f is for float and double
	
}
// both while and for end at the start when the test is false

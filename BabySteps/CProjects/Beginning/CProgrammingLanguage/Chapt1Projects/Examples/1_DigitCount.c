#include <stdio.h>

// Counts White Spaces Digits and such

int main()
{
		int c, i, nwhite, nother;
		int ndigits[10]; // An Array Subscript of 10 integers

		nwhite = nother = 0;
		for (i = 0; i < 10; ++i)
				ndigits[i] = 0;
		while ((c = getchar()) != EOF)
				if (c >= '0' && c <= '9')
						++ndigits[c-'0'];
				else if (c == ' ' || c == '\n' || c =='\t')
						++nwhite;
				else 
						++nother;
		printf("digits =");
		for (i = 0; i < 10; ++i)
				printf(" %d", ndigits[i]);
		printf(", white space = %d, other = %d\n",
						nwhite, nother);
}

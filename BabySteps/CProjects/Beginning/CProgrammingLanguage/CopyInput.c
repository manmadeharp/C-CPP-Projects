#include <stdio.h>
// Copy input to output
int main()
{
	int c;

	c = getchar();
	while (c != EOF) { // EOF is a stdio.h library variable End Of File
		putchar(c);
		c = getchar();
		}
}

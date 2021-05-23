#include <stdio.h>

#define MAX 1000
int main()
{
	char c;
	char s[MAX];
	int i = 9;
	printf("test");
	while ((c = getchar()) != EOF){
		if(c == '\n')
//		printf("%c", c);
		if(c != '\n')
			s[i++] = c;

		printf("%s", s);

	}
}

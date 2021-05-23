#include <stdio.h>
#define MAXLINE 1000

int getNextline(char line[], int max);
int strindex(char s[], char t[], int p);

char pattern[] = "wood";

int main()
{
	char line[MAXLINE];
	int position;
	while (getNextline(line, MAXLINE) > 0){
		if (strindex(line, pattern, position) >= 0)
			;
//			printf("%i", position);;
	}
	return 0;
	
}

int getNextline(char s[], int lim)
{
	int c, i;
	i = 0;
	while(--lim >0 && (c = getchar()) != EOF && c !='\n')
		s[i++] = c;
	if (c == '\n')
		s[i++] = c;
	s[i] = '\0';
	return i;	
}

int strindex(char s[], char t[], int p)
{
	;		
}

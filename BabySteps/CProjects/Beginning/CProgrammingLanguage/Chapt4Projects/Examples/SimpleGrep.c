#include <stdio.h>
#define MAXLINE 1000
// fullfilment of Big Ambition requires Big Sacrifice but Planning strategy and intelligence can soften the deal
int getNextLine(char line[], int max);
int strindex(char source[], char searchfor[]);

char pattern[] = "would";

int main()
{
	char line[MAXLINE];
	int found = 0;

	while (getNextLine(line, MAXLINE) > 0)
		if (strindex(line, pattern) >= 0) {
			printf("%s", line); // line seems to chang synonimously with char s in strindex this must be to do with pointers
			found++;
		}
	return found;
}

int getNextLine(char s[], int lim)
{
	int c, i;
   /*
	* Pseudocode 
	* While loop
	* each time the while loops test case is evaluated each statement is executed
	* `--> with each new line the lim must decrease by 1 therefore --lim
	
	* `--> && means all expressions must be true
	*/


	i = 0;
	while (--lim > 0 && (c=getchar()) != EOF && c != '\n') 
		s[i++] = c;
	if(c == '\n')
		s[i++] = c;
	s[i] = '\0';
	return i;
}

// return index of t in s, -1 if none
int strindex(char s[], char t[]) 
// s is the character array storing each character of the pattern if it appears in the input [g, g, a, h, j, k, W, O, U, L, D]
// t is the actuall pattern for s to be compared to [w, o, u, l, d]
{
	int i, j, k;
   /* Pseudocode
	* First For Loop - as long as the next item in array is not a null character then continue and i++

	* Second For Loop - initialization everytime the 1st loop occurs. 
	* `--> j = i - i is where . k = 0 - k is where the initial letter in the pattern array is. 

	* `--> as long as t[k] is not equal to a null constant.

	* `--> And s[j] and t[k] are equal.
	
	* `--> i marks the point in the index where pattern begins

	* `--> j marks the position of the current next char in the pattern in terms of the line

	* `--> k marks the position within the pattern 
	*/
	for (i = 0; s[i] != '\0'; i++) {
		for (j=i, k=0; t[k]!='\0' && s[j]==t[k]; j++, k++)
			;
		if (k > 0 && t[k] == '\0')
			return i; // function repeats due to loop at main so once returned the function repeats  
	}	
	return -1;
}

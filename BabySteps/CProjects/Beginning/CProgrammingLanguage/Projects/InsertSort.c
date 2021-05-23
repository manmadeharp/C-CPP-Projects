#include <stdio.h>

#define MAXLINE 1000
int InsertSort(char s[]);
int main()
{
	int c, i;
	char s[MAXLINE];
	for(i = 0; (c = getchar()) != '\n'; i++){
		s[i] = c;
	}
	s[i+1] = '\0';
	InsertSort(s);
	//printf("%s \n", s);
	
}
int InsertSort(char s[])
{
   /*
	* Pseudocode
	* i = 0
	* while each 
	*/
	int i, j;
	char t;
	char k[MAXLINE];
	for(i = 0; s[i]!='\0'; i++){
		if (s[i] > s[i + 1]){
				k[i] = s[i+1];
				k[i+1] = s[i];			
				j += 1;
		}
	}
	printf("%s", k);
	return -1;
	
}
/*
	* Learnt:
	*
	*
*/

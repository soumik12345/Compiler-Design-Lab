#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main() {
	printf("Enter a string: ");
	char s[100];
	gets(s);
	if(strlen(s) == 1 && ((s[0] >= '0' && s[0] <= '9') || (s[0] >= 'a' && s[0] <= 'z') || (s[0] >= 'A' && s[0] <= 'Z')))
		printf("String Accepted\n");
	else
		printf("String not accepted\n");
}

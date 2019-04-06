#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main() {
	printf("Enter a string: ");
	char s[100];
	gets(s);
	printf("Enter the string to be searched:");
	char sub[50];
	gets(sub);
	char *ret;
	ret = strstr(s, sub);
	if(ret == NULL)
		printf("Substring not found\n");
	else
		printf("Substring found\n");
}

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int is_keyword(char* token) {
	char keywords[4][10] = {"int", "float", "double", "boolean"};
	int i, n = 4;
	for(i = 0; i < n; i++)
		if(strcmp(token, keywords[i]) == 0)
			return 1;
	return 0;
}

int is_operator(char token) {
	char operators[20] = {'+', '-', '*', '/', '=', '%', '.', '<', '>', '!', '&', '|', '?', ':'};
	int i, n = sizeof(operators) / sizeof(char);
	for(i = 0; i < n; i++)
		if(token == operators[i])
			return 1;
	return 0;
}

int is_seperator(char token) {
	char operators[20] = {',', ';', '(', ')', '{', '}', '[', ']'};
	int i, n = sizeof(operators) / sizeof(char);
	for(i = 0; i < n; i++)
		if(token == operators[i])
			return 1;
	return 0;
}

int is_identifier(char* token) {
	if(!((token[0] >= 'a' && token[0] <= 'z') || (token[0] >= 'A' && token[0] <= 'Z') || token[0] == '_'))
		return 0;
	int i;
	for(i = 1; token[i] != '\0'; i++)
		if(!((token[i] >= 'a' && token[i] <= 'z') || (token[i] >= 'A' && token[i] <= 'Z') || (token[i] >= '0' && token[i] <= '9') || token[i] == '_'))
			return 0;
	return 1;
}

int main() {
	char str[500] = "if(a+b==c)";
//	char str[500] = "int a = 10+20, b = 20;";
	printf("%s\n", str);
	char s[2] = " ";
	//gets(str);
	char* token;
	token = strtok(str, s);
	while(token != NULL) {
		// Checking for operator
		if(strlen(token) == 1 && is_operator(token[0]))
			printf("Operator ---> %s\n", token);
		// Checking for seperator
		if(strlen(token) == 1 && is_seperator(token[0]))
			printf("Seperator ---> %s\n", token);
		// Checking for keyword
		else if(is_keyword(token))
			printf("Keyword ---> %s\n", token);
		else if(is_identifier(token))
			printf("Identifier ---> %s\n", token);
		else {
			int i = 0;
			char con[100] = "";
			for(i = 0; token[i] != '\0'; i++) {
				if(token[i] >= '0' || token[i] <='9') {
					char inter[2];
					inter[0] = token[i];
					strcat(con, inter);
				}
				if(is_operator(token[i])) {
					printf("Constant ---> %s\n", con);
					printf("Operator ---> %c\n", token[i]);
					strcpy(con, "");
				}
				else if(is_seperator(token[i])) {
					printf("Constant ---> %s\n", con);
					printf("Seperator ---> %c\n", token[i]);
					strcpy(con, "");
				}
			}
		}
		token = strtok(NULL, s);
	}
}

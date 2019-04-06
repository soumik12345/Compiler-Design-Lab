// Code Courtesy: https://gist.github.com/devpruthvi/60aaf59e7cdf1cff3f3e#gistcomment-2776269

#include<stdio.h>
#include<string.h>

int main()  {
    char input[100], *l, *r, *temp, temp_prod[20], productions[25][50];
    int i = 0, j = 0, flag = 0;
    printf("Enter the productions: ");
    scanf("%s", input);
    l = strtok(input, "->");
    r = strtok(NULL, "->");
    temp = strtok(r, "|");
    while(temp)  {
        if(temp[0] == l[0])  {
            flag = 1;
            sprintf(productions[i++], "%s'->%s%s'\0", l, temp + 1, l);
        }
        else
            sprintf(productions[i++], "%s->%s%s'\0", l, temp, l);
        temp = strtok(NULL, "|");
    }
    sprintf(productions[i++], "%s'->\u03B5", l);
    if(flag == 0)
        printf("The given production doesn't have Left Recursion");
    else
        for(j = 0; j < i; j++)
            printf("\n%s", productions[j]);
    return 0;
}
#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fptr;
    char file_name[200], c;
    
    printf("Enter the filename: ");
    scanf("%s", file_name);

    // Open File
    fptr = fopen(file_name, "r");
    if(fptr == NULL) {
        printf("Unable to open file\n");
        return 0;
    }
    
    // Read Contents of file
    c = fgetc(fptr);
    while(c != EOF) {
        printf("%c", c);
        c = fgetc(fptr);
    }

    fclose(fptr);
    return 0;
}
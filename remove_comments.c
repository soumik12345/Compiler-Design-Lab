#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fptr;
    char file_name[200], c, file_contents[10000], removed_file_contents[10000];
    int counter = 0, counter_removed = 0, i = 0, n_single_lined_comments = 0, n_multi_lined_comments = 0;
    
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
        file_contents[counter++] = c;
        c = fgetc(fptr);
    }

    /*
    for(i = 0; i <= counter; i++) {
        printf("%c", file_contents[i]);
    } */

    // 0 means inside comment, 1 means outside comment
    int comment_state = 0;

    for(i = 0; i <= counter; i++) {
        if(comment_state == 0) {
            if(file_contents[i] == '/' && file_contents[i + 1] == '/')
                comment_state = 1;
            else if(file_contents[i] == '/' && file_contents[i + 1] == '*')
                comment_state = 1;
        } else {
            if(file_contents[i] == '\n' || i == counter) {
                comment_state = 0;
                n_single_lined_comments++;
            }
            else if(file_contents[i] == '*' || file_contents[i] == '\\' || i == counter) {
                comment_state = 0;
                n_multi_lined_comments++;
            }
        }
        if(comment_state == 0)
            removed_file_contents[counter_removed++] = file_contents[i];
    }

    // printf("Number of Single Line Comments: %d", n_single_lined_comments);
    // printf("Number of Multi Line Comments: %d", n_multi_lined_comments);

    for(i = 0; i <= counter_removed; i++)
        printf("%c", removed_file_contents[i]);

    fclose(fptr);
    return 0;
}
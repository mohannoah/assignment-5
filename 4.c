#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1000

int main() {
    char filename[MAX_LENGTH], search_string[MAX_LENGTH], line[MAX_LENGTH];
    FILE *fp;

    printf("Enter the name of the file: ");
    fgets(filename, MAX_LENGTH, stdin);

    // remove newline character from filename
    filename[strcspn(filename, "\n")] = '\0';

    printf("Enter the search string: ");
    fgets(search_string, MAX_LENGTH, stdin);

    // remove newline character from search_string
    search_string[strcspn(search_string, "\n")] = '\0';

    fp = fopen(filename, "r");

    if(fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    printf("Lines containing \"%s\":\n", search_string);

    while(fgets(line, MAX_LENGTH, fp) != NULL) {
        if(strstr(line, search_string) != NULL) {
            printf("%s", line);
        }
    }

    fclose(fp);

    return 0;
}

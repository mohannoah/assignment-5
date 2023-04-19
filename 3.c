#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 1000

int main() {
    FILE *input_file, *output_file;
    char line[MAX_LENGTH], *ptr;

    input_file = fopen("input.txt", "r");
    output_file = fopen("output.txt", "w");

    if(input_file == NULL || output_file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    while(fgets(line, MAX_LENGTH, input_file) != NULL) {
        ptr = strstr(line, "red");

        while(ptr != NULL) {
            strncpy(ptr, "blue", 4);
            ptr = strstr(ptr + 1, "red");
        }

        fputs(line, output_file);
    }

    fclose(input_file);
    fclose(output_file);

    return 0;
}

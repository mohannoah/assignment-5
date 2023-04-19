#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000

int main() {
    char* input_filename = "input.txt";
    char* error_filename = "error_log.txt";
    char line[MAX_LINE_LENGTH];

    FILE* input_file = fopen(input_filename, "r");
    if (input_file == NULL) {
        fprintf(stderr, "Error: could not open file %s for reading\n", input_filename);
        exit(1);
    }

    FILE* error_file = fopen(error_filename, "w");
    if (error_file == NULL) {
        fprintf(stderr, "Error: could not open file %s for writing\n", error_filename);
        exit(1);
    }

    while (fgets(line, MAX_LINE_LENGTH, input_file)) {
        if (strstr(line, "error") != NULL) {
            fputs(line, error_file);
        }
    }

    fclose(input_file);
    fclose(error_file);

    error_file = fopen(error_filename, "r");
    if (error_file == NULL) {
        fprintf(stderr, "Error: could not open file %s for reading\n", error_filename);
        exit(1);
    }

    while (fgets(line, MAX_LINE_LENGTH, error_file)) {
        printf("%s", line);
    }

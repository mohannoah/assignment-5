#include <stdio.h>
#include <ctype.h>

#define ALPHABET_SIZE 26

int main() {
    FILE *input_file, *output_file;
    int letter_count[ALPHABET_SIZE] = {0};
    char c;

    input_file = fopen("data.txt", "r");
    output_file = fopen("statistics.txt", "w");

    if(input_file == NULL || output_file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    while((c = fgetc(input_file)) != EOF) {
        if(isalpha(c)) {
            c = toupper(c);
            letter_count[c - 'A']++;
        }
    }

    fprintf(output_file, "Statistics:\n");

    for(int i = 0; i < ALPHABET_SIZE; i++) {
        fprintf(output_file, "%c: %d\n", 'A' + i, letter_count[i]);
    }

    fclose(input_file);
    fclose(output_file);

    return 0;
}

#include <stdio.h>

int main() {
    FILE *fp;
    int data[1000];
    int i, n;

    fp = fopen("data.bin", "rb");

    if(fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    n = fread(data, sizeof(int), 1000, fp);

    printf("Data in human-readable format:\n");

    for(i = 0; i < n; i++) {
        printf("%d ", data[i]);
    }

    printf("\n");

    fclose(fp);

    return 0;
}

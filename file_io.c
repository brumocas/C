#include <stdio.h>

int main() {
    FILE *fptr;
    char filename[100], c;

    printf("Enter the filename to open for reading: ");
    scanf("%s", filename);

    fptr = fopen(filename, "r");
    if (fptr == NULL) {
        printf("Cannot open file \n");
        return 0;
    }

    c = fgetc(fptr);
    while (c != EOF) {
        printf("%c", c);
        c = fgetc(fptr);
    }

    fclose(fptr);
    return 0;
}

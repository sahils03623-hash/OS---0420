#include <stdio.h>

int main() {
    FILE *source, *destination;
    char ch;

    source = fopen("source.txt", "r");

    if (source == NULL) {
        printf("Source file not found\n");
        return 1;
    }

    destination = fopen("destination.txt", "w");

    if (destination == NULL) {
        printf("Unable to create destination file\n");
        fclose(source);
        return 1;
    }

    while ((ch = fgetc(source)) != EOF) {
        fputc(ch, destination);
    }

    printf("File copied successfully\n");

    fclose(source);
    fclose(destination);

    return 0;
}
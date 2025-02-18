#include <stdio.h>
#include <stdlib.h>

void reverse_file(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Could not open file %s\n", filename);
        return;
    }

    // Move to the end of the file
    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);

    // Read characters in reverse order
    for (long i = file_size - 1; i >= 0; i--) {
        fseek(file, i, SEEK_SET);
        char ch = fgetc(file);
        putchar(ch);  // Print in reverse order
    }

    fclose(file);
}

int main() {
    char filename[100];

    printf("Enter the filename: ");
    scanf("%s", filename);

    printf("\nReversed file content:\n");
    reverse_file(filename);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

void print_first_n_lines(const char *filename, int n) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Could not open file %s\n", filename);
        return;
    }

    char line[1024]; // Buffer to store each line
    int count = 0;

    while (fgets(line, sizeof(line), file) != NULL && count < n) {
        printf("%s", line);
        count++;
    }

    fclose(file);
}

int main() {
    char filename[100];
    int n;

    printf("Enter the filename: ");
    scanf("%s", filename);

    printf("Enter the number of lines to print: ");
    scanf("%d", &n);

    print_first_n_lines(filename, n);

    return 0;
}
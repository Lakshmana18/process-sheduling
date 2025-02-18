#include <stdio.h>
#include <stdlib.h>

#define MAX_LINES 1000  // Define a limit for storing lines (can be increased)

void print_last_n_lines(const char *filename, int n) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Could not open file %s\n", filename);
        return;
    }

    char *lines[MAX_LINES]; // Array to store lines
    int count = 0;
    char buffer[1024];  // Buffer to store each line

    // Read the file line by line
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        if (count < MAX_LINES) {
            lines[count] = strdup(buffer);  // Store line dynamically
            count++;
        }
    }
    fclose(file);

    // Print the last n lines
    int start = (count > n) ? count - n : 0; // Ensure we don’t access out of bounds
    for (int i = start; i < count; i++) {
        printf("%s", lines[i]);
        free(lines[i]); // Free allocated memory
    }
}

int main() {
    char filename[100];
    int n;

    printf("Enter the filename: ");
    scanf("%s", filename);

    printf("Enter the number of last lines to print: ");
    scanf("%d", &n);

    print_last_n_lines(filename, n);

    return 0;
}
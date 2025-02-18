#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

#define BUFFER_SIZE 1024

// Function to simulate `cp` (Copy file)
void copy_file(char *src, char *dest) {
    int fd_src, fd_dest;
    char buffer[BUFFER_SIZE];
    ssize_t bytes_read, bytes_written;

    // Open source file for reading
    fd_src = open(src, O_RDONLY);
    if (fd_src == -1) {
        perror("Error opening source file");
        return;
    }

    // Open destination file for writing (create if it doesn't exist)
    fd_dest = open(dest, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd_dest == -1) {
        perror("Error opening destination file");
        close(fd_src);
        return;
    }

    // Read from source and write to destination
    while ((bytes_read = read(fd_src, buffer, BUFFER_SIZE)) > 0) {
        bytes_written = write(fd_dest, buffer, bytes_read);
        if (bytes_written != bytes_read) {
            perror("Error writing to file");
            break;
        }
    }

    // Close files
    close(fd_src);
    close(fd_dest);
    printf("File copied successfully from %s to %s\n", src, dest);
}

// Function to simulate `ls` (List directory contents)
void list_directory(char *path) {
    DIR *dir;
    struct dirent *entry;

    dir = opendir(path);
    if (dir == NULL) {
        perror("Error opening directory");
        return;
    }

    printf("Files in directory %s:\n", path);
    while ((entry = readdir(dir)) != NULL) {
        printf("%s  ", entry->d_name);
    }
    printf("\n");

    closedir(dir);
}

// Function to simulate `grep` (Search pattern in a file)
void grep_pattern(char *pattern, char *filename) {
    FILE *file;
    char line[BUFFER_SIZE];
    int line_number = 0;

    file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    printf("Lines containing '%s' in %s:\n", pattern, filename);
    while (fgets(line, sizeof(line), file)) {
        line_number++;
        if (strstr(line, pattern) != NULL) {
            printf("%d: %s", line_number, line);
        }
    }

    fclose(file);
}

// Main function: Take user input and execute command
int main() {
    char command[100], arg1[100], arg2[100];

    while (1) {
        printf("\nEnter command (cp/ls/grep/exit): ");
        scanf("%s", command);

        if (strcmp(command, "cp") == 0) {
            scanf("%s %s", arg1, arg2);
            copy_file(arg1, arg2);
        }
        else if (strcmp(command, "ls") == 0) {
            scanf("%s", arg1);
            list_directory(arg1);
        }
        else if (strcmp(command, "grep") == 0) {
            scanf("%s %s", arg1, arg2);
            grep_pattern(arg1, arg2);
        }
        else if (strcmp(command, "exit") == 0) {
            printf("Exiting...\n");
            break;
        }
        else {
            printf("Invalid command! Available commands: cp, ls, grep, exit\n");
        }
    }

    return 0;
}
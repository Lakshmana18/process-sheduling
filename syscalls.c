#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include <string.h>

void fork_example() {
    pid_t pid = fork();
    if (pid == -1) {
        perror("fork failed");
    } else if (pid == 0) {
        printf("Child Process: PID = %d, Parent PID = %d\n", getpid(), getppid());
        exit(0); // Child exits
    } else {
        wait(NULL); // Parent waits for child
        printf("Parent Process: Child completed\n");
    }
}

void exec_example() {
    pid_t pid = fork();
    if (pid == 0) {
        printf("Executing 'ls -l' using exec\n");
        execl("/bin/ls", "ls", "-l", NULL);
        perror("exec failed");
        exit(1);
    } else {
        wait(NULL);
    }
}

void getpid_example() {
    printf("Current Process ID: %d\n", getpid());
}

void exit_example() {
    printf("Exiting program...\n");
    exit(0);
}

void wait_example() {
    pid_t pid = fork();
    if (pid == 0) {
        printf("Child process running, PID = %d\n", getpid());
        sleep(2);
        printf("Child process exiting\n");
        exit(0);
    } else {
        printf("Waiting for child process to finish...\n");
        wait(NULL);
        printf("Child process completed\n");
    }
}

void close_example() {
    int fd = open("test.txt", O_CREAT | O_WRONLY, 0644);
    if (fd == -1) {
        perror("Error opening file");
        return;
    }
    printf("File opened successfully, fd = %d\n", fd);
    close(fd);
    printf("File closed successfully\n");
}

void stat_example() {
    struct stat fileStat;
    char filename[100];

    printf("Enter filename to check status: ");
    scanf("%s", filename);

    if (stat(filename, &fileStat) == -1) {
        perror("Error getting file status");
        return;
    }

    printf("File: %s\n", filename);
    printf("Size: %ld bytes\n", fileStat.st_size);
    printf("Permissions: %o\n", fileStat.st_mode & 0777);
    printf("Last modified: %ld\n", fileStat.st_mtime);
}

void opendir_readdir_example() {
    DIR *dir;
    struct dirent *entry;
    char dirname[100];

    printf("Enter directory name: ");
    scanf("%s", dirname);

    dir = opendir(dirname);
    if (dir == NULL) {
        perror("Error opening directory");
        return;
    }

    printf("Contents of directory %s:\n", dirname);
    while ((entry = readdir(dir)) != NULL) {
        printf("%s\n", entry->d_name);
    }
    closedir(dir);
}

int main() {
    int choice;

    while (1) {
        printf("\nChoose an option:\n");
        printf("1. Fork Example\n");
        printf("2. Exec Example\n");
        printf("3. Get PID\n");
        printf("4. Exit Program\n");
        printf("5. Wait Example\n");
        printf("6. Close File Example\n");
        printf("7. File Status (stat)\n");
        printf("8. List Directory (opendir, readdir)\n");
        printf("9. Quit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: fork_example(); break;
            case 2: exec_example(); break;
            case 3: getpid_example(); break;
            case 4: exit_example(); break;
            case 5: wait_example(); break;
            case 6: close_example(); break;
            case 7: stat_example(); break;
            case 8: opendir_readdir_example(); break;
            case 9: printf("Exiting...\n"); exit(0);
            default: printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
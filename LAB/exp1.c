
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid;

    pid = fork();  // Create a new process

    if (pid < 0) {
        printf("Process creation failed.\n");
    }
    else if (pid == 0) {
        // Child process
        printf("Child Process\n");
        printf("Process ID: %d\n", getpid());
        printf("Parent Process ID: %d\n", getppid());
    }
    else {
        // Parent process
        wait(NULL);
        printf("\nParent Process\n");
        printf("Process ID: %d\n", getpid());
        printf("Parent Process ID: %d\n", getppid());
    }

    return 0;
}

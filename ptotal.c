#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    // First child process
    pid_t child_pid1 = fork();
    
    if (child_pid1 == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    } else if (child_pid1 == 0) {
        // This is the child process 1
        execl("q1", "q1", NULL);
        perror("execl");
        exit(EXIT_FAILURE);
    } else {
        // This is the parent process
        // You can do other tasks in the parent process
        // Wait for the child to finish
        wait(NULL);
    }

    // Second child process
    pid_t child_pid2 = fork();
    
    if (child_pid2 == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    } else if (child_pid2 == 0) {
        // This is the child process 2
        execl("q2", "q2", NULL);
        perror("execl");
        exit(EXIT_FAILURE);
    } else {
        // This is the parent process
        // You can do other tasks in the parent process
        // Wait for the child to finish
        wait(NULL);
    }
     pid_t child_pid3 = fork();
    
    if (child_pid3 == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    } else if (child_pid3 == 0) {
        // This is the child process 2
        execl("q3", "q3", NULL);
        perror("execl");
        exit(EXIT_FAILURE);
    } else {
        // This is the parent process
        // You can do other tasks in the parent process
        // Wait for the child to finish
         int child_status;
        wait(&child_status);
        
        if (WIFEXITED(child_status)) {
            int exit_status = WEXITSTATUS(child_status);
            printf("Parent process (PID %d): Child process (PID %d) has completed with status %d.\n", getpid(), child_pid, exit_status);
        }
        wait(NULL);
    }
    // Continue with other tasks in the parent process

    return 0;
}
re
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    pid_t child_pid;

    child_pid = fork(); // Create a child process
int a = 4; 
    //while(a) { // Child process
        execl("q1", "q1", "", NULL); // Replace the current process with 'ls -l'
        perror("execl");
        exit(EXIT_FAILURE);
        execl("q2", "q2", "", NULL); // Replace the current process with 'ls -l'
         perror("execl");
        exit(EXIT_FAILURE);
        execl("q3","q3","11",NULL);
        a--; 
    //}

    // Parent process continues here
    // ...

    return 0;
}

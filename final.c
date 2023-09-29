#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int pipefd[2];
    pid_t child_pid;
    
    // Create a pipe to send data from the parent to the child
    if (pipe(pipefd) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }
    
    child_pid = fork();
    
    if (child_pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    } else if (child_pid == 0) {
        // This is the child process
        
        // Close the read end of the pipe since we won't use it in the child
        close(pipefd[0]);
        
        // Redirect stdin to the write end of the pipe
        dup2(pipefd[1], STDIN_FILENO);
        
        // Close the write end of the pipe (since stdin is duplicated)
        close(pipefd[1]);
        
        // Execute the program that will receive integer input
        execl("q3", "q3", NULL);
        
        // If execl fails, print an error message
        perror("execl");
        exit(EXIT_FAILURE);
    } else {
        // This is the parent process
        
        // Close the write end of the pipe since we won't use it in the parent
        close(pipefd[1]);
        
        // Convert an integer to a string
        int input_integer = 11; // Change this to the desired integer value
        char input_string[20]; // Adjust the buffer size as needed
        snprintf(input_string, sizeof(input_string), "%d", input_integer);
        
        // Send the integer input to the child process through the pipe
        write(pipefd[0], input_string, strlen(input_string));
        
        // Close the read end of the pipe
        close(pipefd[0]);
        
        // Wait for the child to finish
        wait(NULL);
    }

    return 0;
}

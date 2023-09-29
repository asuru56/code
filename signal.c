#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void signal_handler(int signum) {
    printf("Received signal %d (Ctrl+C).\n", signum);
    // Add your code to handle the signal here.
}

int main() {
    // Register the signal handler for SIGINT
    signal(SIGINT, signal_handler);

    printf("Press Ctrl+C to trigger the signal handler...\n");

    while (1) {
        system("q1", "q1","1",0);
        execl("q2", "q2", "1", 0);
    }

    return 0;
}

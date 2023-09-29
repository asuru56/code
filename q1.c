#include <stdio.h>
#include <pthread.h>

// Shared variable
int shared_variable = 0;

// Mutex to protect the shared variable
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

// Function to increment the variable
void* increment_variable(void* arg) {
    for (int i = 0; i < 100; i++) {
        pthread_mutex_lock(&mutex); // Acquire the lock
        shared_variable++;
        printf("Increment Value %d by pthread_id \n", shared_variable);
        pthread_mutex_unlock(&mutex); // Release the lock
    }
    return NULL;
}

int main() {
    // Create two threads
    pthread_t thread1, thread2;

    // Start the threads
    pthread_create(&thread1, NULL, increment_variable, NULL);
    pthread_create(&thread2, NULL, increment_variable, NULL);

    // Wait for both threads to finish
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    // Print the final value of the variable
    printf("Final value: %d\n", shared_variable);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

pthread_mutex_t mutex;
pthread_cond_t p2_done;
pthread_cond_t p3_done;
int p2_completed = 0;
int p3_completed = 0;

void *p1_function(void *arg) {
    // Code for p1
    // Provide input
    // Signal p4 to start

    pthread_mutex_lock(&mutex);
    // Signal p4 to start its work
    pthread_cond_signal(&p2_done);
    pthread_mutex_unlock(&mutex);

    return NULL;
}

void *p2_function(void *arg) {
    // Code for p2
    // Execute task for p2

    // Signal p4 that p2 is done
    pthread_mutex_lock(&mutex);
    p2_completed = 1;
    pthread_cond_signal(&p2_done);
    pthread_mutex_unlock(&mutex);

    return NULL;
}

void *p3_function(void *arg) {
    // Code for p3
    // Execute task for p3

    // Signal p4 that p3 is done
    pthread_mutex_lock(&mutex);
    p3_completed = 1;
    pthread_cond_signal(&p3_done);
    pthread_mutex_unlock(&mutex);

    return NULL;
}

void *p4_function(void *arg) {
    pthread_mutex_lock(&mutex);

    // Wait for p1 to signal to start
    pthread_cond_wait(&p2_done, &mutex);

    // Wait for both p2 and p3 to complete
    while (!(p2_completed && p3_completed)) {
        pthread_cond_wait(&p2_done, &mutex);
    }

    // Perform verification and assign tasks if needed
    printf("p4: Verification complete\n");
    printf("p4: Acknowledging p2 and p3\n");

    pthread_mutex_unlock(&mutex);

    return NULL;
}

int main() {
    pthread_t p1, p2, p3, p4;

    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&p2_done, NULL);
    pthread_cond_init(&p3_done, NULL);

    pthread_create(&p1, NULL, p1_function, NULL);
    pthread_create(&p2, NULL, p2_function, NULL);
    pthread_create(&p3, NULL, p3_function, NULL);
    pthread_create(&p4, NULL, p4_function, NULL);

    pthread_join(p1, NULL);
    pthread_join(p2, NULL);
    pthread_join(p3, NULL);
    pthread_join(p4, NULL);

    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&p2_done);
    pthread_cond_destroy(&p3_done);

    return 0;
}
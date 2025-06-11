#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define MAX_THREADS 100

void* threadFunction(void* arg) {
    int threadID = *((int*)arg);
    printf("Hello from thread %d - I was created in iteration %d\n", threadID, threadID - 1);
    pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <number_of_threads>\n", argv[0]);
        return 1;
    }

    int numThreads = atoi(argv[1]);
    pthread_t threads[MAX_THREADS];
    int threadIDs[MAX_THREADS];

    for (int i = 1; i <= numThreads; i++) {
        threadIDs[i] = i;
        if (i % 4 == 0 || i % 5 == 0) {
            sleep(1);
        }
        pthread_create(&threads[i], NULL, threadFunction, &threadIDs[i]);
        printf("I am thread 1. Created new thread (%d) in iteration %d...\n", i, i - 1);
    }

    for (int i = 1; i <= numThreads; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}
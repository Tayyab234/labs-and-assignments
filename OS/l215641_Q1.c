#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>

sem_t sem_T1, sem_T2;

int X, Y, Z, W;
int X1, Y1, Z1, W1, S1, S2;

void* thread_T1() {
    sem_wait(&sem_T1);
    X1 = Z + 2;
    Y1 = Z1 * 5;
    S1 = X1 + Y1;
    printf("x=%d\n", S1);
    sem_post(&sem_T2);
}

void* thread_T2() {
    sem_wait(&sem_T2);
    Z1 = X1 * 2;
    W1 = Y1 + 5;
    S2 = Z1 + W1;
    printf("x=%d\n", S2);
 }

int main() {
    pthread_t t1, t2;

    // Initialize semaphores
    sem_init(&sem_T1, 0, 1);
    sem_init(&sem_T2, 0, 0);

    // Get input from user
    printf("Enter X, Y, Z, W: ");
    scanf("%d %d %d %d", &X, &Y, &Z, &W);

    // Create threads
    pthread_create(&t1, NULL, thread_T1, NULL);
    pthread_create(&t2, NULL, thread_T2, NULL);

    // Wait for threads to finish
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    // Destroy semaphores
    sem_destroy(&sem_T1);
    sem_destroy(&sem_T2);

    return 0;
}
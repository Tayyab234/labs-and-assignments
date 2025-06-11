#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
sem_t chopstick[5];

void* philosopher(int i) {
    // Philosopher thinks
    printf("Philosopher %d wants to eat\n", i);

    // Philosopher picks up chopsticks
    sem_wait(&chopstick[(i+1) % 5]); // left chopstick
    printf("Philosopher %d tries to pick left chopstick\n", i);
    sem_wait(&chopstick[i]); // right chopstick
    printf("Philosopher %d picks the left chopstick\n", i);
    printf("Philosopher %d picks the right chopstick\n", i);

    // Philosopher eats
    printf("Philosopher %d begins to eat\n", i);
    printf("Philosopher %d has finished eating\n\n", i);

    // Philosopher puts down chopsticks
    sem_post(&chopstick[i]); // right chopstick
    printf("Philosopher %d leaves the right chopstick\n", i);
    sem_post(&chopstick[(i+1) % 5]); // left chopstick
    printf("Philosopher %d leaves the left chopstick\n", i);
}

int main(){

pthread_t T[5];
for (int i = 0; i < 5; i++) {
    sem_init(&chopstick[i], 0, 1);
}
//creating thread
for (int i = 0; i < 5; i++) {
    pthread_create(&T[i], NULL, philosopher, i);
}
//wait for threads to finish
for (int i = 0; i < 5; i++) {
    pthread_join(T[i], NULL);
}
//destroy semaphores
for (int i = 0; i < 5; i++) {
    sem_destroy(&chopstick[i]);
}

return 0;
}
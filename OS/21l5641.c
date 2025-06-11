#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

// Summation function
void *sum(void *arg) {
    int n = (int)arg;
    long long sum = 0;
    for (int i = 0; i <= n; i++) {
        sum += i;
    }
    return (void *)sum;
}

int main() {
    pthread_t thread_id;
    int n;
    printf("\nPlease enter an integer: ");
    scanf("%d", &n);

    void *result;
    pthread_create(&thread_id, NULL, sum, (void *)n);
    pthread_join(thread_id, &result);

    // Print the sum
    printf("Sum of integers from 0 to %d is: %lld\n", (int)n, (long long)result);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_SIZE 100

struct ArrayData {
    int arr[MAX_SIZE];
    int size;
};

// Function to remove duplicates and negative values
void* processFile(void* arg) {
    struct ArrayData *k = malloc(sizeof(struct ArrayData));
    k->size = 0;

    FILE *file;
    int num;
    int dub = 1;
    int i = 0;

    if ((file = fopen((char*)arg, "r")) != NULL) {
        while (fscanf(file, "%d", &num) == 1) {
            if (dub != 0 && num >= 0) {
                k->arr[i] = num;
                i++;
                dub = 0;
            } else if (num >= 0) {
                int j = 0;
                while (j < i && k->arr[j] != num) {
                    j++;
                }
                if (j == i) {
                    k->arr[i] = num;
                    i++;
                }
            }
        }

        fclose(file);
    }

    k->size = i;
    pthread_exit(k);
}

int main(int argc, char *argv[]) {
    pthread_t thread1, thread2;
    struct ArrayData *result, *result1;

    // Create thread and pass file data
    pthread_create(&thread1, NULL, processFile, (void*)argv[1]);
    pthread_create(&thread2, NULL, processFile, (void*)argv[2]);

    // Wait for the threads to finish
    pthread_join(thread1, (void**)&result);
    pthread_join(thread2, (void**)&result1);

    // Access the array and its size from the results
    int count = 0, sum = 0;
    printf("Unique integers of file1\n");
    for (int i = 0; i < result->size; i++) {
        printf("%d\n", result->arr[i]);
        count += 1;
        sum += result->arr[i];
    }
    float avg = (float)sum / count;
    printf("\navg of unique integers %f\n", avg);

    //-----------------------------------------------------------------------------------
    count = 0;
    sum = 0;
    printf("\nUnique integers of file2\n");
    for (int i = 0; i < result1->size; i++) {
        printf("%d\n", result1->arr[i]);
        count += 1;
        sum += result1->arr[i];
    }
    avg = (float)sum / count;
    printf("\navg of unique integers %f\n", avg);

    // Free allocated memory
    free(result);
    free(result1);

    return 0;
}
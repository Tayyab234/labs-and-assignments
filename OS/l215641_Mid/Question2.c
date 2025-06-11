#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

int main(int arg, char* argv[]) {
    char* input = argv[1];
    int size = strlen(input);
    printf("Size : %d\n",size);
    printf("Input string: %s\n", input);

    int newsize = 0;
    int k = 0;
    while (k < size) {
        if (input[k] >= '0' && input[k] <= '9')
            newsize++;
        k++;
    }

    char buffer[size];
    int pf1[2];
    int pf2[2];
    pipe(pf1);
    pipe(pf2);
    pid_t pid = fork();
    if (pid > 0) { // parent process
        close(pf1[0]);
        write(pf1[1], input, size);
        wait(NULL); // wait for child process to execute its instructions

        close(pf2[1]);
        int arr[newsize];
        read(pf2[0], arr, newsize * sizeof(int));
        printf("Sorted array: ");
        for (int i = 0; i < newsize; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }
    else { // child process
        wait(NULL);
        close(pf1[1]);
        read(pf1[0], buffer, size);

        int outputarray[newsize];
        int i = 0;
        int j = 0;
        while (i < size) {
            if (buffer[i] >= '0' && buffer[i] <= '9') {
                outputarray[j] = buffer[i] - '0';
                j++;
            }
            i++;
        }

        // sort output array in descending order
        for (i = 0; i < newsize; i++) {
            for (j = i + 1; j < newsize; j++) {
                if (outputarray[i] < outputarray[j]) {
                    int temp = outputarray[i];
                    outputarray[i] = outputarray[j];
                    outputarray[j] = temp;
                }
            }
        }

        // send back the sorted array through pipe
        close(pf2[0]);
        write(pf2[1], outputarray, newsize * sizeof(int));
    }

    return 0;
}

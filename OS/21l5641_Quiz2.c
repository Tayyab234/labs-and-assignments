#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Function to generate Fibonacci series
void* fibonacciGenerator(void* arg) {
    int n = *(int*)arg;
  int* series = malloc((n+1) * sizeof(int));
  series[0] = 0;
  series[1] = 1;
  for (int i = 2; i < n; i++) {
    series[i] = series[i-1] + series[i-2];
  }
  series[n] = 0; // add termination value to the series
  return series;
}

// Function to count even numbers in a series
void* countEvenNumbers(void* arg) {
  int* series = (int*)arg;
  int count = 0;
  for (int i = 0; series[i]!= 0; i++) {
    if (series[i] % 2 == 0) {
      count++;
    }
  }
  int* result = malloc(sizeof(int));
  *result = count;
  free(series); // free the memory allocated for the series
  return result;
}

// Function to count odd numbers in a series
void* countOddNumbers(void* arg) {
  int* series = (int*)arg;
  int count = 0;
  for (int i = 0; series[i]!= 0; i++) {
    if (series[i] % 2!= 0) {
      count++;
    }
  }
  int* result = malloc(sizeof(int));
  *result = count;
  free(series); // free the memory allocated for the series
  return result;
}

// Function to calculate sum of a series
void* calculateSum(void* arg) {
  int* series = (int*)arg;
  int sum = 0;
  for (int i = 0; series[i]!= 0; i++) {
    sum += series[i];
  }
  int* result = malloc(sizeof(int));
  *result = sum;
  free(series); // free the memory allocated for the series
  return result;
}

int main() {
 int n;
 void *result1, *Ecount, *Oddcount, *sum;
 printf("\nPlease enter a positive integer : ");
  scanf("%d", &n);
  pthread_t th1,th2,th3,th4;
  pthread_create(&th1,NULL,fibonacciGenerator, &n); // pass address of n
  pthread_join(th1,&result1);
  int* result = (int*)result1; // cast result1 to int*
  printf("fibonacci series :  ");
  for(int i=0;i<n;i++){
    printf("%d ", result[i]); // correct printf format
  }
  pthread_create(&th2,NULL,countEvenNumbers, result1); // pass address of result1
  pthread_join(th2,&Ecount);
  printf("\n Even count : %d",*(int*)Ecount);
  pthread_create(&th3,NULL,countOddNumbers, result1); // pass address of result1
  pthread_join(th3,&Oddcount);
  printf("\n Odd count : %d",*(int*)Oddcount);
  
  pthread_create(&th4,NULL,calculateSum, result1); // pass address of result1
  pthread_join(th4,&sum);
  
  printf("\n Sum is  : %d",*(int*)sum);
  
  free(result); // free allocated memory
  return 0;
}
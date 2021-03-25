#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>
#define NUM1    0
#define NUM2    15
#define NUMOFTHREADS    8

void *printPrimeThreadCalculation(void *threadid);
void primeCheckerThread(int num1, int num2, int numOfThreads);

int main() {

    // Calculate the time taken by take_enter()
    clock_t t;
    t = clock();

    /* Thread Prime Checker */
    primeCheckerThread(NUM1, NUM2, NUMOFTHREADS);

    printf(" \n");
    printf("Timer ends \n");
    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC; // calculate the elapsed time
    printf("The program took %f seconds to execute", time_taken);

    /* Exits the threads */
    pthread_exit(NULL);
    return 0;
}


void *printPrimeThreadCalculation(void *threadid) {
    long tid;
    tid = (long) threadid;
    printf("Threadid> %ld:\n", tid);

    int number1 = NUM1;
    int number2 = NUM2;
    int isPrime, i;

    /* Calculations */
    while (number1 <= number2) {
        /* Assume isPrime is true */
        isPrime = 1;

        for (i = 2; i < number1 && isPrime; i++) {
            if (number1 % i == 0) {
                isPrime = 0;
            }
        }
        if (isPrime == 1) {
            printf("%d ", number1);
        }
        number1++;
    }
    printf("\n");
    printf("\n");
}

void primeCheckerThread(int num1, int num2, int numOfThreads) {
    /* Create threads */
    pthread_t threads[numOfThreads];
    int rc;
    long t;
    for (t = 0; t < numOfThreads; t++) {
        /* Creates threads */
        rc = pthread_create(&threads[t], NULL, printPrimeThreadCalculation, (void *)t);
        if (rc) {
            printf("ERROR; return code from pthread_create() is %d\n", rc);
            exit(-1);
        }
    }
}

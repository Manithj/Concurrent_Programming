// This program demonstrates the use of pthreads to calculate the sum of numbers in parallel.
// Coded by Manith Jayaba
#include <stdio.h>
#include <pthread.h>
#include <iostream>

using namespace std;

// Define a struct to hold data for each thread
struct ThreadData {
    int numbers[4] = {1, 4, 3, 4}; // Array of numbers to be summed
    int sum1; // Variable to store the sum of the first 2 numbers
    int sum2; // Variable to store the sum of the last 2 numbers
};

// Function to calculate the sum of the first 2 numbers
void *addNumbers1(void *arg) {
    ThreadData *data = (ThreadData *)arg;

    data->sum1 = 0;
    for (int i = 0; i < 2; ++i) {
        data->sum1 += data->numbers[i];
    }

    pthread_exit(NULL);
}

// Function to calculate the sum of the last 2 numbers
void *addNumbers2(void *arg) {
    ThreadData *data = (ThreadData *)arg;

    data->sum2 = 0;
    for (int i = 2; i < 4; ++i) {
        data->sum2 += data->numbers[i];
    }

    pthread_exit(NULL);
}

int main() {
    pthread_t threads[2]; // Array to hold thread IDs
    ThreadData data; // Create an instance of ThreadData struct

    // Create two threads to calculate sums in parallel
    pthread_create(&threads[0], NULL, addNumbers1, (void *)&data);
    pthread_create(&threads[1], NULL, addNumbers2, (void *)&data);

    // Wait for both threads to finish execution
    for (int i = 0; i < 2; ++i) {
        pthread_join(threads[i], NULL);
    }

    // Output the results
    std::cout << "Sum of the 1st 2 numbers is: " << data.sum1 << std::endl;
    std::cout << "Sum of the last 2 numbers is: " << data.sum2 << std::endl;

    return 0;
}
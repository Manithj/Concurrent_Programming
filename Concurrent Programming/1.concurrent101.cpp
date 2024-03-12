// Coded by Manith Jayaba
// Including necessary libraries for the program
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Defining a function to print a message received as a parameter
void *print_msg(void *msg){
    char *message;
    message = (char *) msg; // Type casting the parameter into a char pointer
    printf("%s \n", message); // Printing the message
    return NULL; // Returning NULL after printing
}

// Main function where the program execution begins
int main() {
    pthread_t thread1, thread2; // Declaring two pthread variables for threads
    char *msg1 = "Hello from thread 1"; // Message for thread 1
    char *msg2 = "Hello from thread 2"; // Message for thread 2
    int iret1, iret2; // Return values of pthread_create

    // Creating threads and passing the print_msg function with respective messages as arguments
    iret1 = pthread_create(&thread1, NULL, print_msg, (void*)msg1);
    iret2 = pthread_create(&thread2, NULL, print_msg, (void*)msg2);

    // Waiting for threads to finish execution before proceeding
    pthread_join(thread1, nullptr);
    pthread_join(thread2, nullptr);

    // Printing the return values of thread creation
    printf("T1: %d\n", iret1);
    printf("T2: %d\n", iret2);

    return 0; // Exiting the program with success status
}
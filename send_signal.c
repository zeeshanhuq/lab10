/**
 * File: send_signal.c
 * Modified by: Zeeshan Huq
 * 
 * Brief summary of program: Sends a random number to a specified process using the SIGUSR1 signal.
*/


#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>

#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <pid>\n", argv[0]);
        return 1;
    }

    pid_t pid = (pid_t)atoi(argv[1]);
    srand((unsigned int)time(NULL)); // Seed the random number generator
    int number = rand(); // Generate a random number


    printf("Sending number: %d\n", number);

    union sigval value;
    value.sival_int = number; // Send the generated number with the signal

    if (sigqueue(pid, SIGUSR1, value) == -1) {
        perror("sigqueue");
        return 1;
    }
    return 0;
}
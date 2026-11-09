/**
 * @file signal_segfault.c
 * @brief Program that dereferences a null pointer causing a segmentation fault
 */

/**
 * Modified by: Zeeshan Huq
 * 
 * Brief summary of modifications:
 * added a signal handler for SIGSEGV that prints a message when the signal is received, instead of terminating the program immediately.
 */


#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void handle_signal(int signum) {
    printf("Caught signal %d\n", signum);
    const char msg[] = "Segmentation fault occurred!\n";
    write(STDOUT_FILENO, msg, sizeof(msg) - 1);
}

int main (int argc, char* argv[]) {
    (void)argc; // Unused parameter
    (void)argv; // Unused parameter
    signal(SIGSEGV, handle_signal); // Register the signal handler for SIGSEGV
    // Declare a null pointer
    int* i = NULL;

    // Dereference the null pointer
    printf("The value of i is: %d\n", *i);

    // Return to exit the program
    return 0;
}
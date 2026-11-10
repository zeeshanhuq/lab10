/**
 * File: recv_signal.c
 * Modified by: Zeeshan Huq
 * 
 * Brief summary of program: Receives a signal from another process and prints the received number.
*/

#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>

void handler(int signo, siginfo_t *info, void *context) {
    (void)signo; // Unused parameter
    (void)context; // Unused parameter
    printf("Received signal: %d\n", signo);
    if (info != NULL) {
        printf("Signal sent by process: %d\n", info->si_value.sival_int);
    }
}

int main() {
    struct sigaction sa;
    memset(&sa, 0, sizeof(sa));
    sa.sa_sigaction = handler;
    sa.sa_flags = SA_SIGINFO;

    sigemptyset(&sa.sa_mask);
    sigaction(SIGUSR1, &sa, NULL);
    
    int pid = getpid();
    printf("Process ID: %d\n", pid);

    while (1) {
        pause(); // Wait for signals
    }

    return 0;
}
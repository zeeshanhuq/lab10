/**
 * File: signal_alarm.c
 * Modified by: Zeeshan Huq
 * 
 * Brief summary of program:
 * sets a signal handler for SIGALRM, sets an alarm for 5 seconds, and waits for the alarm to trigger. 
 * When the alarm goes off, it prints a message to the standard output.
*/

#include <signal.h>
#include <unistd.h>
#include <stdio.h>

static volatile sig_atomic_t alarm_triggered = 0;

void handle_alarm(int signum) {
    printf("Received signal %d\n", signum);
    const char msg[] = "SIGALRM received!\n";
    write(STDOUT_FILENO, msg, sizeof(msg) - 1);
    alarm_triggered = 1;
}

int main() {
    // Register the signal handler for SIGALRM
    signal(SIGALRM, handle_alarm);

    // Set an alarm for 5 seconds
    alarm(5);

    printf("Alarm set for 5 seconds. Waiting...\n");
    
    // Wait for the alarm to trigger
    while (!alarm_triggered) {
        pause(); // Wait for signals
    }

    return 0;
}
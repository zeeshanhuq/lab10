/**
 * File: signal_alarm.c
 * Modified by: Zeeshan Huq
 * 
 * Brief summary of program:
*/

#include <signal.h>
#include <unistd.h>
#include <stdio.h>

static volatile sig_atomic_t alarm_triggered = 0;

void handle_alarm(int signum) {
    void()signum; // Unused parameter
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
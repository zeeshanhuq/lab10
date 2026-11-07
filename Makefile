CC=gcc
CFLAGS=-c -Wall -Wextra -g 
TARGETS = signal_handler signal_alarm signal_segfault signal_sigaction \
		  recv_signal send_signal
all: $(TARGETS)

%: %.c
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f $(TARGETS) *.o
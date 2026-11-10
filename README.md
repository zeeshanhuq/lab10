## Lab Week 10
Programs explore signals as a communication technique.  
Building:  
make : builds all programs  
make clean: removes compiled programs  

Programs:  
signal_handler:  
Registers a handler ofr sigint. The handlers prints a message but doesnt quit. Send SIGINT with CTRL_C within its terminal or kill -SIGINT (pid) form another terminal to send the signal for it to receive. Stop the program with CTRL+\  

signal_alarm:  
Schedules an alarm for 5 seconds, after which the OS sends SIGALARM. The handler prints a message and the program quits.  

signal_segfault:  
Installs a SIGSEGV handler and dereferences a NULL pointer. The handler prints a message and returns to the program continuoustly executes. This causes an infinite loop of faulting. Stop with CTRL+C.  

signal_sigaction:  
Uses sigaction with SA_SIGINFO to register a SIGUSR 1 handler. It then waits in an infinite loop until a signal is sent, where it will print the received signal and the PID of who sent it. Stop with CTRL+C.  

recv_signal and send_signal:  
Use one terminal for each program.
recv_signal prints its own PID and registers a SIGUSR1 handler with sigaction and prints the integer sent along with the signal. Stop with CTRL+C
send_signal picks a random integer and sents it to the given PID.
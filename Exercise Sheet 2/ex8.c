#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void func(int signo) {
	fprintf(stderr, "\nReceived signal %d!\n", signo);
}

int main() {
	struct sigaction new, old;
	sigset_t smask;	// defines signals to block while func() is running

	// prepare struct sigaction
	if (sigemptyset(&smask)==-1)	// block no signal
		perror ("sigsetfunctions");
	new.sa_handler = func;
	new.sa_mask = smask;
	new.sa_flags = 0;	// usually works

	if(sigaction(SIGCHLD, &new, &old) == -1)
		perror ("sigaction");

	int id = fork();
    if(id != 0){
        pause();
        printf("World!\n");
    } else {
        printf("Hello ");
        kill(0, SIGCHLD);
    }

	return 0;
}
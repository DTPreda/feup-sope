#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

/**
 * Program to inspect the page size of a system.
 * Tries to write the entire page. Fails at exactly 33 times the actual size of a page.
*/
char* p;
int counter = 0;

void sig_handler(int signo){
    fprintf(stdout, "Page size, returned by sysconf: %li\n", sysconf(_SC_PAGE_SIZE));
    fprintf(stdout, "Segmentation fault (core dumped), %i\n", getpid());
    for (int i = 1; 1; i++) {
        *(p - i) = 'a';
        counter++;
        fprintf(stdout, "%i\n", counter);
    }
}

int set_handlers() {
    for (int i = 1; i < 32; i++) {
        if (i != SIGKILL && i != SIGSTOP) {
            if (signal(i, sig_handler) == SIG_ERR) {
                fprintf(stdout, "%i\n", i);
                perror("signal");
                return 1;
            }
        }
    }
    return 0;
}

void end(){
    fprintf(stdout, "%i\n", counter);
}

int main (int argc, char* argv[]) {
    set_handlers();

    p = (char*) malloc (1);

    for(int i = 0; 1; i++){
        *(p + i) = 'a';
        counter++;
        fprintf(stdout, "%i\n", counter);
    }
    return 0;
}
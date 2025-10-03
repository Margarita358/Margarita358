#include <stdio.h>
#include <unistd.h>

int main (void) {
    fprintf(stdout, "I am process with pid=%d\n",getpid());
    fprintf(stdout, "My group proup id=%d\n",getpgrp());
    fprintf(stdout, "My parent pid=%d\n",getppid());
    return 0;
}



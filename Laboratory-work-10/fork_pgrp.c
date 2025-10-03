#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main (void)
{
        pid_t pid;
        if  ((pid = fork()) < 0) {
                 fprintf(stderr, "fork error!");
                 return EXIT_FAILURE;
        }
        if  (pid == 0) {
                printf("I'm Child process:\n");
                printf("\t my pid = %d, my ppid = %d\n", getpid(), getppid());
                printf("\t my group process id = %d\n", getpgrp());
        }
        else {
                printf("I'm Parent process:\n");
                printf("\t my pid=%d, \n\t my child pid=%d\n", getpid(), pid);
                printf("\t my group process id=%d\n", getpgrp());
                if (setpgid(pid,getpid()) != 0) {
                         fprintf(stderr, "setpgid error!\n");
                         return EXIT_FAILURE;
                        }
              } 
              return EXIT_SUCCESS;
}

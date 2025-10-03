#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main (void)
{
        pid_t pid = fork();
        if (pid == 0) {
               printf("I'm child process:\n");
               printf("\t my pid=%d, \n\t my ppid=%d\n", getpid(), getppid());
         }
         else {
               printf("I'm Parent process:\n");
               printf("\t my pid=%d, \n\t my child pid=%d\n", getpid(), pid);
               sleep(1);
         }
return EXIT_SUCCESS;
}

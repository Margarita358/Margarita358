#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main (void)
{
        char* echo_args[] = { "echo",
                              "I'm ECHO - a new image of child process.\n",
                              NULL
                              };
        pid_t pid = fork();
        if (pid != 0) {
                printf("I'm parent!\n");
                execv("/bin/echo",echo_args);
                printf("exec error!");
                return EXIT_FAILURE;
         }
         else {
                printf("I'm child!\n");
         }
         return EXIT_SUCCESS;
}

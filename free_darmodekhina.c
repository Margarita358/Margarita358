#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void) {
    pid_t pid = fork();

    if (pid < 0) {
        perror("fork failed");
        exit(1);
    } 
    else if (pid == 0) {
        // Child process
        printf("The child of Darmodekhina executes: free\n");
        sleep(1);

        // Масив аргументів для execv
        char *args[] = {"/usr/bin/free", "-k", "-w", NULL};

        // Замінюємо образ процесу
        if (execv("/usr/bin/free", args) == -1) {
            perror("execv failed");
            exit(1);
        }
    } 
    else {
        // Parent process waits
        wait(NULL);
        printf("Parent process finished waiting for child.\n");
    }

    return 0;
}

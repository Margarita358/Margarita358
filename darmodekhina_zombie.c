#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <sys/types.h> 
#include <sys/wait.h>

int main(void) {
    pid_t pid;

    pid = fork();

    if (pid < 0) {
        perror("fork failed");
        return EXIT_FAILURE;
    } 
    else if (pid == 0) {
         // Child process
         printf("I am Zombie-process of Darmodekhina\n");
         exit(EXIT_SUCCESS); // child завершується раніше
    } 
    else {
    // Parent process
    printf("Parent process (PID=%d) sleeping, child becomes zombie\n", getpid());
    sleep(10); // чекаємо, не збираючи child через wait
    printf("Parent process finished\n");

    // Тепер збираємо завершеного child
    wait(NULL);
    }

    return EXIT_SUCCESS;

}


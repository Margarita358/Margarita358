#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main(void) {
    pid_t pid;
    int n = 11; // номер варіанту

    pid = fork();

    if (pid < 0) {
        perror("fork failed");
        return EXIT_FAILURE;
    } 
    else if (pid == 0) {
        // Child process
        for (int i = 0; i < 2*n + 1; i++) {
            printf("Parent of Darmodekhina, iteration %d, parent PPID=%d\n", i+1, getppid());
            sleep(1);
        }
    } 
    else {
        // Parent process
        sleep(n + 1); // чекаємо n+1 секунд
        printf("Parent process (PID=%d) finished earlier than child.\n", getpid());
        exit(EXIT_SUCCESS);
    }

    return EXIT_SUCCESS;
}

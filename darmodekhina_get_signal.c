#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
    fprintf(stderr, "Usage: %s <PID>\n", argv[0]);
    return EXIT_FAILURE; 
    }

    pid_t pid = (pid_t)atoi(argv[1]);

    if (kill(pid, SIGUSR2) != 0) {
    perror("kill error");
    return EXIT_FAILURE;
    }

    printf("Sent SIGUSR2 to process %d\n", pid); 
    return EXIT_SUCCESS;

}

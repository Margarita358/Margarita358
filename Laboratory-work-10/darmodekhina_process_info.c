#include <stdio.h>
#include <unistd.h>

int main (void) {
    fprintf(stdout, "Process Group (PGID)=%d\n",getpid());
    fprintf(stdout, "Process ID (PID)=%d\n",getpid());    
    fprintf(stdout, "Parent Process ID (PPID)=%d\n",getppid());
    fprintf(stdout, "User ID (UID)=%d\n",getuid());
    fprintf(stdout, "Group ID (GID)=%d\n",getgid());
    return 0;
}


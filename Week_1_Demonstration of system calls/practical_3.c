/*Write a program to create child process which will list all the files present in your
 system. Make sure that parent process waits until child has not completed its
 execution. (use wait(), exit()).What will happen if parent process dies before child
 process? Illustrate it by creating one more child of parent process/// solved */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    pid_t pid1, pid2;
    pid1 = fork();

    if (pid1 < 0)
    {
        // Fork failed
        printf("Fork failed!\n");
        return 1;
    }

    if (pid1 == 0)
    {
        printf("First Child Process (Listing files):\n");
        execlp("/bin/ls", "ls", NULL); // execlp

        exit(0);
    }
    else
    {

        wait(NULL);
        printf("Parent Process waited for first child to complete\n");
        pid2 = fork();

        if (pid2 < 0)
        {
            // Fork failed
            printf("Fork failed!\n");
            return 1;
        }

        if (pid2 == 0)
        {
            // Second Child Process: Parent dies before second child completes
            sleep(5); // Simulate child doing something for 5 seconds
            printf("Second Child Process (Orphan Process):\n");
            printf("Second Child Process ID: %d\n", getpid());
            printf("Second Child Parent Process ID: %d\n", getppid()); // Should be `init` process ID
            exit(0);
        }
        else
        {
            // Parent Process: Terminate before the second child finishes
            printf("Parent Process is about to terminate before second child completes.\n");
            exit(0); // Parent process terminates
        }
    }
    return 0;
}

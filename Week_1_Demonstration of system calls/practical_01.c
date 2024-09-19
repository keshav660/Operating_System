// Write the Program to create the child process using fork ();
#include <stdio.h>
#include <unistd.h>
int main()
{
    pid_t pid = fork();
    if (pid < 0)
    {
        printf("Fork failed!\n");
        return 1;
    }
    else if (pid == 0)
    {
        // Child process
        printf("Hello from the Child process!\n");
    }
    else
    {
        // Parent process
        printf("Hello from the Parent process!\n");
    }
    return 0;
}
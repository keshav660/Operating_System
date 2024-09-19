// write the program to print the process id of child and parent;

#include<stdio.h>
#include<unistd.h>
int main() {
    pid_t pid = fork();

    if (pid < 0) {
        printf("Fork failed!\n");
        return 1;
    } else if (pid == 0) {
        // Child process id
        printf("Hello from the Child process!\n");
      printf(" Child Process ID: %d\n", getpid());
      printf("Parents Process ID : - %d\n", getppid());
     
    } else {
        // Parent process 
        printf("Hello from the Parent process!\n");
        printf("Child Process ID: %d\n", getpid()); 
        printf("Parent Process ID: %d\n", getppid()); 
       
    }
    return 0;
}
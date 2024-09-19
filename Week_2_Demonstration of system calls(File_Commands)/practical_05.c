// II. Write a program to show working of execlp() system call by executing Is command.
#include <stdio.h>
#include <unistd.h>

int main() {
    printf("Executing ls command using execlp():\n");
    execlp("ls", "ls", NULL);
    return 1; 
}

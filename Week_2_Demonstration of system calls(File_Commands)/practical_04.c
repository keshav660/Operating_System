// Write a program to open a directory and list its contents. (use opendir(), readdir(), closedir())
#include <stdio.h>
#include <dirent.h>

int main() {
    DIR *dir;
    struct dirent *entry;
    dir = opendir("/home/welcome_bro/Desktop/Operating_System");

    if (dir == NULL) {
        
        perror("Unable to open directory");//perror :> to print error
        return 1;
    }
    printf("Contents of the directory:\n");
    while ((entry = readdir(dir)) != NULL) {
        printf("%s\n", entry->d_name);
    }

    // Close the directory
    closedir(dir);

    return 0;
}

// Ill. Write a program to read a file and store your details in that file. Your program should also
// create one more file and store your friends details in that file. Once both files are created, print
// lines which are matching in both files.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 256

// Function to write details to a filel
void write_details_to_file(const char *fiename, const char *details) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }
    fprintf(file, "%s", details);
    fclose(file);
}

// Function to compare files and print matching lines
void print_matching_lines(const char *file1, const char *file2) {
    FILE *f1 = fopen(file1, "r");
    FILE *f2 = fopen(file2, "r");
    char line1[MAX_LINE_LENGTH], line2[MAX_LINE_LENGTH];

    if (f1 == NULL || f2 == NULL) {
        perror("Error opening files for comparison");
        exit(EXIT_FAILURE);
    }

    printf("Matching lines:\n");
    while (fgets(line1, MAX_LINE_LENGTH, f1) != NULL) {
        // Remove newline character from the line
        line1[strcspn(line1, "\n")] = 0;

        // Rewind the second file to compare each line
        rewind(f2);
        while (fgets(line2, MAX_LINE_LENGTH, f2) != NULL) {
            line2[strcspn(line2, "\n")] = 0;

            if (strcmp(line1, line2) == 0) {
                printf("%s\n", line1);
            }
        }
    }

    fclose(f1);
    fclose(f2);
}

int main() {
    // Define your details and friend's details
    const char *my_details = "Name: Yogesh\nAge: 20\nRoll No: 2219293\n";
    const char *friend_details = "Name: Keshav\nAge: 21\nRoll No: 2219294\n";

    // File names
    const char *file1 = "my_details.txt";
    const char *file2 = "friend_details.txt";

    // Write details to files
    write_details_to_file(file1, my_details);
    write_details_to_file(file2, friend_details);

    // Compare the files and print matching lines
    print_matching_lines(file1, file2);

    return 0;
}

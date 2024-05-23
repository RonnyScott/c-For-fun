#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

void display_file(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Failed to open file");
        return;
    }

    char buffer[BUFFER_SIZE];
    while (fgets(buffer, BUFFER_SIZE, file)) {
        printf("%s", buffer);
    }

    fclose(file);
}

void append_to_file(const char *filename) {
    FILE *file = fopen(filename, "a");
    if (!file) {
        perror("Failed to open file");
        return;
    }

    char buffer[BUFFER_SIZE];
    printf("Enter text to append (type 'EXIT' on a new line to stop):\n");
    while (1) {
        fgets(buffer, BUFFER_SIZE, stdin);
        if (strcmp(buffer, "EXIT\n") == 0) {
            break;
        }
        fputs(buffer, file);
    }

    fclose(file);
}

int main() {
    char filename[256];
    printf("Enter the filename: ");
    scanf("%s", filename);
    getchar(); // Consume newline character after filename input

    int choice;
    do {
        printf("\nText Editor\n");
        printf("1. Display file\n");
        printf("2. Append to file\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume newline character after choice input

        switch (choice) {
            case 1:
                display_file(filename);
                break;
            case 2:
                append_to_file(filename);
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 3);

    return 0;
}

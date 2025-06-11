#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    // Check that the input file name was provided
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <input file>\n", argv[0]);
        return 1;
    }

    // Open the input file for reading
    int input_fd = open(argv[1], O_RDONLY);
    if (input_fd == -1) {
        perror("Error opening input file");
        return 1;
}

    // Open the output file for writing
    int output_fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (output_fd == -1) {
        perror("Error opening output file");
        close(input_fd);
        return 1;
    }

    // Use dup2() to replace stdout (1) with the output file's file descriptor
    if (dup2(output_fd, 1) == -1) {
        perror("Error dup2'ing output file to stdout");
        close(input_fd);
        close(output_fd);
        return 1;
    }

    // Close the original file descriptors
    close(input_fd);
    close(output_fd);

    // Use the "cat" command to print the contents of the input file to stdout
    execlp("cat", "cat", argv[1], (char *) NULL);

    // If we get here, there was an error executing the "cat" command
    perror("Error executing cat");
    return 1;
}
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 200

int main() {
    int fd;
    char buffer[BUFFER_SIZE];
    char * stop_words[] = {"a", "the", "an", "of", "to", "in", "and"};
    int stop_word_freqs[7] = {0};
    int total_words = 0;
    int total_chars = 0;

    /* create the FIFO (named pipe) */
    create_fifo();

    /* read the sentence from the input file */
    fd = open("inputfile.txt", O_RDONLY);
    read(fd, buffer, BUFFER_SIZE);
    close(fd);

    // tokenize the sentence into words 
    char * token = strtok(buffer, " ");
    while (token != NULL) {
        total_words++;
        total_chars += strlen(token);

        for (int i = 0; i < 7; i++) {
            if (strcmp(token, stop_words[i]) == 0) {
                stop_word_freqs[i]++;
            }
        }

        token = strtok(NULL, " ");
    }

    /* calculate the average word length */
    double avg_word_length = (double) total_chars / total_words;

    /* open the FIFO (named pipe) for writing */
    fd = open("/tmp/fifo_pipe", O_WRONLY);

    /* write the stop word frequencies to the FIFO */
    for (int i = 0; i < 7; i++) {
        char output[32];
        snprintf(output, sizeof(output), "%d %s\n", stop_word_freqs[i], stop_words[i]);
        write(fd, output, strlen(output) + 1);
    }

    /* close the FIFO */
    close(fd);

    /* open the FIFO (named pipe) for reading */
    fd = open("/tmp/fifo_pipe", O_RDONLY);

#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

int main() {
    int fd;
    char * myfifo = "/tmp/fifo_pipe";

    // create the FIFO (named pipe) 
    mkfifo(myfifo, 0666);

    // write "Hello, world!" to the FIFO 
    fd = open(myfifo, O_WRONLY);
    write(fd, "create_fifo", strlen("create_fifo") + 1);
    close(fd);

    // remove the FIFO 
    unlink(myfifo);

    return 0;
}

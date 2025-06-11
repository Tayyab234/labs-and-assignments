#include <iostream>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    // Command 1: mkdir ./myFolder_1 ./myFolder2
    pid_t pid1 = fork();
    if (pid1 == 0) {
        execlp("mkdir","mkdir", "./myFolder_1", "./myFolder2", (char*) NULL);
        perror("execlp failed");
        exit(1);
    }

    // Command 2: mkdir ./myFolder_1/mySubFolder
    pid_t pid2 = fork();
    if (pid2 == 0) {
        execlp("mkdir", "mkdir","./myFolder_1/mySubFolder", (char*) NULL);
        perror("execlp failed");
        exit(1);
    }

    // Command 3: ls -S
    pid_t pid3 = fork();
    if (pid3 == 0) {
        execlp("ls","ls", "-S", (char*) NULL);
        perror("execlp failed");
        exit(1);
    }

    // Wait for all child processes to complete
    int status;
    waitpid(pid1, &status, 0);
    waitpid(pid2, &status, 0);
    waitpid(pid3, &status, 0);

    return 0;
}

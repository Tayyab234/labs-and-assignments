#include <iostream>
#include <sys/shm.h>
#include <string>
#include <errno.h>

class Student {
public:
    int rollNumber;
    char name[20];
};

int main() {
    // Create shared memory segment
    int key = shmget(12321, sizeof(Student) * 3, IPC_CREAT | IPC_EXCL | 0666); // Assuming 3 students, 1 extra for the count
    if (key == -1) {
        perror("Error creating shared memory segment");
        return 1;
    }

    // Attach shared memory segment
    Student* ptr = (Student*)shmat(key, NULL, 0);
    if ((void*)ptr == (void*)-1) {
        perror("Error attaching shared memory segment");
        return 1;
    }

    std::cout << "Shared memory created with id = " << key << std::endl;
    ptr[0].rollNumber = -1;

    std::cout << "Waiting for the client process to send data." << std::endl;
    while (ptr[0].rollNumber == -1); // Busy wait

    std::cout << std::endl;
    for (int i = 1; i <= ptr[0].rollNumber; i++) {
        std::cout << "Roll Number: " << ptr[i].rollNumber << std::endl;
        std::cout << "Name: " << ptr[i].name << std::endl;
        std::cout << std::endl;
    }

    // Detach shared memory segment
    if (shmdt(ptr) == -1) {
        perror("Error detaching shared memory segment");
        return 1;
    }

    // Delete shared memory segment
    if (shmctl(key, IPC_RMID, NULL) == -1) {
        perror("Error deleting shared memory segment");
        return 1;
    }

    return 0;
}

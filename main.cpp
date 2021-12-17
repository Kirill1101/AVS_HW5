#include <iostream>
#include <thread>
#include <vector>
#include <random>
#include "WrongBee.h"

void errMessage1() {
    printf("incorrect command line!\n"
           "  Waited:\n"
           "     command rows columns\n");
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        errMessage1();
        return 1;
    }

    int rows = atoi(argv[1]);
    int columns = atoi(argv[2]);

    // Create forest
    int** forest;
    forest = new int*[rows];
    for (int i = 0; i < rows; i++) {
        forest[i] = new int[columns];
    }

    // Put winnie the pooh
    std::random_device rd;
    forest[rd() % rows][rd() % columns] = 1;

    // Create and start threads
    std::vector<std::thread> threads;
    for (int i = 0; i < rows; ++i) {
        WrongBee* wrongBee = new WrongBee(&forest, i, columns);
        threads.push_back(std::thread(&WrongBee::run, wrongBee));
    }

    // Join threads
    for (int i = 0; i < rows; ++i) {
        threads[i].join();
    }

    return 0;
}

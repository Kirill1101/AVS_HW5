#include <iostream>
#include <string>
#include "WrongBee.h"

void WrongBee::run() {
    for (int i = 0; i < columns; ++i) {
        if (forest[row][i] == 1) {
            std::string str = "Thread " + std::to_string(row) + " Found Winnie the Pooh in the cell "
                    + std::to_string(row) + " " + std::to_string(i) + "\n";
            std::cout << str;
        } else {
            std::string str = "Thread " + std::to_string(row) + " Didn't find Winnie the Pooh in the cell "
                              + std::to_string(row) + " " + std::to_string(i) + "\n";
            std::cout << str;
        }
    }
}

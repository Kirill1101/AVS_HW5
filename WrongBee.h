#ifndef __WrongBee__
#define __WrongBee__
#include <thread>

class WrongBee {
private:
    int row;
    int columns;
    int** forest;
public:
    WrongBee(int*** forest, int row, int columns) {
        this->forest = *forest;
        this->row = row;
        this->columns = columns;
    }

    void run();
};

#endif

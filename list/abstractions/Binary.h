#ifndef GOOD_WORK_BINARY_H
#define GOOD_WORK_BINARY_H

#include <fstream>
class Binary {
public:
    virtual void save_binary(std::ofstream &out) = 0;

    virtual void load_binary(std::ifstream &in) = 0;
};


#endif

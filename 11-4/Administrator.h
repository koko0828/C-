#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H
#include "Security.h"
#include <string>

// declare class here
class Administrator {
public:
    bool Login(string username, string password);
};

#endif
#ifndef SERIALIZEABLE_H
#define SERIALIZEABLE_H

#include <string>

class Serializeable {
    virtual std::string str() = 0;
};

#endif

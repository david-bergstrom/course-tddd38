#ifndef SERIALIZEABLE_H
#define SERIALIZEABLE_H

#include <string>

class Serializeable {
    public:
        virtual ~Serializeable() = 0;
        virtual std::string str() = 0;
};

Serializeable::~Serializeable() { }

#endif

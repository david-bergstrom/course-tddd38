#ifndef CLONEABLE_H
#define CLONEABLE_H

class Cloneable {
    public:
        virtual ~Cloneable() = 0;
        virtual Cloneable * clone() const = 0;
};

Cloneable::~Cloneable() { }

#endif

#ifndef GEOMETRIC_OBJECT_H
#define GEOMETRIC_OBJECT_H

#include "cloneable.h"
#include "serializeable.h"

class GeometricObject : public Cloneable, public Serializeable {
    public:
        virtual ~GeometricObject() = 0;
};

GeometricObject::~GeometricObject() { }

#endif

#ifndef _VECTORSERIALIZER_H
#define _VECTORSERIALIZER_H

#include "master_types.h"

class VectorSerializer {
    public:
        static void deserialize(Vector *v, Stream *s);
        static void deserialize(Vector *v, const byte *buffer);
        static void serialize(const Vector &v, Print *p);
        static void humanReadable(const Vector &v, Print *p);
};

#endif

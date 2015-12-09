#ifndef _DIRECTIONSERIALIZER_H
#define _DIRECTIONSERIALIZER_H

#include "master_types.h"

class DirectionSerializer {
    public:
        static void deserialize(Direction *drct, const byte *buffer);
        static void serialize(const Direction &drct, Print *p);
};

#endif

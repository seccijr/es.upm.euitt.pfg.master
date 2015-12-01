#ifndef _MASTERTYPES_H
#define _MASTERTYPES_H

#include <Arduino.h>
#include <IPAddress.h>
#include "utility/master_definitions.h"

typedef struct {
    byte type;
    union {
        int32_t l;
        float f;
        byte b[4];
    } value;
} Message;

typedef struct {
    byte origin;
    byte target;
    byte method;
    Message message;
} Packet;

#endif

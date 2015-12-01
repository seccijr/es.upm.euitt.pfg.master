#ifndef _ADDRESS_H
#define _ADDRESS_H

#include <Arduino.h>
#include <IPAddress.h>
#include "master_definitions.h"

class AddressClass {
    public:
        AddressClass(const byte *endpoint);
        AddressClass(const byte &resource, const byte *endpoint);
        AddressClass(const byte &first, const byte &second, const byte &third, const byte &fourth);
        byte resource, endpoint[MMT_ENDPOINT_LEN];
};

extern AddressClass Localhost;

#endif

#ifndef _ADDRESS_H
#define _ADDRESS_H

#include <Arduino.h>
#include <IPAddress.h>
#include "master_definitions.h"

class AddressClass {
    public:
        AddressClass();
        AddressClass(const byte *endp);
        AddressClass(const byte &res, const byte *endp);
        AddressClass(const byte &first, const byte &second, const byte &third, const byte &fourth);
        bool match(const AddressClass &addr);
        bool matchResource(const byte &res);
        bool matchEndpoint(const byte *endp);
        bool matchResource(const AddressClass &addr);
        bool matchEndpoint(const AddressClass &addr);
        bool operator==(AddressClass addr);
        byte resource, endpoint[MMT_ENDPOINT_LEN];
};

extern AddressClass Localhost;

#endif

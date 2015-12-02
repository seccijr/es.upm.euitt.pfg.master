#include "Address.h"
#include "master_definitions.h"
#include <IPAddress.h>

AddressClass::AddressClass() {
    resource = 0x00;
    for (int i = 0; i < MMT_ENDPOINT_LEN; i++) {
        endpoint[i] = 0x00;
    }
}

AddressClass::AddressClass(const byte *endp) {
    resource = (byte)MMT_DEF_RESOURCE;
    for (int i = 0; i < MMT_ENDPOINT_LEN; i++) {
        endpoint[i] = endp[i];
    }
}

AddressClass::AddressClass(const byte &res, const byte *endp) {
    resource = res;
    for (int i = 0; i < MMT_ENDPOINT_LEN; i++) {
        endpoint[i] = endp[i];
    }
}

AddressClass::AddressClass(const byte &first, const byte &second, const byte &third, const byte &fourth) {
    endpoint[0] = first;
    endpoint[1] = second;
    endpoint[2] = third;
    endpoint[3] = fourth;
}

bool AddressClass::operator==(AddressClass addr) {
    bool same_resource = resource == addr.resource;
    bool same_endpoint = true;
    for (int i = 0; i < MMT_ENDPOINT_LEN; i++) {
        same_endpoint &= endpoint[i] == addr.endpoint[i];
    }
    return same_resource && same_endpoint;
}

AddressClass Localhost = AddressClass((byte)MMT_DEF_RESOURCE, MMT_DEF_ENDPOINT);
AddressClass Broadcast = AddressClass((byte)MMT_BROADCAST_RESOURCE, MMT_BROADCAST_ENDPOINT);

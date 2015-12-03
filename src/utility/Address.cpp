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

bool AddressClass::match(const AddressClass &addr) {
    bool match_resource = matchResource(addr);
    bool match_endpoint = matchEndpoint(addr);
    return match_resource && match_endpoint;
}

bool AddressClass::matchResource(const byte &res) {
    bool match_resource = false;
    match_resource |= resource == res;
    match_resource |= resource == MMT_ADD_WILDCARD;
    match_resource |= res == MMT_ADD_WILDCARD;
    return match_resource;
}

bool AddressClass::matchEndpoint(const byte *endp) {
    bool match_endpoint = true;
    for (int i = 0; i < MMT_ENDPOINT_LEN; i++) {
        bool match_octect = false;
        match_octect |= endpoint[i] == endp[i];
        match_octect |= endpoint[i] == MMT_ADD_WILDCARD;
        match_octect |= endp[i] == MMT_ADD_WILDCARD;
        match_endpoint &= match_octect;
    }
    return match_endpoint;
}

bool AddressClass::matchResource(const AddressClass &addr) {
    return matchResource(addr.resource);
}

bool AddressClass::matchEndpoint(const AddressClass &addr) {
    return matchEndpoint(addr.endpoint);
}

bool AddressClass::operator==(AddressClass addr) {
    bool same_resource = resource == addr.resource;
    bool same_endpoint = true;
    for (int i = 0; i < MMT_ENDPOINT_LEN; i++) {
        same_endpoint &= endpoint[i] == addr.endpoint[i];
    }
    return same_resource && same_endpoint;
}

AddressClass Localhost((const byte)MMT_DEF_RESOURCE, MMT_DEF_ENDPOINT);

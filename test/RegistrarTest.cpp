#include "utility/master_types.h"
#include "utility/Address.h"
#include "RegistrarTest.h"

void fakeHandler(const Packet &) {}

void RegistrarTest::TestRegisterSubcriber() {
    // Arrange
    RegistrarClass reg = RegistrarClass();
    const AddressClass addr = AddressClass(0xFF, (const byte[4]){0xFF, 0xFF, 0xFF, 0xFF});
    Packet pckt = {};
    pckt.method = MMT_POST;
    Message msg = {};
    msg.type = MMT_LONG;
    msg.value.l = 1L;
    pckt.message = msg;

    // Act
    reg.registerSubscriber(addr, fakeHandler);
    reg.publish(addr, pckt);

    // Assert
    bool published = reg.checkPublished(addr, pckt);
    assertEqual(published, true);
}

void RegistrarTest::setup() {
}

void RegistrarTest::once() {
    TestRegisterSubcriber();
}

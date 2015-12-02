#include "utility/master_types.h"
#include "utility/Address.h"
#include "RegistrarTest.h"

bool called = false;

void fakeHandler(const Packet &) {
    called = true;
}

void RegistrarTest::testRegisterSubcriber() {
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
    bool subscribed = reg.checkSubscribed(addr, fakeHandler);
    assertTrue(subscribed);
    bool published = reg.checkPublished(addr, pckt);
    assertTrue(published);
}

void RegistrarTest::testFlush() {
    // Arrange
    RegistrarClass reg = RegistrarClass();
    const AddressClass addr = AddressClass(0xFF, (const byte[4]){0xFF, 0xFF, 0xFF, 0xFF});
    Packet pckt = {};
    pckt.method = MMT_POST;
    Message msg = {};
    msg.type = MMT_LONG;
    msg.value.l = 1L;
    pckt.message = msg;
    called = false;

    // Act
    reg.registerSubscriber(addr, fakeHandler);
    reg.publish(addr, pckt);
    reg.flushQueue();

    // Assert
    assertTrue(called);
}

void RegistrarTest::setup() {
}

void RegistrarTest::once() {
    testRegisterSubcriber();
    testFlush();
}

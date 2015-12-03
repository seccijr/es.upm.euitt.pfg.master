#include "utility/master_types.h"
#include "utility/Address.h"
#include "RegistrarTest.h"
#include "mock/FakeHandler.h"

void RegistrarTest::testRegisterSubcriber() {
    // Arrange
    FakeHandler fakeHandler;
    RegistrarClass reg = RegistrarClass();
    Message msg = {
        MMT_LONG,
        1L
    };
    Packet pckt = {
        0x03,
        0x04,
        MMT_POST,
        msg
    };
    Vector v = {
        pckt,
        {0x01, 0x01, 0x01, 0x01},
        {0x02, 0x02, 0x02, 0x02}
    };
    AddressClass addr = AddressClass(v.packet.target, v.destination);

    // Act
    reg.registerSubscriber(addr, &fakeHandler);
    reg.publish(v);

    // Assert
    bool subscribed = reg.checkSubscribed(addr, &fakeHandler);
    assertTrue(subscribed);
    bool published = reg.checkPublished(v);
    assertTrue(published);
}

void RegistrarTest::testFlush() {
    // Arrange
    int flag = 0;
    FakeHandler fakeHandler;
    RegistrarClass reg = RegistrarClass();
    Message msg = {
        MMT_LONG,
        1L
    };
    Packet pckt = {
        0x03,
        0x04,
        MMT_POST,
        msg
    };
    Vector v = {
        pckt,
        {0x01, 0x01, 0x01, 0x01},
        {0x02, 0x02, 0x02, 0x02}
    };
    AddressClass addr = AddressClass('*', (const byte[4]){0x02, '*', 0x02, '*'});

    // Act
    reg.registerSubscriber(addr, &fakeHandler);
    reg.publish(v);
    reg.flushQueue();

    // Assert
    assertTrue(fakeHandler.called);
}

void RegistrarTest::setup() {
}

void RegistrarTest::once() {
    testRegisterSubcriber();
    testFlush();
}

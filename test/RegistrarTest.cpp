#include "utility/master_types.h"
#include "RegistrarTest.h"
#include "mock/FakeHandler.h"

void RegistrarTest::testRegisterSubcriber() {
    // Arrange
    FakeHandler fakeHandler;
    RegistrarClass reg = RegistrarClass();
    Address source = {
        0x03,
        {0x01, 0x01, 0x01, 0x01}
    };
    Address destination = {
        0x04,
        {0x02, 0x02, 0x02, 0x02}
    };
    Message msg = {
        MMT_LONG,
        1L
    };
    Packet pckt = {
        MMT_POST,
        msg
    };
    Direction drct = {
        source,
        destination
    };
    Vector v = {
        pckt,
        drct
    };

    // Act
    reg.registerSubscriber(v.direction, &fakeHandler);
    reg.publish(v);

    // Assert
    bool subscribed = reg.checkSubscribed(v.direction, &fakeHandler);
    assertTrue(subscribed);
    bool published = reg.checkPublished(v);
    assertTrue(published);
}

void RegistrarTest::testPublishedFromLocal() {
    // Arrange
    RegistrarClass reg = RegistrarClass();
    Address source = {
        0x03,
        {0x01, 0x01, 0x01, 0x01}
    };
    Address destination = {
        0x04,
        {0x02, 0x02, 0x02, 0x02}
    };
    Message msg = {
        MMT_LONG,
        1L
    };
    Packet pckt = {
        MMT_POST,
        msg
    };
    Direction drct = {
        source,
        destination
    };
    Vector v = {
        pckt,
        drct
    };

    // Act
    reg.publish(v);

    // Assert
    bool published = reg.checkPublished(v);
    assertTrue(published);
}

void RegistrarTest::testFlush() {
    // Arrange
    int flag = 0;
    FakeHandler fakeHandler;
    RegistrarClass reg = RegistrarClass();
    Address source = {
        0x03,
        {0x01, 0x01, 0x01, 0x01}
    };
    Address destination = {
        0x04,
        {0x02, 0x02, 0x02, 0x02}
    };
    Message msg = {
        MMT_LONG,
        1L
    };
    Packet pckt = {
        MMT_POST,
        msg
    };
    Direction drct = {
        source,
        destination
    };
    Vector v = {
        pckt,
        drct
    };
    Address addr = {
        '*',
        {0x02, '*', 0x02, '*'}
    };

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
    testPublishedFromLocal();
    testFlush();
}

#include "utility/master_types.h"
#include "utility/Address.h"
#include "RegistrarTest.h"
#include "mock/FakeRegistrarHandler.h"

void RegistrarTest::TestRegisterSubcriber() {
    RegistrarClass reg = RegistrarClass();
    FakeRegistrarHandlerClass handler = FakeRegistrarHandlerClass();

    AddressClass addr = AddressClass(0xFF, (const byte[4]){0xFF, 0xFF, 0xFF, 0xFF});
    reg.registerSubscriber(&addr, &handler);

    Packet pckt = {};
    pckt.method = MMT_POST;
    Message msg = {};
    msg.type = MMT_LONG;
    msg.value.l = 1L;
    pckt.message = msg;
    reg.publish(&addr, &pckt);
    assertEqual(handler.called_, true);
}

void RegistrarTest::setup() {
}

void RegistrarTest::once() {
    TestRegisterSubcriber();
}

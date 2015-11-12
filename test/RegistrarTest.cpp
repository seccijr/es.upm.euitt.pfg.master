#include <Message.h>
#include "RegistrarTest.h"
#include "FakeRegistrarHandler.h"

using namespace Master;


void RegistrarTest::TestRegisterSubcriber() {
    String msg_str = String("MESSAGE");
    FakeRegistrarHandlerClass handler = FakeRegistrarHandlerClass();

    Address addr = {
        {0xFF, 0xFF, 0xFF, 0xFF},
        {0xFF, 0xFF, 0xFF, 0xFF}
    };
    reg_.RegisterSubscriber(&addr, &handler);

    Packet pckt = {};
    pckt.method = MMT_POST;
    Message msg = {};
    msg.type = MMT_LONG;
    msg.value.l = 1L;
    pckt.msg = &msg;
    reg_.Publish(&addr, &pckt);
    assertEqual(handler.called_, true);
}

void RegistrarTest::setup() {
    reg_ = RegistrarClass();
}

void RegistrarTest::once() {
    TestRegisterSubcriber();
}

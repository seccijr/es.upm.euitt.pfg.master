#include "RegistrarTest.h"
#include "src/Registrar.h"
#include "src/Message.h"
#include "mock/FakeRegistrarHandler.h"

void Master::RegistrarTest::TestRegisterSubcriber() {
    String msg_str = String("MESSAGE");
    MessageClass msg = MessageClass(msg_str);
    String url = String("http://url.com/resource");
    FakeRegistrarHandlerClass handler = FakeRegistrarHandlerClass();
    reg_.RegisterSubscriber(url, handler);
    reg_.Publish(url, msg);
    assertEqual(handler.called_, true);
}

void Master::RegistrarTest::setup() {
    reg_ = RegistrarClass();
}

void Master::RegistrarTest::once() {
    TestRegisterSubcriber();
}

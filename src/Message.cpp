
#include "src/Message.h"

using namespace Master;


MessageClass::MessageClass(const unsigned char value[]) {}

MessageClass::MessageClass(const int &value) {}

MessageClass::MessageClass(const String &value) {}

MessageClass::MessageClass(const float &value) {}

int MessageClass::ToInt() {}

String MessageClass::ToString() {}

float MessageClass::ToFloat() {}

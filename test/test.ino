#include <Arduino.h>
#include <ArduinoUnit.h>
#include <Master.h>
#include "RegistrarTest.h"

Master::RegistrarTest test = Master::RegistrarTest("Master::RegistrarClass");

void setup() {
    Serial.begin(9600);
    while(!Serial) {
        ;
    }
}

void loop() {
    Test::run();
}

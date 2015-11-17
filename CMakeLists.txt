cmake_minimum_required(VERSION 2.8)
set(CMAKE_TOOLCHAIN_FILE cmake/ArduinoToolchain.cmake)
set(PROJECT_NAME Master)
set(ArduinoUnit_RECURSE true)
project(${PROJECT_NAME})

register_hardware_platform(${ARDUINO_SDK_PATH}/hardware/arduino/avr/)
print_board_list()
print_programmer_list()

file(GLOB master_SRCS
    "src/*.cpp")

file(GLOB master_HDRS
    "src/*.h")

file(GLOB test_SRCS
    "test/*.cpp")

file(GLOB test_HDRS
    "test/*.h")

include_directories(src test)

set(test_SKETCH  ${CMAKE_CURRENT_SOURCE_DIR}/test/test.ino)
set(test_SRCS ${master_SRCS} ${test_SRCS})
set(test_HDRS ${master_HDRS} ${test_HDRS})
#set(test_BOARD uno)
set(test_BOARD robotMotor)
set(test_SERIAL picocom @SERIAL_PORT@ -b 9600 -l)
set(test_PORT  /dev/ttyACM3)

generate_arduino_firmware(test)

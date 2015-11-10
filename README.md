Master Arduino library for PFG project

#### To build and test:

> $ rm -rf build/* ; cmake -B./build -H./ && make -C build && make -C build upload && sudo picocom /dev/ttyACM0 -b 9600 -

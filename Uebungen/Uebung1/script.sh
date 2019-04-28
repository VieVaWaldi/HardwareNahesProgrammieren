make $1
avrdude -v -patmega32 -cstk500 -P /dev/ttyACM0 -U flash:w:$1

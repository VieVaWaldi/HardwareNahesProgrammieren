make $1
avrdude -v -patmega32 -cstk500 -P /dev/tty.usbmodem14201 -U flash:w:$1

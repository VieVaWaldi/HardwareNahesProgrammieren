echo $1

make $1
sudo avrdude -v -patmega32 -cstk500 -P /dev/ttyACM0 -U flash:w:$1

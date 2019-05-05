echo $1

make $1
sudo avrdude -v -p atmega32 -c stk500 -P /dev/ttyACM0 -U flash:w:$1

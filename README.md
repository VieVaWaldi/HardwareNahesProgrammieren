# HardwareNahesProgrammieren

// ATmega32
// ATMEL Evalutions-Board V2.0.1 Fertigmodul
// im /dev/ das Geraet verfuegbar (ttyACM0)
// avr-gcc -mmcu=atmega32 -O2 main.c, bei O2 wird compiler optimiert
// avrdude -v -patmega32  -cstk500 -P /dev/ttyACM0 -U flash:w:a.out uebertragen auf den Mikrocompiler
// mikrocontroller.net
// mit avr-gcc -S ein Assembler-Code erstellen

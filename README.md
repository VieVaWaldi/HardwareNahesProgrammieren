# HardwareNahesProgrammieren
Gruppe 6

* ATmega32
* ATMEL Evalutions-Board V2.0.1 Fertigmodul
* mikrocontroller.net

* im /dev/ das Geraet verfuegbar (ttyACM0)

* Bei O2 wird compiler optimiert
`avr-gcc -mmcu=atmega32 -O2 main.c`

* Uebertragen auf den Mikrocompiler
`avrdude -v -patmega32  -cstk500 -P /dev/ttyACM0 -U flash:w:a.out `

* mit ein Assembler-Code erstellen
`avr-gcc -S`

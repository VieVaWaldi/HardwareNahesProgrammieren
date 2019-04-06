#### Hardwarenahe Programmierung

Vcc - positive Spannungsversorgung

Atmega32 vertraegt maximal 6V und 200mA. 

##### I/O - Portkonfiguration

Beim umschalten zwischen tri-state und output high 
```  
  { DDxn, Portxn } = 0b00
  { DDxn, Portxn } = 0b11
```
muss ein Zwischenzustand, mit entweder 
* Pull-up enabled ` { DDxn, Portxn } = 0b01 ` oder 
* output low `{ DDxn, Portxn } = 0b10 `
gesetzt werden.

Ebenso bei input mit Pull-up und output low.
Als Zwischenzustand muss entweder tri-state oder output high eingesetzt werden.

Beispiel:
Auslesen Softwareangelegter PIN-Werte.
Zwischen Lese- und Schreibzugriff (Read/Write) auf Port existiert eine Synchronisationssperre/verzoegerung (=Synclatch) von 2x 1/2 Takt. 
--> Darum 1 Takt NOP einfuegen!

###### C-Programm
```
unsigned char i;

...

/* configure I/O Ports */
PORTB = (1 << PB7) | (1 << PB6) | (1 << PB1) | (1 << PB0);

DDRB = (1 << DBB3) | (1 << DBB2) | (1 << DBB1) | (1 << DBB0);
_NOP(); // No Operation, mache nichts fuer einen Takt

/* Read Port Pins */
i = PINB;

-----------------------------------------------
```

###### Assembler-Programm
```
ldi r16, (1 << PB7) | (1 << PB6) | ...
ldi r17, (1 << DDB3) | (1 << DDB2) | ...
out PORTB, r16 // kann nur Registernummer rausgeben, deswegen brauch ich diese Variablen
out DDRB, r17
nop
in r16, PINB
```

PDIP = Plastic Dual Inline Package

```
    ------
  -|      |-
  -|      |-
  -|      |-
  -|      |-
  -|      |-
  -|      |-
    ------      (zweireihig)



   ------
p-|      |-q
|  ------  |    (SMD = Surface mounted device (Oberflaechenmontage))


    |  |
   ------
 -|      |- 
 -|      |-
   ------
    |  |      (QFP = Quad flat package)

  ```


  RISC = Reduced Instruction Set Computer, befehl dauert nur 1 CPU-Takt.
  Bei Atmel haben wir enhanced RISC, erweitert normale RISC-Befehle um einige zusaetzliche Befehle.

  ARM = Advanced RISC Maschine
  CISC = Complex Instruction Set Computer

  Folien:
  SFIOR = Special Function IO Register
  PIN-Register: Nach Zustand der einzelnen Pins erfragen, welche sind high, welche sind low

### ALU (Arithmetic Logical Unit)
  * Binaere Addition, Multiplikation, Division, Zweierkomplement, Logische Operationen und Bitoperationen (= AND/OR/XOR/NOT)
  * ALU liest aus den Registern, 32x8 Bit
  * Ergebnisse werden dort auch reingeschrieben

  z.B.
  ```
  13 + 24 = 37:
    0 1101
 + 1 1000 
 ======== 
   10 0101 
  ```
  
  Exaktische Ergebnis, wenn 
  * Vorzeichenlos, das Vorzeichenbit nicht gesetzt wird (=Zweierkomplement)
  * ohne Ueberlauf

  Die ALU unterhaelt Statusflags, ueber diese kann man ueberpruefen, ob etwas schief gegangen ist.

  ```
  24 - 13 = 11:
    1 1000 
- 0 1101 
==========
    0 1011
  
  0011 * 1010

     1010
 +1 0100
 =======
   1 1110
 ```

```
 11110 / 11 = 1010
-11
===
  11
- 11
 ===
  --

27 = 0001 1011
~27 = 1110 0100
-27 = 1110 0101

 11111111 (-1)
+00000001 (1)
---------
 00000000 (0)
  ```

### Logische- vs Bitoperationen

  ```
  &&          |     &
  ||          |     |
  !           |     ~
              |     ^ (xor)
              |
Ergebnis:   | 
00000000    | integer
00000001    |
```

zusaetzlich: Bei Verkettung von logischen und/oder kann Auswertung abgebrochen werden, wenn Ergebnis feststeht
              
```
    0010 | 1101         ????
 &  1010   0111      &  1111 (Maske)
===============      =======
    0010   0101         ???? Bitmaske mit &: 0 - Ausschalten, 1 - Unveraendert

    0010 | 1101         ????
 |  1010 | 0111      |  1111 (Maske)
===============      =======
    1010 | 1111         ???? Bitmaske mit |: 0 - Unveraendert, 1 - Einschalten

    0010 | 1101         ??0?
 ^  1010 | 0111      |  0010 (Maske)
===============      =======
    1000 | 1010         !!1! Bitmaske mit ^: Ein- und Ausschalten, egal mit welchem Wert
                     |  0010
                    ========
                        ??0?
```

 ^ Gerne bei Pruefsumme, kommt dann 0 heraus

### Statusregister (=Was ist bei der letzten Operation passiert?)

 Bit | Discription
 --- | -----------
 I-Bit  |   Global Interrupt Enable/Disable
 T-Bit  |   Bit Copy Instructions (BLD, BST)
 H-Bit  |   Half Carry Bit
 S-Bit  |   Sign Bit, stets XOR zwischen N ^ V
 V-Bit  |   Zweierkomplement-Ueberlauf Flag
 N-Bit  |   Negative Flag
 Z-Bit  |   Zero Flag
 C-Bit  |   Carry-Flag Ueberlauf

 Half Carry: Bsp.: BCD-Addition (binary coded decimal)
 
 ```
        2      2
 22 = 0010 | 0010

 22 + 19 
 0010 | 0010 + 0001 | 1001

  0010 0010
 +0001 1001
 ==========
  0011 1011

  3     11 (GEHT NICHT! Uebertrag auf die naechste Stelle. Ausgleich: Adjustment von 6 vornehmen, 0110, Dezimal zu Hexadezimal)
  0011 1011
 +0000 0110
 ==========
  0100 0001 = 41


  39 + 48

  0011 1001 + 0100 1000

  0011 1001 Half Carry impliziert Adjustment + 6 (0110)
 +0100 1000
 ==========
  1000 0001
 +0000 0110
 ==========
  1000 0111
    8    7
 ```

### Inbetriebnahme Evaluationsboard
  1. Programmer an ISP-Schnittstelle (In-System-Programmierung)
  2. USB-Port anschliessen und "mit Linux verbinden" (= /dev/ttyACM0)
  3. Netzteil einstecken

### Entwicklungswerkzeuge
  1. Compiler-Toolchain
  * avr-gcc
  * avr-as
  * avr-ld

  2. avrdude
  * Schreib-/Lesebefehl
  `-U flash:w:<datei>[:<fmt>]`

  flash: Programmspeicher
  :w: Schreiben
  <datei>: Zu schreibende Datei
  <fmt> option: Format, a - Automatisch

  -c <ProgrammerID> z.B. stk500

  -p <chiptyp> z.B. atmega32

  -P <Device> (seriell) z.B. /dev/ttyS0, /dev/ttyACM0

### Serielle Schnittstelle

  * 8 bit, keine Paritaet, 1 Stop-Bit

  ```
    ^
    |
    |
    | (idle)
 5V |-----------    -----    -----    ---
    |           |  |     |  |     |  |
    |           |  |     |  |     |  |
    |           |  |     |  |     |  |
-5V |           ----     ----     ----
    |___________________________________> Stop

  ```

  Uebertragungsrate: Baudrate (Symbolrate)

  Angenommenen Rate = 1 Band/s, dann Einmal pro Sekunde den Leitungszustand ablesen, typischerweise 8x nacheinander ablesen.

  Symbol fuer -5V = 1 } Informationsgehalt 1 bit -> Symbolrate = Bitrate
               5V = 0 }

  Datenrate 8 bit pro 10 Takte

  Fehlererkennung: Paritaet (~sbit)

  gerade Paritaet := Summe aller Bits = 0 oder Anzahl 1er gerade
  ungerade Paritaet := Summe aller Bits = 1 oder Anzahl 1er ungerade

  0 xor 1 xor 0 xor 1 xor 1 xor 0 xor 1 xor 0 xor 0 = 0 (will ich gerade)
  1 xor 1 xor 0 xor 1 xor 1 xor 0 xor 1 xor 0 xor 1 = 0 (will ich ungerade)
                                                          (Paritaetsbit)

  Beispiel: 

  10101100 xor 0 = 0
  10101100 xor 1 = 1


  Beispiel: 
    
  'c' = 0x43 = 0b01000011

  ```
    ^
    |
    |
    |                                                                     <- Start
 5V |-----------                   -----|-----|-----|-----       -----|-----|
    |           |     |     |     |     |     |     |     |     |     |     |
    |   Idle    |     |     |     |     |     |     |     |     |     |     |   (next frame)
    |           |Start|  1  |  1  |  0  |  0  |  0  |  0  |  1  |  0  |Stop |
-5V |            -----|-----|-----                         -----      
    |_____________________________________________________________________> 

  ```


  ```
  111 12V ^
  110  8V |
  101  5V |
  100  3V |
          |
  011  0V |
          |
  010 -3V |
  001 -5V |
  000 -8V |
          |___________________________________> Stop
  ```

### USART-Register

  Register | Description
  -------- | -----------
  UBRR | Baudrate Register (16 Bit) Low/High (UBRRL, UBRRH)
  UDR | Datenregister Transfer (schreiben) und Empfang (lesen)
  UCSR (A,B,C) | Statusregister fuer Konfiguration
  
  Alle drei Teile haben Zugriff auf Statusregister. (Clock Generator, Receiver und Transmitter)

  Register | Description
  -------- | -----------
  UCSRC | * mode (asnc/sync)
          * Frameformat (bits, stopbit(s), parity)
          * clock polarity (nur synchron)
  
  UCSRB | * Aktivieren von 
              * Interrupts und Sende-/Empfangslogik

  UCSRA | * Status und Error-Flags

  Die Register UCSRC und UBRRH teilen sich eine Busaddresse (=I/O-Location). Das Bit URSEL entscheidet, auf welches Register zugegriffen wird.
  Ist `(1 << URSEL)` dann wird auf UCSRC geschrieben, sonst wird UBRRH verwendet (R/W).
  Soll UCSRC gelesen werden, dann muss erst UBRRH und dann im naechsten Zyklus UCSRC gelesen werden.
  Dies MUSS eine atomare Operation sein. (Interrupts sollten hier deaktiviert sein)

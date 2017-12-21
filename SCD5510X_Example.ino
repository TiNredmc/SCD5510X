//This is example code for load data bit to SCD5510X 10 digits 5x5 display from osram (or siemens).

#include <SPI.h> //init. library for spi device .I will communicate with SCD5510X via SPI bus interface .
int Load= 10;

void setup(){
pinMode(Load, OUTPUT);//set pin10 to output for switching "send bit" or "display data out"
SPI.begin(); //init. SPI Library .
SPI.setBitOrder(LSBFIRST);//Swap bit from MSB to LSB as first .arcoding to scd5510X datasheet .Thy start at d0 but arduino start bit at d7(8 bit SPI)
digitalWrite(Load, LOW);
SPI.transfer(0xC0); // clear display
digitalWrite(Load, HIGH);
digitalWrite(Load, LOW);
SPI.transfer(0xF8); // test lamp
digitalWrite(Load, HIGH);
delay(1000); // just wait for 1 sec ;D
digitalWrite(Load, LOW);
SPI.transfer(0xC0); // clear display after test lamp
digitalWrite(Load, HIGH);
}


void loop(){
digitalWrite(Load, LOW);
SPI.transfer(0xB0);// select digit 0 for'T'
SPI.transfer(0x1F);//11111
SPI.transfer(0x24);//00100
SPI.transfer(0x44);//00100   T
SPI.transfer(0x64);//00100
SPI.transfer(0x84);//00100
SPI.transfer(0xB1);// select digit 1 for 'i'
SPI.transfer(0x04);//00100
SPI.transfer(0x20);//00000
SPI.transfer(0x4C);//01100   i
SPI.transfer(0x64);//00100
SPI.transfer(0x8E);//01110
SPI.transfer(0xB2);// select digit 2 for'n'
SPI.transfer(0x00);//00000
SPI.transfer(0x36);//10110
SPI.transfer(0x59);//11001   n
SPI.transfer(0x71);//10001
SPI.transfer(0x91);//10001
SPI.transfer(0xB3);// select digit 3 for 'L'
SPI.transfer(0x10);//10000
SPI.transfer(0x30);//10000
SPI.transfer(0x50);//10000   L
SPI.transfer(0x70);//10000
SPI.transfer(0x9F);//11111
SPI.transfer(0xB4);// select digit 4 for'e'
SPI.transfer(0x00);//00000
SPI.transfer(0x2E);//01110
SPI.transfer(0x5F);//11111   e
SPI.transfer(0x70);//10000
SPI.transfer(0x8E);//01110
SPI.transfer(0xB5);// select digit 5 for't'
SPI.transfer(0x08);//11111
SPI.transfer(0x3C);//00100
SPI.transfer(0x48);//00100   t
SPI.transfer(0x6A);//00100
SPI.transfer(0x84);//00100
SPI.transfer(0xB6);// select digit 6 for'H'
SPI.transfer(0x11);//10001
SPI.transfer(0x31);//10001
SPI.transfer(0x5F);//11111   H
SPI.transfer(0x71);//10001
SPI.transfer(0x8f);//10001
SPI.transfer(0xB7);// select digit 7 for 'a'
SPI.transfer(0x00);//00000
SPI.transfer(0x2E);//01110
SPI.transfer(0x52);//10010   a
SPI.transfer(0x72);//10010
SPI.transfer(0x8D);//01101
SPI.transfer(0xB8);// select digit 8 for'x'
SPI.transfer(0x00);//00000
SPI.transfer(0x32);//10010
SPI.transfer(0x4C);//01100   x
SPI.transfer(0x6C);//01100
SPI.transfer(0x92);//10001
SPI.transfer(0xB9);// select digit 9 for '!'
SPI.transfer(0x04);//00100
SPI.transfer(0x24);//00100
SPI.transfer(0x44);//00100   !
SPI.transfer(0x60);//00000
SPI.transfer(0x84);//00100
digitalWrite(Load, HIGH);
digitalWrite(Load, LOW);
SPI.transfer(0xC0); // clear display
digitalWrite(Load, HIGH);
}

//This is example code for load data bit to SCD5510X 10 digits 5x5 display from osram (or siemens).

#include<SPI.h> //init. library for spi device .I will communicate with SCD5510X via SPI bus interface .
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
SPI.transfer(0xB8);// select digit 8 for'H'
SPI.transfer(0x11);//10001
SPI.transfer(0x31);//10001
SPI.transfer(0x5F);//11111   H
SPI.transfer(0x71);//10001
SPI.transfer(0x8f);//10001
SPI.transfer(0xB9);// select digit 10 for 'I'
SPI.transfer(0x0E);//01110
SPI.transfer(0x24);//00100
SPI.transfer(0x44);//00100   I
SPI.transfer(0x64);//00100
SPI.transfer(0x8E);//01110
digitalWrite(Load, HIGH);
digitalWrite(Load, LOW);
SPI.transfer(0xC0); // clear display
digitalWrite(Load, HIGH);
}

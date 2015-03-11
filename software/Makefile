AVR=atmega16m1
CC=avr-gcc
CFLAGS=-Os -g -Wall -std=c99 -mmcu=$(AVR)

AVRDUDE=avrdude
AVR_AVRD=m16

ELF=bin/blink.elf
HEX=bin/blink.hex


all: program

build:
	$(CC) $(CFLAGS) -c src/main.c -o obj/main.o
	$(CC) $(CFLAGS) obj/main.o -o $(ELF)
	
hex: build
	avr-objcopy -j .text -j .data -O ihex $(ELF) $(HEX)
	
program: hex
	$(AVRDUDE) -F -V -c usbtiny -p $(AVR_AVRD) -U flash:w:$(HEX)


#PHONY
fuse:
	$(AVRDUDE) -c usbtiny -p $(AVR_AVRD) -F -U lfuse:w:0xef:m

clean:
	rm -rf bin/*.hex bin/*.elf obj/*.o

.PHONY: fuse clean

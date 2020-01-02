
TARGET = bldc
MCU = atmega328p
SOURCES = src/main.c src/adc.c src/pwm.c src/uart.c src/bldc.c

PROGRAMMER = arduino
PORT = /dev/ttyUSB0
BAUD = 57600



OBJECTS=$(SOURCES:.c=.o)
CFLAGS=-c -Os -I include
# LDFLAGS=

all: $(TARGET).hex clean_tmp

$(TARGET).hex: $(TARGET).elf
	avr-objcopy -j .text -j .data -O ihex $(TARGET).elf $(TARGET).hex

$(TARGET).elf: $(OBJECTS)
	avr-gcc -mmcu=$(MCU) $(OBJECTS) -o $(TARGET).elf

.c.o:
	avr-gcc $(CFLAGS) -mmcu=$(MCU) $< -o $@

program:
	avrdude -p $(MCU) -c $(PROGRAMMER) -P $(PORT) -b $(BAUD) -D -U flash:w:$(TARGET).hex:i

clean_tmp:
	rm -rf src/*.o
	rm -rf src/*.elf
	rm -rf *.elf

clean:
	rm -rf src/*.o
	rm -rf src/*.elf
	rm -rf *.elf
	rm -rf *.hex
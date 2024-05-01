COMMON_OBJECTS		= demos.o p2_interrupt_handler.o stateMachine.o switches.o buzzer.o melody.o

CPU             	= msp430g2553
CFLAGS          	= -mmcu=${CPU} -Os -I../h
LDFLAGS = -L../lib -L/opt/ti/msp430_gcc/include/ 
CC              = msp430-elf-gcc
AS              = msp430-elf-gcc -mmcu=${CPU} -c

all: main.elf #what are .elf files?

main.elf: ${COMMON_OBJECTS} main.o
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^ -lTimer -lLcd 

load: main.elf
	msp430loader.sh $^

clean:
	rm -f *.o *.elf

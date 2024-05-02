COMMON_OBJECTS		= game.o music.o

CPU             	= msp430g2553
CFLAGS          	= -mmcu=${CPU} -Os -I../h
LDFLAGS = -L../lib -L/opt/ti/msp430_gcc/include/ 
CC              = msp430-elf-gcc
AS              = msp430-elf-gcc -mmcu=${CPU} -c

all: game.elf #what are .elf files?

game.elf: ${COMMON_OBJECTS} game.o
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^ -lTimer -lLcd 

load: game.elf
	msp430loader.sh $^

clean:
	rm -f *.o *.elf

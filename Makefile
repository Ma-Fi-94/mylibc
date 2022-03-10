SRC = libstring.c
DEST = libstring.elf
CC_FLAGS = -Wall -Wextra -fsanitize=address
CC = clang

go: clean all run

clean:
	rm -f *.elf

all:
	${CC} ${SRC} ${CC_FLAGS} -o ${DEST}

run:
	./libstring.elf



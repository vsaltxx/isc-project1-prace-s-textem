TARGET=t9search
COMPILER=gcc
COMPILE=$(COMPILER) -std=c99 -Wall -Wextra -Werror $(TARGET).c -o $(TARGET)

default: all

all:
	$(COMPILER) -std=c99 -Wall -Wextra -Werror $(TARGET).c -o $(TARGET)


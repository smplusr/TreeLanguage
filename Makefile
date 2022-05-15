SOURCE	= $(shell find src/ -name *.c)
SCRIPT	= $(shell find bin/ -name *.t)
TARGET	= tl.elf

CC	= gcc -O2 -fpic -no-pie -w -o


all:	$(TARGET) run

$(TARGET):	$(SOURCE)
	$(CC) $@ $^
	mv $@ bin/

clean:	$(JUNK)
	$(RM) $<

run:	$(TARGET)
	./bin/$< -f $(SCRIPT) -d

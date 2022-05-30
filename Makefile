LDFLAGS = -L. library.so -Wl,-rpath='.' 
CFLAGS	= -w -Og -fPIC -no-pie


TARGET	= tl.elf
LIBRARY	= library.so



all:	$(LIBRARY) $(TARGET)
	mv *.so *.elf bin/

clean:	bin/*
	$(RM) $^



%.so:	$(shell find lib/ -name *.c)
	$(CC) $(CFLAGS) -fPIC -shared -o $@ $^


%.elf:	$(shell find src/ -name *.c)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)



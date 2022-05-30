LDFLAGS = -L. $(LIBRARY) -Wl,-rpath='.' 
CFLAGS	= -Og -fPIC -no-pie


TARGET	= tl.elf
LIBRARY	= library.so



all:	clean $(LIBRARY) $(TARGET)
	mv *.so *.elf bin/

clean:	$(shell find -name *.so) $(shell find -name *.elf)
	$(RM) $^



%.so:	$(shell find lib/ -name *.c)
	$(CC) $(CFLAGS) -fPIC -shared -o $@ $^


%.elf:	$(shell find src/ -name *.c)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)



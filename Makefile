TARGET=add-nbo
CC = gcc
CFLAGS = -w

all: $(TARGET)

$(TARGET): add-nbo.c
	gcc $(CFLAGS) $^ $(LOADLIBES) $(LDLIBS) -o $@

clean:
	rm -f $(TARGET)

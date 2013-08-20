CC     := gcc
CFLAGS := -Wall -g -O2 -Iinclude
SOURCES := $(shell find src -name '*.c')
OBJECTS := $(SOURCES:.c=.o)

all: $(SOURCES) libSCCL.a

libSCCL.a: $(OBJECTS)
	ar rs libSCCL.a $(OBJECTS)
	rm -rf src/*.o

.c.o:
	$(CC) $(CFLAGS) $< -c -o $@

clean:
	rm -rf src/*.o libSCCL.a


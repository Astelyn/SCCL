CC     := gcc
CFLAGS := -Wall -g -O2
SOURCES := $(shell find . -name '*.c')
OBJECTS := $(SOURCES:.c=.o)

all: $(SOURCES) libSCCL.a

libSCCL.a: $(OBJECTS)
	ar rs libSCCL.a $(OBJECTS)
	rm -rf *.o

.c.o:
	$(CC) $(CFLAGS) $< -c -o $@

clean:
	rm -rf *.o libSCCL.a


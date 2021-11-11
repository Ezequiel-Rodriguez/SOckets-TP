include ../Makefile.inc

SOURCES := $(wildcard *.c)

U_TARGET := $(../user)
S_TARGET := $(../server)

OBJECTS := $(wildcard *.o)
TARGETS := $(S_TARGET) $(U_TARGET)

# TODO: build user and server independently

all: $(OBJECTS)
	$(GCC) $(GCCFLAGS) $< -o $(TARGETS)
	@rm -rf $(OBJECTS)

$(OBJECTS): $(SOURCES)
	$(GCC) $(GCCFLAGS) -I./include -c $< -o $@ $(GCCLINKFLAGS)

clean:
	@rm -rf $(TARGETS)

include ../Makefile.inc

S_SOURCES := server.c challenges.c
C_SOURCES := client.c

S_OBJECTS := server.o challenges.o
C_OBJECTS := client.o

C_TARGET := ../client
S_TARGET := ../server
TARGETS := $(S_TARGET) $(C_TARGET)

# TODO: build user and server independently

all:
	make server;
	make client;

server: $(S_OBJECTS)
	$(GCC) $(GCCFLAGS) $< -o $(S_TARGET)
	@rm -rf $(S_OBJECTS)

$(S_OBJECTS): $(S_SOURCES)
	$(GCC) $(GCCFLAGS) -I./include -c $< -o $@ $(GCCLINKFLAGS)

client: $(C_OBJECTS)
	$(GCC) $(GCCFLAGS) $< -o $(C_TARGET)
	@rm -rf $(C_OBJECTS)

$(C_OBJECTS): $(C_SOURCES)
	$(GCC) $(GCCFLAGS) -c $< -o $@ $(GCCLINKFLAGS)

clean:
	@rm -rf $(TARGETS)

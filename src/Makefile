include ../Makefile.inc

S_SOURCES := server.c 
CHAL_SOURCES := challenges.c
C_SOURCES := client.c

S_OBJECTS := server.o 
CHAL_OBJECTS := challenges.o
C_OBJECTS := client.o

C_TARGET := ../client
S_TARGET := ../server
TARGETS := $(S_TARGET) $(C_TARGET)

# TODO: build user and server independently

all:
	make server;
	make client;

server: $(S_OBJECTS) $(CHAL_OBJECTS)
	$(GCC) $(GCCFLAGS) $(S_OBJECTS) $(CHAL_OBJECTS) -o $(S_TARGET) $(GCCLINKFLAGS)
	@rm -rf $(S_OBJECTS)
	@rm -rf $(CHAL_OBJECTS)

$(S_OBJECTS): $(S_SOURCES)
	$(GCC) $(GCCFLAGS) -I./include -c $< -o $@ $(GCCLINKFLAGS)
	
$(CHAL_OBJECTS): $(CHAL_SOURCES)
	$(GCC) $(GCCFLAGS) -I./include -c $< -o $@ $(GCCLINKFLAGS)

client: $(C_OBJECTS)
	$(GCC) $(GCCFLAGS) $< -o $(C_TARGET)
	@rm -rf $(C_OBJECTS)

$(C_OBJECTS): $(C_SOURCES)
	$(GCC) $(GCCFLAGS) -c $< -o $@ $(GCCLINKFLAGS)

clean:
	@rm -rf $(TARGETS)
	@rm -rf $(S_OBJECTS)
	@rm -rf $(CHAL_OBJECTS)

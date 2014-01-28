# Default
CFLAGS += -Wall
LDFLAGS += 

#
# Files
#
SOURCES = $(wildcard src/*.c)
OBJECTS = $(patsubst src/%.c, obj/%.o, $(SOURCES))
BINARY = bin/test

#
# Build rules
#
all: $(BINARY)

clean:
	rm -rf bin
	rm -rf obj

run: $(BINARY)
	exec $(BINARY)

$(BINARY): $(OBJECTS)
	mkdir -p bin
	$(CC) $(LDFLAGS) $^ -o $@

obj/%.o: src/%.c
	mkdir -p obj
	$(CC) $(CFLAGS) -c $< -o $@

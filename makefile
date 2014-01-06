# Default
CFLAGS += -Wall
LDFLAGS += 

#
# Files
#
SOURCES = $(wildcard src/*.c)
OBJECTS = $(patsubst src/%.c, obj/%.o, $(SOURCES))
BINARY = out/test

#
# Build rules
#
all: $(BINARY)

clean:
	rm -rf out
	rm -rf obj

run: $(BINARY)
	exec $(BINARY)

$(BINARY): $(OBJECTS)
	mkdir -p out
	$(CC) $(LDFLAGS) $^ -o $@

obj/%.o: src/%.c
	mkdir -p obj
	$(CC) $(CFLAGS) -c $< -o $@

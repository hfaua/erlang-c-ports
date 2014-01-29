# Default
CFLAGS += -Wall
LDFLAGS += 

#
# Files
#
ERLANG_UTILS_OBJECTS = src/read.c src/write.c
SIMPLE_TEST = bin/rewrite
COMPUTATION_TEST = bin/compute

#
# Build rules
#
all: $(SIMPLE_TEST) $(COMPUTATION_TEST)

clean:
	rm -rf bin
	rm -rf obj

$(SIMPLE_TEST): obj/rewrite.o $(ERLANG_UTILS_OBJECTS)
	mkdir -p bin
	$(CC) $(LDFLAGS) $^ -o $@

$(COMPUTATION_TEST): obj/compute.o obj/recursion.o $(ERLANG_UTILS_OBJECTS)
	mkdir -p bin
	$(CC) $(LDFLAGS) $^ -o $@

obj/%.o: src/%.c
	mkdir -p obj
	$(CC) $(CFLAGS) -c $< -o $@

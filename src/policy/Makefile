
.PHONY: all
all: lib.a

lib.a: lib.o
	ar rcs $@ $^

test: lib.o ../parse/lib.a ../list/lib.a ../hashmap/lib.a

.PHONY: clean
clean:
	rm -f lib.a lib.o test

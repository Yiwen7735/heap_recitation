all: clobber main

linked_node.o: linked_node.c linked_node.h
	clang -c linked_node.c

main: main.c linked_node.o
	clang main.c linked_node.o -o main

clean:
	rm -rf *.o

clobber: clean
	rm -rf main

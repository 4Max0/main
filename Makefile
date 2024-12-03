all: 
	compile 
	run
	clean

compile:
	gcc main.c -o LLTest linked_list.c

run: 
	./LLTest
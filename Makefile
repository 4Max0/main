FLAGS=
DEPEN= src/graph.c

all: compile run clean

compile:
	gcc $(FLAGS) main.c -o ./out/graph $(DEPEN)

run:
	./out/graph

clean:
	powershell -Command "Remove-Item .\out\* -Recurse -Force"
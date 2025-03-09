all: parse file distance similarity test

parse:
	gcc -c parse.c

file:
	gcc -c file.c

distance: parse file
	gcc -c distance.c distanceLauncher.c
	gcc -o distance parse.o file.o distance.o distanceLauncher.o

similarity: parse file
	gcc -c similarity.c similarityLauncher.c
	gcc -o similarity parse.o file.o similarity.o similarityLauncher.o

test: distance similarity
	gcc -c test.c
	gcc -o test parse.o file.o distance.o similarity.o test.o

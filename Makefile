all: parse reader distance similarity test

parse:
	gcc -c parse.c

reader:
	gcc -c reader.c

distance: parse reader
	gcc -c distance.c distanceLauncher.c
	gcc -o distance parse.o reader.o distance.o distanceLauncher.o

similarity: parse reader
	gcc -c similarity.c similarityLauncher.c
	gcc -o similarity parse.o reader.o similarity.o similarityLauncher.o

test: distance similarity
	gcc -c test.c
	gcc -o test parse.o reader.o distance.o similarity.o test.o

all: reader distance similarity test

reader:
	gcc -c reader.c

distance: reader
	gcc -c distance.c distanceLauncher.c
	gcc -o distance reader.o distance.o distanceLauncher.o

similarity: reader
	gcc -c similarity.c similarityLauncher.c
	gcc -o similarity reader.o similarity.o similarityLauncher.o

test: distance similarity
	gcc -c test.c
	gcc -o test distance.o similarity.o test.o

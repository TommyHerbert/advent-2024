all: args file distance similarity test

args:
	gcc -c args.c

file:
	gcc -c file.c

distance: args file
	gcc -c distance.c distanceLauncher.c
	gcc -o distance args.o file.o distance.o distanceLauncher.o

similarity: args file
	gcc -c similarity.c similarityLauncher.c
	gcc -o similarity args.o file.o similarity.o similarityLauncher.o

test: distance similarity
	gcc -c test.c
	gcc -o test args.o file.o distance.o similarity.o test.o

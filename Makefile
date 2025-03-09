all: args file distance similarity test

args:
	gcc -c args.c

file:
	gcc -c file.c

distance: args file
	gcc -c distance.c distance_launcher.c
	gcc -o distance args.o file.o distance.o distance_launcher.o

similarity: args file
	gcc -c similarity.c similarity_launcher.c
	gcc -o similarity args.o file.o similarity.o similarity_launcher.o

test: distance similarity
	gcc -c test.c
	gcc -o test args.o file.o distance.o similarity.o test.o

clean:
	rm *.o distance similarity test


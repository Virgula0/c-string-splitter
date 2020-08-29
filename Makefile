all: splitter.o main.o merge

merge: main.c splitter.h splitter.c
	cc main.o splitter.o -o main

main.o: main.c splitter.h
	cc -c main.c -o main.o

splitter.o: splitter.h splitter.c
	cc -c splitter.c -o splitter.o

clean:
	rm main
	rm *.o

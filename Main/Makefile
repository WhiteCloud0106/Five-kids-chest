all: main.c function.o
	cc main.c function.o

function.o: function.c function.h
	cc -c function.c

clean:
	rm -f *.o a.out *.*~
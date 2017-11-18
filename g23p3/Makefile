all: ex1 ex2

ex1: g23p3c1.o
	g++ g23p3c1.o -o ex1
g23p3c1.o:
	g++ -c g23p3c1.cpp -o g23p3c1.o

ex2: g23p3c2.o
	g++ g23p3c2.o -o ex2
g23p3c2.o:
	g++ -c g23p3c2.cpp -o g23p3c2.o

clean:
	rm *.o

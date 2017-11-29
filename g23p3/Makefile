all: ex1 ex2 ex2c

ex1: g23p3c1.o
	g++ g23p3c1.o -o ex1
g23p3c1.o:
	g++ -c g23p3c1.cpp -o g23p3c1.o

ex2: g23p3c2.o
	g++ g23p3c2.o -o ex2
g23p3c2.o:
	g++ -c g23p3c2.cpp -o g23p3c2.o

ex2c: g23p3c2c.o
	g++ g23p3c2c.o -o ex2c
g23p3c2c.o:
	g++ -c g23p3c2c.cpp -o g23p3c2c.o

test_vector:
	g++ test_vector.cpp -o test_vector

clean:
	rm *.o

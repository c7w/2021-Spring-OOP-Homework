all: main.o product.o sum.o functions.h
	g++ main.o product.o sum.o -o main

%.o: %.cpp functions.h
	g++ -c $< -o $@ 

clean:
	rm -f *.o
	rm -f main

main: main.o graph.o node.o operation.o mymap.o operationMinus.o operationPlus.o
	g++ -std=c++11 -o main main.o graph.o node.o operation.o operationPlus.o operationMinus.o mymap.o 
main.o: main.cpp
	g++ -c -std=c++11 -o main.o main.cpp 
graph.o: graph.cpp graph.h mymap.h node.h operation.h
	g++ -c -std=c++11 -o graph.o graph.cpp 
node.o: node.cpp node.h
	g++ -c -std=c++11 -o node.o node.cpp 
operation.o: operation.cpp operation.h node.h
	g++ -c -std=c++11 -o operation.o operation.cpp 
operationPlus.o: operationPlus.cpp operationPlus.h node.h operation.h operation.cpp
	g++ -c -std=c++11 -o operationPlus.o operationPlus.cpp 
operationMinus.o: operationMinus.cpp operationMinus.h node.h operation.h operation.cpp
	g++ -c -std=c++11 -o operationMinus.o operationMinus.cpp 
mymap.o: mymap.cpp mymap.h 
	g++ -c -std=c++11 -o mymap.o mymap.cpp 
clean:
	rm main *.o

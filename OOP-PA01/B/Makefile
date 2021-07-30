include control.mak

FF1=
FF2=
FF3=
FF4=

FFA1=
FFA2=
FFA3=
FFA4=

ifeq (TRUE, $(F1))
	FF1 = -D __F1__
	FFA1 = g++ -c f1.cpp
endif

ifeq (TRUE, $(F2))
	FF2 = -D __F2__
	FFA2 = g++ -c f2.cpp
endif

ifeq (TRUE, $(F3))
	FF3 = -D __F3__
	FFA3 = g++ -c f3.cpp
endif

ifeq (TRUE, $(F4))
	FF4 = -D __F4__
	FFA4 = g++ -c f4.cpp
endif

main: control.mak
	g++ -c main.cpp $(FF1) $(FF2) $(FF3) $(FF4)
	$(FFA1)
	$(FFA2)
	$(FFA3)
	$(FFA4)
	g++ *.o -o main

clean:
	rm *.o
	rm main
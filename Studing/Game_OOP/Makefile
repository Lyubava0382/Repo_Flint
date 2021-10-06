All: main.o Field.o Iterator.o Cell.o
	g++ main.o Field.o Iterator.o Cell.o
main.o: main.cpp Field.h Cell.h Iterator.h
	g++ -c main.cpp
Field.o: Field.cpp Field.h Cell.h
	g++ -c Field.cpp
Iterator.o: Iterator.cpp Iterator.h Cell.h Field.h
	g++ -c Iterator.cpp
Cell.o: Cell.cpp Cell.h
	g++ -c Cell.cpp
clean:
	rm *.o a.out

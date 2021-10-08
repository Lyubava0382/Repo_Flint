All: main.o Cell.o Field.o Iterator.o
	g++ main.o Cell.o Field.o Iterator.o
main.o: main.cpp ./Field/Field.h ./Iterator/Iterator.h
	g++ -c main.cpp
Cell.o: ./Cell/Cell.cpp ./Cell/Cell.h
	g++ -c ./Cell/Cell.cpp
Iterator.o: ./Iterator/Iterator.cpp ./Iterator/Iterator.h
	g++ -c ./Iterator/Iterator.cpp
Field.o: ./Field/Field.cpp ./Field/Field.h
	g++ -c ./Field/Field.cpp
clean:
	rm *.o a.out

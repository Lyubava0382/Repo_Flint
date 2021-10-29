All: main.o Cell.o Field.o Iterator.o
	g++ main.o -o game-lauch -lsfml-graphics -lsfml-window -lsfml-system Cell.o Field.o Iterator.o
main.o: main.cpp Game/Field Game/Iterator
	g++ -c main.cpp
Cell.o: Game/Cell Game/Cell Game/Cell
	g++ -c ./Cell/Cell.cpp
Iterator.o: Game/Iterator Game/Iterator
	g++ -c ./Iterator/Iterator.cpp
Field.o: Game/Field Game/Field
	g++ -c ./Field/Field.cpp
clean:
	rm *.o game-lauch

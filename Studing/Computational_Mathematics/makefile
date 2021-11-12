ALL: main_sfml.o
	g++ main_sfml.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system
main_sfml.o: main_sfml.cpp
	g++ -c main_sfml.cpp
clean:
	rm *.o sfml-app

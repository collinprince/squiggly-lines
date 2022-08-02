CC = g++
CFLAGS = -std=c++17 -Wall

SQUIGGLY_DEPS = main.o $(MAIN_DEPS)
MAIN_DEPS = line.o quadraticLine.o linearLine.o color.o
LINE_DEPS = color.o lines/line.hpp lines/line.cpp imageSettings.hpp
COLOR_DEPS = color.hpp color.cpp



squiggly: main.o graph.hpp shapes/shape.hpp shapes/circle.hpp shapes/rectangle.hpp
	$(CC) -o squiggly $(SQUIGGLY_DEPS)

main.o: $(MAIN_DEPS) main.cpp
	$(CC) $(CFLAGS) -c main.cpp 

linearLine.o: line.o lines/linearLine.hpp
	$(CC) $(CFLAGS) -c lines/linearLine.cpp

quadraticLine.o: line.o lines/quadraticLine.hpp
	$(CC) $(CFLAGS) -c lines/quadraticLine.cpp 

line.o: $(LINE_DEPS)
	$(CC) $(CFLAGS) -c lines/line.cpp 

color.o: $(COLOR_DEPS)
	$(CC) $(CFLAGS) -c color.cpp

clean:
	rm -f squiggly main.o line.o color.o quadraticLine.o linearLine.o
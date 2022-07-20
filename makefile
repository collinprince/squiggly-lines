CC = g++
CFLAGS = -std=c++17

MAIN_DEPS = mathLine.o quadraticLine.hpp
MATHLINE_DEPS = color.o mathLine.hpp mathLine.cpp imageSettings.hpp
COLOR_DEPS = color.hpp color.cpp



squiggly: main.o
	$(CC) -o squiggly main.o color.o mathLine.o

main.o: $(MAIN_DEPS)
	$(CC) $(CFLAGS) -c main.cpp

mathLine.o: $(MATHLINE_DEPS)
	$(CC) $(CFLAGS) -c mathLine.cpp

color.o: $(COLOR_DEPS)
	$(CC) $(CFLAGS) -c color.cpp

clean:
	rm -f squiggly main.o mathLine.o color.o
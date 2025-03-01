CC=g++
CFLAGS=-std=c++17 -Wall -Wextra -O3 -march=native -lsfml-graphics -lsfml-window -lsfml-system
CFLAGS_DEBUG=-std=c++17 -O0 -g -lsfml-graphics -lsfml-window -lsfml-system
SOURCES=src/main.cpp src/app.cpp src/map.cpp src/forecast.cpp
EXECUTABLE=AeroFly.out

build: $(SOURCES)
	$(CC) $(CFLAGS) $(SOURCES) -o $(EXECUTABLE)

debug: $(SOURCES)
	$(CC) $(CFLAGS_DEBUG) $(SOURCES) -o $(EXECUTABLE)

clean: $(EXECUTABLE)
	rm ./AeroFly.out

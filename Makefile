PROGRAM = theTraveler
CXX     = g++
CXXFLAGS  = -g -std=c++17 -Wall -I/usr/X11R6/include -I/usr/pkg/include
LDFLAGS = -L/usr/X11R6/lib -L/usr/pkg/lib
LDLIBS  = -lglfw -lglut -lGLU -lGL -lm

$(PROGRAM): main.o camera.o keyboard.o
	$(CXX) $(LDFLAGS) -o $(PROGRAM) $^ $(LDLIBS)

main.o: sources/main.cpp
	$(CXX) $(CXXFLAGS) -c sources/main.cpp $(LDLIBS)

keyboard.o: sources/keyboard.cpp headers/keyboard.hpp headers/camera.hpp
	$(CXX) $(CXXFLAGS) -c sources/keyboard.cpp $(LDLIBS)

camera.o: sources/camera.cpp headers/camera.hpp
	$(CXX) $(CXXFLAGS) -c sources/camera.cpp $(LDLIBS)




.PHONY: clean dist

clean:
	-rm *.o $(PROGRAM) *core

dist: clean
	-tar -chvj -C .. -f ../$(PROGRAM).tar.bz2 $(PROGRAM)

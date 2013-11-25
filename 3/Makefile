OBJ = main.o ThreeDShapes.o TwoDShapes.o 
CXXFLAGS = -Wall -pedantic-errors -g
BINARY = bin
all: $(BINARY)

$(BINARY): $(OBJ)
	g++ $(CXXFLAGS) $(OBJ) -o $(BINARY)

%.o : %.cpp
	g++ $(CXXFLAGS) -c $<

clean:
	rm $(BINARY) $(OBJ)

#ThreeDShapes.o
#

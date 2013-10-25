OBJ = main.o ThreeDShapes.o TwoDShapes.o shapes.o 
CXXFLAGS = -Wall -pedantic-errors -g
BINARY = bin
all: $(BINARY)

$(BINARY): $(OBJ)
	g++ $(CXXFLAGS) $(OBJ) -o $(BINARY)

%.o : %.c
	g++ $(CXXFLAGS) -c $<

clean:
	rm $(BINARY) $(OBJ)

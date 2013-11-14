OBJ = main.o Matrix.o
CXXFLAGS = -Wall -pedantic-errors -g
BINARY = bin
all: $(BINARY)	

$(BINARY): $(OBJ)
	g++ $(CXXFLAGS) $(OBJ) -o $(BINARY)

%.o : %.c
	g++ $(CXXFLAGS) -c $<

clean:
	rm $(BINARY) $(OBJ)

OBJ = main.o tree.o 
CPPFLAGS = -Wall -pedantic-errors -g
BINARY = bin
all: $(BINARY)

%.o : %.cpp
	g++ $(CPPFLAGS) -c $<

$(BINARY): $(OBJ)
	g++ $(CPPFLAGS) $(OBJ) -o $(BINARY)

clean:
	rm $(BINARY) $(OBJ)

OBJ = main.o 
CPPFLAGS = -Wall -pedantic-errors -g
BINARY = bin
all: $(BINARY)

$(BINARY): $(OBJ)
	g++ $(CPPFLAGS) $(OBJ) -o $(BINARY)

%.o : %.cpp
	g++ $(CPPFLAGS) -c $<

clean:
	rm $(BINARY) $(OBJ)

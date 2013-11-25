OBJ = main.o string.o 
CPPFLAGS = -Wall -pedantic-errors -g
BINARY = bin
all: $(BINARY)

$(BINARY): $(OBJ)
	g++ $(CPPFLAGS) $(OBJ) -o $(BINARY)

%.o : %.c
	g++ $(CPPFLAGS) -c $<

clean:
	rm $(BINARY) $(OBJ)

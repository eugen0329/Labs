OBJ = exception.o main.o products.o rwProducts.o string.o 
CPPFLAGS = -Wall -pedantic-errors -g
BINARY = bin
all: $(BINARY)

$(BINARY): $(OBJ)
	g++ $(CPPFLAGS) $(OBJ) -o $(BINARY)

%.o : %.cpp
	g++ $(CPPFLAGS) -c $<

clean:
	rm $(BINARY) $(OBJ)

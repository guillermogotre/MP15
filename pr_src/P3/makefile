
SRC = src
INC = include
OBJ = obj
BIN = bin
LIB = lib

CXX = g++
CPPFLAGS = -Wall -g -c -I$(INC)


all: $(BIN)/arteASCII $(BIN)/testarteASCII $(BIN)/testplano $(BIN)/testimagen

$(BIN)/testimagen: $(LIB)/libimagen.a $(OBJ)/testimagen.o
	g++ -o $(BIN)/testimagen $(OBJ)/testimagen.o -limagen -L$(LIB)

$(OBJ)/testimagen.o: $(SRC)/testimagen.cpp
	g++ -c -o $(OBJ)/testimagen.o $(SRC)/testimagen.cpp -I$(INC)

$(LIB)/libimagen.a: $(OBJ)/pgm.o $(OBJ)/imagen.o
	ar rvs $(LIB)/libimagen.a $(OBJ)/pgm.o $(OBJ)/imagen.o

$(OBJ)/pgm.o: $(SRC)/pgm.cpp $(INC)/pgm.h
	g++ -c $(SRC)/pgm.cpp -o $(OBJ)/pgm.o -I$(INC)

$(OBJ)/imagen.o: $(SRC)/imagen.cpp $(INC)/imagen.h
	g++ -c $(SRC)/imagen.cpp -o $(OBJ)/imagen.o -I$(INC)
rmimages:
	rm *.pgm
clean:
	rm -f $(OBJ)/*.o $(LIB)/*.a
mrproper: clean rmimages
	rm -f $(BIN)/*

	
# ************ documentación *******

documentacion:
	doxygen doc/doxys/Doxyfile

# ************ Limpieza ************

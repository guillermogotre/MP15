
SRC = src
INC = include
OBJ = obj
BIN = bin
LIB = lib

CXX = g++
CPPFLAGS = -Wall -g -c -I$(INC)


all: $(BIN)/arteASCII $(BIN)/testarteASCII $(BIN)/testplano $(BIN)/testimagen

$(BIN)/arteASCII: $(LIB)/libimagen.a $(OBJ)/arteASCII.o
	$(CXX) -o $(BIN)/arteASCII $(OBJ)/arteASCII.o -limagen -L$(LIB)

$(BIN)/testarteASCII: $(LIB)/libimagen.a $(OBJ)/testarteASCII.o
	$(CXX) -o $(BIN)/testarteASCII $(OBJ)/testarteASCII.o -limagen -L$(LIB)

$(BIN)/testplano: $(LIB)/libimagen.a $(OBJ)/testplano.o
	$(CXX) -o $(BIN)/testplano $(OBJ)/testplano.o -limagen -L$(LIB)

$(BIN)/testimagen: $(LIB)/libimagen.a $(OBJ)/testimagen.o 
	$(CXX) -o $(BIN)/testimagen $(OBJ)/testimagen.o -limagen -L$(LIB)

$(OBJ)/testimagen.o: $(SRC)/testimagen.cpp $(INC)/imagen.h
	$(CXX) $(CPPFLAGS) -o $(OBJ)/testimagen.o $(SRC)/testimagen.cpp 

$(OBJ)/testplano.o: $(SRC)/testplano.cpp $(INC)/imagen.h
	$(CXX) $(CPPFLAGS) -o $(OBJ)/testplano.o $(SRC)/testplano.cpp 

$(OBJ)/testarteASCII.o: $(SRC)/testarteASCII.cpp $(INC)/imagen.h
	$(CXX) $(CPPFLAGS) -o $(OBJ)/testarteASCII.o $(SRC)/testarteASCII.cpp 

$(OBJ)/arteASCII.o: $(SRC)/arteASCII.cpp $(INC)/imagen.h
	$(CXX) $(CPPFLAGS) -o $(OBJ)/arteASCII.o $(SRC)/arteASCII.cpp 

$(LIB)/libimagen.a: $(OBJ)/pgm.o $(OBJ)/imagen.o $(OBJ)/byte.o
	ar rvs $(LIB)/libimagen.a $(OBJ)/pgm.o $(OBJ)/imagen.o $(OBJ)/byte.o

$(OBJ)/pgm.o: $(SRC)/pgm.cpp $(INC)/pgm.h
	$(CXX) $(CPPFLAGS) $(SRC)/pgm.cpp -o $(OBJ)/pgm.o 

$(OBJ)/imagen.o: $(SRC)/imagen.cpp $(INC)/imagen.h $(INC)/pgm.h $(INC)/byte.h
	$(CXX) $(CPPFLAGS) $(SRC)/imagen.cpp -o $(OBJ)/imagen.o

$(OBJ)/byte.o: $(SRC)/byte.cpp
	$(CXX) $(CPPFLAGS) $(SRC)/byte.cpp -o $(OBJ)/byte.o

rmimages:
	rm -f *.pgm *.txt
clean:
	rm -f $(OBJ)/*.o $(LIB)/*.a
mrproper: clean rmimages
	rm -f $(BIN)/*

	
# ************ documentación *******

documentacion:
	doxygen doc/doxys/Doxyfile

# ************ Limpieza ************

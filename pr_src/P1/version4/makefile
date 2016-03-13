BIN = bin
OBJ = obj
SRC = src
INC = include
OPT = 
all: $(BIN)/central
$(BIN)/central: $(OBJ)/central.o lib/libformas.a
	g++ $(OBJ)/central.o -lformas -o $(BIN)/central -Llib
lib/libformas.a: $(OBJ)/punto.o $(OBJ)/circulo.o
	ar rvs lib/libformas.a $(OBJ)/punto.o $(OBJ)/circulo.o
$(OBJ)/central.o:	$(SRC)/central.cpp $(INC)/circulo.h $(INC)/punto.h
	g++ $(OPT) -c $(SRC)/central.cpp -o $(OBJ)/central.o -I$(INC)
$(OBJ)/punto.o: $(SRC)/punto.cpp $(INC)/punto.h
	g++ $(OPT) -c $(SRC)/punto.cpp -o $(OBJ)/punto.o -I$(INC)
$(OBJ)/circulo.o: $(SRC)/circulo.cpp $(INC)/circulo.h $(INC)/punto.h
	g++ $(OPT) -c $(SRC)/circulo.cpp -o $(OBJ)/circulo.o -I$(INC)
clean:
	@echo "Limpiando..."
	rm $(OBJ)/*.o lib/lib*.a
remove: clean
	@echo "Eliminando..."
	rm $(BIN)/central

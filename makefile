# Comandos do sistema operacional
# Linux: rm -rf 
# Windows: cmd //C del 
RM = rm -rf 

# Compilador
CC = g++

# Variaveis para os subdiretorios
SRC = ./src
INC = ./include
BIN = ./bin
OBJ = ./build
DOC = ./doc

# Define o nome do binario/executavel final
PROG = $(BIN)/exerc1

# Opcoes de compilacao
CPPFLAGS = -Wall -pedantic -std=c++11 -I$(INC)

# Lista dos arquivos objeto (.o) que formam o binario/executavel final
OBJS = $(OBJ)/data.o $(OBJ)/funcionario.o $(OBJ)/empresa.o $(OBJ)/cadastro.o $(OBJ)/main.o

all : $(OBJS)
	$(CC) $(LDFLAGS) -o $(PROG) $(OBJS)

# Alvo para a compilação com informações de debug
# Altera a flag CFLAGS, incluindo as opções -g -O0 e recompila todo o projeto
debug: CFLAGS += -g -O0 
debug: all

# Alvo para a construcao do objeto build/main.o
# Define os arquivos objeto dos quais main.o depende.
$(OBJ)/main.o : $(OBJ)/cadastro.o 
	$(CC) $(CPPFLAGS) -c $(SRC)/main.cpp -o $@

$(OBJ)/cadastro.o : $(INC)/cadastro.h $(OBJ)/empresa.o
	$(CC) $(CPPFLAGS) -c $(SRC)/cadastro.cpp -o $@

$(OBJ)/empresa.o : $(INC)/empresa.h $(OBJ)/funcionario.o
	$(CC) $(CPPFLAGS) -c $(SRC)/empresa.cpp -o $@

$(OBJ)/funcionario.o : $(INC)/funcionario.h $(OBJ)/data.o
	$(CC) $(CPPFLAGS) -c $(SRC)/funcionario.cpp -o $@

$(OBJ)/data.o : $(INC)/data.h
	$(CC) $(CPPFLAGS) -c $(SRC)/data.cpp -o $@

# Alvo (target) usado para limpar os arquivos temporarios (objeto)
# gerados durante a compilacao, assim como os arquivos binarios/executaveis.
clean:
	$(RM) $(PROG) $(OBJS)
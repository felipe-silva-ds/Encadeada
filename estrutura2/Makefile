# Nome do compilador
CXX = g++

# Flags do compilador
CXXFLAGS = -Wall -g

# Nome do executável
EXEC = Encadeada

# Arquivos fonte
SRC = Encadeada.cpp

# Regras de compilação
all: $(EXEC)

$(EXEC): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(EXEC) $(SRC)

# Regra para limpar arquivos de compilação
clean:
	rm -f $(EXEC)
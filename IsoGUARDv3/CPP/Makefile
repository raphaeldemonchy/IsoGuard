# Définir les variables de compilation
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra
LDFLAGS = -lvirt -lpthread

# Nom de l'exécutable
TARGET = create_vm

# Dossiers de sources
SRC_DIR = .
CORE_DIR = ./CORE
API_DIR = ./API

# Fichiers sources
SRCS = $(SRC_DIR)/main.cpp $(CORE_DIR)/core.cpp $(API_DIR)/Server.cpp

# Dossiers d'inclusion pour les en-têtes
INCLUDES = -I$(CORE_DIR) -I$(API_DIR)

# Bibliothèques à lier
LIBS = -lvirt -lpthread

# Règle par défaut : compilation de l'exécutable
all: $(TARGET)

# Règle pour lier l'exécutable
$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -o $(TARGET) $(SRCS) $(LDFLAGS)

# Nettoyer les fichiers de compilation
clean:
	rm -f $(TARGET) *.o

# Recompilation complète
rebuild: clean all

.PHONY: all clean rebuild

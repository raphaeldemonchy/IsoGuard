# Définir les variables de compilation
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra
LDFLAGS = -lvirt

# Nom de l'exécutable
TARGET = create_vm

# Fichiers sources
SRCS = main.cpp CORE/core.cpp

# Dossiers d'inclusion
INCLUDES =

# Dossiers de bibliothèques (ajuster si nécessaire)
LIBS =

# Règle par défaut : compilation de l'exécutable
all: $(TARGET)

# Règle pour lier l'exécutable
$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -o $(TARGET) $(SRCS) $(LDFLAGS)

# Nettoyer les fichiers de compilation
clean:
	rm -f $(TARGET)

# Recompilation complète
rebuild: clean all

.PHONY: all clean rebuild

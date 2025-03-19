# Variables
CXX = g++
CXXFLAGS = -std=c++17 -Wall -pthread -I./include   # Ajoutez -I./include pour spécifier où chercher les fichiers d'en-tête
LIBS = -lvirt

# Nom de l'exécutable
TARGET = vm_manager

# Fichiers sources
SRCS = VMmanager.cpp

# Fichiers objets
OBJS = $(SRCS:.cpp=.o)

# Règle par défaut
all: $(TARGET)

# Compilation de l'exécutable
$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $(TARGET) $(LIBS)

# Compilation des fichiers objets
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Nettoyage des fichiers objets et de l'exécutable
clean:
	rm -f $(OBJS) $(TARGET)

# Règle pour exécuter le programme
run: $(TARGET)
	./$(TARGET)

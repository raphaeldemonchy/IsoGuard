NAME = vm_backend

CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Werror -I$(INCDIR)
LDFLAGS = -lvirt -lxml2 -lpthread

SRCDIR = src
OBJDIR = build
INCDIR = include

SRC = $(shell find $(SRCDIR) -name '*.cpp') main.cpp
OBJ = $(SRC:%.cpp=$(OBJDIR)/%.o)

# Règle principale
all: $(NAME)

# Édition des liens
$(NAME): $(OBJ)
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

# Compilation des fichiers objets
$(OBJDIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Nettoyage des objets
clean:
	rm -rf $(OBJDIR)

# Nettoyage complet
fclean: clean
	rm -f $(NAME)

# Rebuild complet
re: fclean all

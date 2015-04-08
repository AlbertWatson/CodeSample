# ----------------------------------------------------------------
#  
# Makefile created by Yeaw Chu Lee
# Date : 14.01.2013
# 
# ----------------------------------------------------------------

#
# Environment variables
#

# Compiler and Linker
# CC = clang++ 
# LD = clang++
CC = nvcc
LD = nvcc

# Compiler and Linker flags
CCFLAGS = -c -O3 -std=c++11 
LDFLAGS = -lm -std=c++11 

# Paths
SRCDIR = .
OBJDIR = ./obj
BINDIR = ./bin

# Executable filename
BIN = main

# Messages
COMPILE_MESSAGE = "\033[32;1m\n --- Compiling \033[33m%s\033[32m...\n\033[m"
LINK_MESSAGE = "\033[32;1m\n --- Linking binary \033[33m%s\033[32m...\n\033[m"

#
# Bringing everything together
#

# Find source files
SOURCES:=$(wildcard $(SRCDIR)/*.cpp)

# Get object files
OBJECTS=$(addprefix $(OBJDIR)/,$(notdir $(SOURCES:.cpp=.o)))

# Executable filename
EXECUTABLE=$(BINDIR)/$(BIN)

# Top-level rule
all: $(OBJDIR) $(BINDIR) $(EXECUTABLE)
	@printf "\033[34;1m\n --- Compile and Link complete! --- \n\033[m"

$(BINDIR):
	@printf "\033[32;1m\nMaking \033[33m$(BINDIR)/ \033[32mpath for binaries...\n\033[m"
	mkdir $(BINDIR)

$(OBJDIR):
	@printf "\033[32;1m\nMaking \033[33m$(OBJDIR)/ \033[32mpath for objects...\n\033[m"
	mkdir $(OBJDIR)

# Rule to link object files        
$(EXECUTABLE): $(OBJECTS)
	@printf $(LINK_MESSAGE) $(BIN)
	$(LD) $(LDFLAGS) -o $@ $^

# Rule to compile source files
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	@printf $(COMPILE_MESSAGE) "$<"
	$(CC) $(CCFLAGS) -o $@ $<

# Rule for cleanup
clean_obj:
	@printf "\033[34;1m\nCleaning \033[31;1monly\033[34;1m objects ... (saving binaries)\n\033[m"
	-rm -rf $(OBJECTS)

# Rule to remove all object and binary files
clean:
	@printf "\033[34;1m\nCleaning up...\n\033[m"
	-rm -rf $(EXECUTABLE) $(OBJECTS) 


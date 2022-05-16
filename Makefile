CC     = gcc
CFLAGS = -Wall -Werror --pedantic-errors -g
MKDIR  = mkdir -p
RM     = rm -rf

SRC = src
INC = $(SRC)/include
OBJ = obj
BIN = bin

MODULES = logger util wc_core

all: wc_single wc_multi

wc_single: $(OBJ)/wc_single.o $(patsubst %, $(OBJ)/%.o, $(MODULES)) | $(BIN)
	$(CC) $(CFLAGS) -I$(INC) $^ -o $(BIN)/$@

wc_multi: $(OBJ)/wc_multi.o $(patsubst %, $(OBJ)/%.o, $(MODULES)) | $(BIN)
	$(CC) $(CFLAGS) -I$(INC) $^ -o $(BIN)/$@

$(OBJ)/%.o: $(SRC)/%.c | $(OBJ)
	$(CC) $(CFLAGS) -I$(INC) -c $< -o $@

$(OBJ)/%.o: $(SRC)/%.c $(INC)/%.h | $(OBJ)
	$(CC) $(CFLAGS) -I$(INC) -c $< -o $@

$(OBJ) $(BIN):
	$(MKDIR) $@

clean:
	$(RM) $(OBJ) $(BIN)

CC = gcc

FLAGS = -Wall -W
GL = -lglut -lGLU -lGL
LM = -lm
INCLUDES = -Iinc
SRC = src
OBJ = obj

SRCS = $(wildcard $(SRC)/*.c)
OBJS= $(patsubst $(SRC)/%.c, $(OBJ)/%.o, $(SRCS))

BINDIR = bin
BIN = $(BINDIR)/main


all: $(BIN)

$(BIN): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $@ $(GL)

$(OBJ)/%.o: $(SRC)/%.c
	$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@ $(GL)

clean:
	rm -rf $(BINDIR)/* $(OBJ)/*

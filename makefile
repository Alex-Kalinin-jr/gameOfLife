CD=gcc
FLAGS=-Wall -Werror -Wextra
ROAD =.
FNAME=game

all: game static
	$(CD) $(FLAGS) game.o -L. -lmatr -o $(ROAD)/$(FNAME)

game: game.c
	$(CD) -c $(FLAGS) game.c -o game.o

matr: matr.c
	$(CD) -c $(FLAGS) matr.c -o matr.o

static: matr
	ar -rcs libmatr.a matr.o


run:
	$(ROAD)/$(FNAME)
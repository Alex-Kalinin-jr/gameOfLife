CD=gcc
FLAGS=-Wall -Werror -Wextra
ROAD =.
FNAME=game

all: game static static2
	$(CD) $(FLAGS) game.o -L. -lmatr -linput -o $(ROAD)/$(FNAME)

game: game.c
	$(CD) -c $(FLAGS) game.c -o game.o

matr: matr.c
	$(CD) -c $(FLAGS) matr.c -o matr.o

static: matr
	ar -rcs libmatr.a matr.o



inputSettings: inp_settings.c
	$(CD) -c $(FLAGS) inp_settings.c -o inp_settings.o

static2: inputSettings
	ar -rcs libinput.a inp_settings.o


clean:
	rm -rf *.o *.a

run:
	$(ROAD)/$(FNAME)
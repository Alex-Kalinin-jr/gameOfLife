CD = gcc
FLAGS =-Wall -Werror -Wextra
ROAD =.
FNAME=game

all:
	$(CD) $(FLAGS) game.c -o $(ROAD)/$(FNAME)

run:
	$(ROAD)/$(FNAME)
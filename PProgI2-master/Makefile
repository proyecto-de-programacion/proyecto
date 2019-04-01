all: JuegoOca

JuegoOca: command.o game.o die.o set.o game_loop.o graphic_engine.o screen.o space.o game_reader.o object.o player.o inventory.o link.o 
	gcc command.o game.o die.o set.o game_loop.o graphic_engine.o screen.o space.o game_reader.o object.o player.o inventory.o link.o -g -o JuegoOca

command.o: command.c command.h
	gcc -Wall -ansi -pedantic -c -g command.c

game.o: game.c game.h
	gcc -Wall -ansi -pedantic -c -g game.c
	
die.o: die.c die.h
	gcc -Wall -ansi -pedantic -c -g die.c

game_loop.o: game_loop.c
	gcc -Wall -ansi -pedantic -c -g game_loop.c

graphic_engine.o: graphic_engine.c graphic_engine.h
	gcc -Wall -ansi -pedantic -c -g graphic_engine.c

screen.o: screen.c screen.h
	gcc -Wall -ansi -pedantic -c -g screen.c

space.o: space.c space.h types.h
	gcc -Wall -ansi -pedantic -c -g space.c

game_reader.o: game_reader.c game_reader.h
	gcc -Wall -ansi -pedantic -c -g game_reader.c

object.o: object.c object.h
	gcc -Wall -ansi -pedantic -c -g object.c

player.o: player.c player.h
	gcc -Wall -ansi -pedantic -c -g player.c

set.o: set.c set.h
	gcc -Wall -ansi -pedantic -c -g set.c

inventory.o: inventory.c inventory.h
	gcc -Wall -ansi -pedantic -c -g inventory.c

link.o: link.c link.h
	gcc -Wall -ansi -pedantic -c -g link.c

clean:
	rm -f *o JuegoOca

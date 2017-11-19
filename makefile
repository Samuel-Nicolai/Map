##############MakeFile-MAP##############
all: principal

principal: map.o main.o
	gcc -o principal main.o map.o
	rm -rf *.o

map.o: map.c
	gcc -Wall -c map.c

main.o: main.c
	gcc -Wall -c main.c

clean:
	rm -rf *.o

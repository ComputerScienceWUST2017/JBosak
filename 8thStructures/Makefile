CFLAGS = -g -Wall -Wextra -o
OBJECTS = main.o func.o
NAME = 8assignment

build: $(OBJECTS)
	gcc $(CFLAGS) $(NAME) $(OBJECTS)
	rm -f *.o

main.o: main.c
	gcc -c $(CFLAGS) main.o main.c

func.o: func.c
	gcc -c $(CFLAGS) func.o func.c

clean:
	rm -f *.o

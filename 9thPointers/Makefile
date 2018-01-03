CFLAGS = -g -Wall -Wextra -o
OBJECTS = main.o sortTools.o personalData.o
NAME = 9assignment
CC = gcc

build: $(OBJECTS)
	$(CC) $(CFLAGS) $(NAME) $(OBJECTS)
	rm -f *.o


main.o: main.c
	$(CC) -c $(CFLAGS) main.o main.c

sortTools.o: sortTools.c
	$(CC) -c $(CFLAGS) sortTools.o sortTools.c

personalData.o: personalData.c
	$(CC) -c $(CFLAGS) personalData.o personalData.c

clean:
	rm -f *.o

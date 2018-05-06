CFLAGS = -Wall -Wextra -o
OBJECTS = main.o  Tree.o Node.o Content.o BaseStructure.o HashTable.o BTree.o
NAME = 8assignment

build: $(OBJECTS)
	g++ $(CFLAGS) $(NAME) $(OBJECTS)
	rm -f *.o


main.o: main.cpp
	g++ -c $(CFLAGS) main.o main.cpp

Tree.o: btc/Tree.cpp
	g++ -c $(CFLAGS) Tree.o btc/Tree.cpp

Node.o: btc/Node.cpp
	g++ -c $(CFLAGS) Node.o btc/Node.cpp

Content.o: btc/Content.cpp
	g++ -c $(CFLAGS) Content.o btc/Content.cpp

BaseStructure.o: BaseStructure.cpp
	g++ -c $(CFLAGS) BaseStructure.o BaseStructure.cpp

HashTable.o: HashTable.cpp
	g++ -c $(CFLAGS) HashTable.o HashTable.cpp

BTree.o: BTree.cpp
	g++ -c $(CFLAGS) BTree.o BTree.cpp

clean:
	rm *.o

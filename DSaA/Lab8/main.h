#ifndef MAIN_H
#define MAIN_H

#include "HashTable.h"
#include "BaseStructure.h"
#include "btc/Tree.h"
#include <string.h>
#include <algorithm>
#include <sstream>
#include "BTree.h"


#define delim "1!@'#:..;[>!\" $%&()*+,-./;<=?@[]^_`{|}~;~-\\)[]_]|-.$/(0),.?\?+-*=/*^&*(""/-""\")23.,?’‘’‘”45678/"
using namespace std;

BaseStructure* createBS(int argc, string argv);
string separateToWord(char *p);


#endif

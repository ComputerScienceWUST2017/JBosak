#ifndef BTREE_H
#define BTREE_H


#include <map>
#include "btc/Content.h"
#include "BaseStructure.h"
#include <iostream>
using namespace std;

class BTree: public BaseStructure{
public:
  Content frequent[10];
  std::map<string, long> map;
  bool insertWord(Content content);
  void findFrequent(int amount);
  void printFrequent(int amount);


};


#endif

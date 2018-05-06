#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
#include <unordered_map>
#include "btc/Content.h"
#include "BaseStructure.h"


class HashTable:public BaseStructure{
public:
  std::unordered_map<string, long> map;
  Content frequent[10];
  bool insertWord(Content content);
  void findFrequent(int amount);
  void printFrequent(int amount);
private:
};

#endif

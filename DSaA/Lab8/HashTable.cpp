#include "HashTable.h"


  bool HashTable::insertWord(Content content){
    ++map[content.word];
    return true;
  }
  void HashTable::findFrequent(int amount){
    for (std::pair<string, long> const &x: map) {
      if(x.second > frequent[amount - 1].counter){
        int i;
        for(i = amount - 1; i>0 && frequent[i-1].counter < x.second;i--){
          frequent[i] = frequent[i-1];
        }
        frequent[i].counter= x.second;
        frequent[i].word = x.first;
      }

  }
  printFrequent(amount);
  }
  void HashTable::printFrequent(int amount){
    for (int i = 0; i < amount; ++i) {
      cout<<frequent[i].counter <<"("<<frequent[i].counter<<")\n";
    }
  }

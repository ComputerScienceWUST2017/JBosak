#ifndef TREE_H
#define TREE_H

#include "Node.h"
#include "../BaseStructure.h"

class Tree:public BaseStructure{
private:
  Content frequent[10];
  Node *root;
  void showFrequent(int amount);
  void findFrequent(Node * child,int amount);
  Node * findWord(string word);
  void showTree(Node * node,int height);
  Node *findNode(Node *node,string word);
public:
  Tree();
   void findFrequent(int amount);
   void show();
   bool insertWord(Content content);
   void printFrequent(int amount);
};

#endif

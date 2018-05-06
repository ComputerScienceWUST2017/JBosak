#ifndef NODE_H
#define NODE_H

#include <iostream>
#include "Content.h"

class Node{
public:
  Content content;
  Node *parent;
  Node *left;
  Node *right;
  Node(Content content, Node *parent, Node *left, Node *right);
  Node();

  void showNode(bool newLine);

};


#endif

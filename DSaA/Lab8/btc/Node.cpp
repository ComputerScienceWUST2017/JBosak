 #include "Node.h"

void Node::showNode(bool newLine){
  std::cout<<content.counter<<"(";
  std::cout<<content.word<<")";
  if(newLine){
    std::cout<<"\n";
  }
}

Node::Node(Content content, Node *parent, Node *left, Node *right){
  this->content = content;
  this->parent = parent;
  this->left = left;
  this->right = right;
};
Node::Node(){};

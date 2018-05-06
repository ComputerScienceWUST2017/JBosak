#include "Tree.h"

Tree::Tree(){
  this->root = NULL;
}

  void Tree::printFrequent(int amount){
    for (int i = 0; i < amount; ++i) {
      cout<<frequent[i].counter <<"("<<frequent[i].counter<<")\n";
    }
  }

  void Tree::findFrequent(Node * child,int amount){
  	if(child != NULL){
      if(child->content.counter > frequent[amount-1].counter){
        int i;
        for(i = amount - 1;i > 0 && frequent[i-1].counter < child->content.counter;i--){
          frequent[i] = frequent[i-1];
        }
        frequent[i].counter = child->content.counter;
        frequent[i].word = child->content.word;
      }
  		findFrequent(child->left,amount);
  		findFrequent(child->right,amount);
  	}
  }

  Node * Tree::findWord(string word){
    Node *node = findNode(this->root,word);
    if(node == NULL){
      return NULL;
    }else
    if(node->content.word == word){
      return node;

    }
    return NULL;
  }

  Node *Tree::findNode(Node *node,string word){
    if(node==NULL || node->content.word == word){
      return node;
    }
    if(node->content.word< word)
     node = findNode(node->right,word);
    else
     node = findNode(node->left,word);
    if(node==NULL || node->content.word == word)
     return node;

    return NULL;
  }

  void Tree::showTree(Node * node,int height){
    if(node == NULL){
      return;
    }
    height++;
    if(node->left != NULL){
      cout<<"\n";
      for(int i = 0; i<height;i++){
        cout<<" ";
      }
      node->left->showNode(false);
    }
    showTree(node->left,height);
    if(node->right != NULL){
      cout<<"\n";
      for(int i = 0; i<height;i++){
				cout<<" ";
      }
      node->right->showNode(false);
    }
    showTree(node->right,height);
  }

 void Tree::findFrequent(int amount){
       findFrequent(this->root,amount);
       printFrequent(amount);
 }

  void Tree::show(){
    if(this->root == NULL){
      cout<<"\n";
      return;
    }
    int height = 0;
    this->root->showNode(true);
    showTree(this->root,height);
    cout<<"\n";
  }

  bool Tree::insertWord(Content content){
    Node * newNode = findWord(content.word);
    if(newNode != NULL){
      newNode->content.counter++;
      return true;
    }
    Node *parent = NULL;
    newNode = new Node(content,parent,NULL,NULL);

    if(this->root!= NULL){
      Node *x = this->root;
      while(x != NULL){
        parent = x;
        if(x->content.word < content.word)
          x = x->right;
        else
          x = x->left;
      }
      if(x == NULL){
        newNode->parent = parent;
        if(parent->content.word<content.word)
          parent->right = newNode;
        else
          parent->left = newNode;
        return true;
      }
    }else{
      newNode->parent = NULL;
      this->root = newNode;
      return true;
    }

    return false;
  }

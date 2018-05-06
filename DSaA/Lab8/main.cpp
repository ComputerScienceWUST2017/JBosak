#include "main.h"

int
main(int argc, char *argv[]){
  string str = argv[1];
  BaseStructure *bs = createBS(argc,str);

  string line;
  char *p;
  while(getline(cin,line)){
    p = strdup(line.c_str());
    p = strtok(p,delim);
    while (p) {
      bs[0].insertWord(separateToWord(p));
      p = strtok(NULL, delim);
    }
  }
  //tree[0].show();
 bs[0].findFrequent(5);

  return 0;
}
string separateToWord(char *p){
  string word;
  stringstream ss;
  ss<<p;
  ss>>word;
  transform(word.begin(), word.end(),word.begin(), ::tolower);
  return word;
}

BaseStructure* createBS(int argc, string argv){
  BaseStructure* structure = NULL;

  if(argc >1){
    transform(argv.begin(), argv.end(),argv.begin(), ::toupper);
    if(argv== "BST"){
      cout<<"BST"<<"\n\n";
      structure= new Tree[1];
    }
    else if(argv == "HT"){
      cout<<"HashTable"<<"\n\n";
      structure= new HashTable[1];
    }
    else if(argv == "BBST"){
      cout<<"Balanced BST"<<"\n\n";
      structure= new BTree[1];
    }
  } else if (argc == 1){  //default
    structure = new Tree[1];
  }
  return structure;

}

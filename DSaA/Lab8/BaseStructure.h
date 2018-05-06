#ifndef BASESTRUCTURE_H
#define BASESTRUCTURE_H
class BaseStructure{
public:
   virtual bool insertWord(Content content) = 0;
   virtual void findFrequent(int amount) = 0;
   virtual void printFrequent(int amount) = 0;
};
#endif

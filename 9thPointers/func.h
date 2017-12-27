#ifndef FUNC_H_INCLUDED
#define FUNC_H_INCLUDED
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

struct personalData{
  char name[20];
  char *remarks;
  float weight;
  int age;
} ;

int readPtrData(struct personalData * ar[], int len);
struct personalData * getPersonPtr(char * line);
int semicolonCounter(char *line);

void weightSort(struct personalData *data[], int len);
int cmpWeight(const void *a, const void *b);

void remarkstSort(struct personalData * data[], int len);
int cmpRemarks(const void *a, const void *b);

void printAllData(struct personalData * data[],int len);
void printData (struct personalData data[], int len);
void printPtrData (struct personalData * data[], int len);


#endif

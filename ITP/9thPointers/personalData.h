#ifndef PERSONALDATA_H_INCLUDED
#define PERSONALDATA_H_INCLUDED
 #include <stdio.h>
 #include <string.h>
 #include <stdlib.h>
 #include <ctype.h>

typedef struct personalData{
  char name[20];
  char *remarks;
  float weight;
  int age;
}personalData;

int readPtrData(struct personalData *ar[], int len);
personalData * getPersonPtr(char *line);
int semicolonCounter(char *line);

#endif

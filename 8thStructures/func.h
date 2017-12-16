#ifndef FUNC_H_INCLUDED
#define FUNC_H_INCLUDED
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "func.h"

typedef struct {
  char name[20];
  char *remarks;
  int age;
  float weight;
} personalData;

personalData getPersonDesc(char * line);
int readData(personalData *ar, int len);
int getOldestPersen(personalData data[], int len);
int getSlimmestPersen(personalData data[], int len);
void printInfo(personalData ar[], int idx, char *msgOk, char * msgbad);


#endif

#ifndef FUNC_H_INCLUDED
#define FUNC_H_INCLUDED
#include "personalData.h"
//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>



void weightSort(struct personalData *data[], int len);
int cmpWeight(const void *a, const void *b);

void remarkstSort(struct personalData *data[], int len);
int cmpRemarks(const void *a, const void *b);

void printAllData(struct personalData *data[],int len);
void printData (struct personalData data[], int len);
void printPtrData (struct personalData *data[], int len);


#endif

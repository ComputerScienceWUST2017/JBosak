#include "sortTools.h"



void weightSort(struct personalData *data[], int len){
  qsort(data,len,sizeof(*data),cmpWeight);
}
int cmpWeight (const void *a, const void *b) {
  struct personalData *data0 = *((struct personalData **)a);
  struct personalData *data = *((struct personalData **)b);

  return (data0->weight - data->weight);
}

void remarkstSort(struct personalData *data[], int len){
  qsort(data,len,sizeof(*data),cmpRemarks);
}

int cmpRemarks (const void *a, const void *b) {
  struct personalData *data0 = *((struct personalData **)a);
  struct personalData *data = *((struct personalData **)b);

  return (strcmp(data0->remarks, data->remarks));
}

void printAllData(struct personalData *data[], int len){
  int i;
  for(i = 0;i < len; i++){
    printPtrData(&data[i], len);
  }
}

void printData (struct personalData data[], int len){
  if(len < 0){
    puts("It is not working");
  }else{
    int index = 0;
  //  puts("It is working");
    printf("name: %s\tage: %d\tweight: %.2f\tremark:%s\n"
      ,data[index].name, data[index].age, data[index].weight, data[index].remarks);
  }
}
void printPtrData(struct personalData *data[], int len){
  if(len < 0){
    puts("It is not working");
  }else{
    int index = 0;
  //  puts("It is working");
    printf("name: %s\tage: %d\tweight: %.2f\tremark:%s\n"
      ,data[index]->name, data[index]->age, data[index]->weight, data[index]->remarks);
  }
}

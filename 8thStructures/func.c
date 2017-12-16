
#include "func.h"

int getOldestPersen(personalData data[], int len){
  int index = 0;
  int i;
  for(i = 0;i<len;i++){
    if(data[i].age > data[index].age){
      index = i;
    }
  }
  return index;
}
int getSlimmestPersen(personalData data[], int len){
  int index = 0;
  int i;
  for(i = 0;i<len;i++){
    if(data[i].weight < data[index].weight){
      index = i;
    }
  }
  return index;
}

int readData(personalData ar[], int len){
  char line[50];
  int i = 0;

  while(fgets(line, 100, stdin) != NULL){
    char *ptr = line;
    ar[i++] = getPersonDesc(ptr);
  }
  return i;
}

personalData getPersonDesc(char * line){
  char *data;
  char name[20];
  personalData x;
  data = strtok (line,";");
  snprintf(name, 20, "%s", data);
  strcpy(x.name , name);
  data = strtok(NULL, ";");
  x.age = atoi(data);
  data = strtok(NULL, ";");
  x.weight = atof(data);
  data = strtok (NULL,";");
  x.remarks = malloc(50);
  snprintf(x.remarks, 50, "%s", data);
  return x;
}

void printInfo(personalData ar[], int idx, char *msgOk, char * msgbad){
  printf("%s\n",msgOk );
  printf("name: %s\tage: %d\tweight: %f\tremark:%s\n"
  ,ar[idx].name, ar[idx].age, ar[idx].weight, ar[idx].remarks);
}


#include "func.h"

int getOldestPersen(personalData data[], int len){
  int index = 0;
  int i;
  if(len == 0){
    return -1;
  }
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
  if(len == 0){
    return -1;
  }
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
    if(i<len-1){
      char *ptr = line;
      ar[i++] = getPersonDesc(ptr);
    }
  }
  personalData x;
  x.remarks = '\0';
  ar[i] =x ;
  return i;
}

personalData getPersonDesc(char * line){
  char *data;
  personalData x;
  data = strtok (line,";");
  snprintf(x.name, 20, "%s", data);
  data = strtok(NULL, ";");
  x.age = atoi(data);
  data = strtok(NULL, ";");
  x.weight = atof(data);
  data = strtok (NULL,";");
  x.remarks = malloc(sizeof(char)*50);
  snprintf(x.remarks, 50, "%s", data);
  return x;
}

void printInfo(personalData ar[], int idx, char *msgOk, char * msgbad){
  if(idx<0){
    printf("\n%s\n",msgbad );
  }else{
    printf("\n%s\n",msgOk );
    printf("name: %s\tage: %d\tweight: %f\tremark:%s\n"
            ,ar[idx].name, ar[idx].age, ar[idx].weight, ar[idx].remarks);
  }
}


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
    char *ptr = line;
    if((i<len-1) && (semicolonCounter(ptr) == 4)){
      ar[i++] = getPersonDesc(ptr);
      if(ar[i-1].remarks == '\0'){
        i--;
      }
    }
  }
  personalData x;
  x.remarks = '\0';
  ar[i] =x ;
  return i;
}

int semicolonCounter(char *line){
  int counter = 0;

  unsigned int j;
  for(j = 0;j < strlen(line)-1; j++){
    if(line[j] == ';'){
      counter++;
    }
  }
  return counter;
}

personalData getPersonDesc(char * line){
  char *data;
  personalData x;

  data = strtok (line,";");//name
  snprintf(x.name, 20, "%s", data);

  data = strtok(NULL, ";");//age
  if(atoi(data) == 0){
    x.remarks = '\0';
    return x;
  }
  x.age = atoi(data);

  data = strtok(NULL, ";");//weight
  if(atof(data) == 0){
    x.remarks = '\0';
    return x;
  }
  x.weight = atof(data);

  data = strtok (NULL,";");//remark
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

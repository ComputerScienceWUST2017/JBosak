#include "func.h"

int getOldestPersen(personalData data[]){
  int index = 0;
  int i = 0;
   while(data[i].remarks != '\0'){
    if(data[i].age > data[index].age){
      index = i;
    }
      i++;

  }
  if(data[0].remarks == '\0'){//checking if there is any data
    index = -1;
  }
  return index;
}
int getSlimmestPersen(personalData data[], int len){
  int indexOfSlimmestPerson = 0;
  if(len == 0){
    return -1;
  }
  int i;
  for(i = 0;i < len;i++){
    if(data[i].weight < data[indexOfSlimmestPerson].weight){
      indexOfSlimmestPerson = i;
    }
  }
  return indexOfSlimmestPerson;
}

int readData(personalData ar[], int len){
  char line[100];
  int i = 0;

  while(fgets(line, 100, stdin) != NULL){
    if((i<len-1) && (semicolonCounter((char*)line) == 4)){
      ar[i++] = getPersonDesc((char*)line);
      if(ar[i-1].remarks == '\0'){
        i--;
      }
    }
  }
  personalData lastPerson;//according to "The last structure should have remarks set to 0;"
  lastPerson.remarks = '\0';
  ar[i] = lastPerson;
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
  unsigned int i;
  for(i = 0; i< strlen(data); i++){
    if(!(isdigit(data[i]) || data[i] == '.')){
      x.remarks = '\0';
      return x;
    }
  }
  x.weight = atof(data);

  data = strtok (NULL,";");//remarks
  x.remarks = malloc(sizeof(char)*(strlen(data)+1));
  snprintf(x.remarks, 50, "%s", data);

  return x;
}


void printInfo(personalData ar[], int idx, char *msgOk, char * msgbad){
  if(idx < 0){
    printf("\n%s\n",msgbad );
  }else{
    printf("\n%s\n",msgOk );
    printf("name: %s\tage: %d\tweight: %.2f\tremark:%s\n"
            ,ar[idx].name, ar[idx].age, ar[idx].weight, ar[idx].remarks);
  }
}

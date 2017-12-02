#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>


typedef enum {
  EQUALS, ADD, SUBSTRACT, NUMBER, WORD, PREV, MULTIPLY, EXIT
} TokenType;

TokenType getNextToken(char tk[], int len);
float followToken(float a, float b,char *en);
char * lineCalc(void);
static float prevResult;

int
main(){
  prevResult = 0;
  while(1){

    char *solution = lineCalc();
    printf("\n\n\nSolution: %s\n",solution );
}
  return 0;
}

float followToken(float a, float b ,char *en){
  switch (getNextToken(en, 20)) {
    case ADD:
    a = a + b;
    break;

    case SUBSTRACT:
    a = a - b;
    break;

    case EQUALS:
    break;

    case MULTIPLY:
    a = a * b;
    break;
  }
  return a;
}

TokenType getNextToken(char tk[], int len){

  if(isdigit(tk[0]) != 0){
    return NUMBER;
  }

  if (!(stricmp("MULTIPLY", tk)) || tk[0] == '*') {
    return MULTIPLY;

  } else if (!(stricmp("ADD", tk)) || tk[0] == '+' || !(stricmp("PLUS", tk))) {
    return ADD;

  } else if (!(stricmp("EQUALS\n", tk)) || tk[0] == '=') {
    return EQUALS;

  } else if (!(stricmp("substract", tk)) || tk[0] == '-' || !(stricmp("MINUS", tk))) {
    return SUBSTRACT;

  } else if (!stricmp("PREV", tk) || !(stricmp("“PREV_RESULT", tk))) {
    return PREV;
  } else if(stricmp("EXIT\n", tk) == 0){
    exit(0);
    return WORD;
  }

  return WORD;
}

char * lineCalc(void){
  static char result2Return[20];
  float value;
  float a = 0;
  float b = 0;
  char *token1 = (char*) malloc  (sizeof(char)*10);
  char *token2 = (char*) malloc  (sizeof(char)*10);
  char line[60];
  char *schowek;
  fgets(line, 100, stdin);
  char separator[] = " ,";
  for(schowek = strtok(line, separator); schowek; schowek = strtok(NULL, separator)){
    switch (getNextToken(schowek, sizeof(schowek)/sizeof(TokenType))) {

      case NUMBER:
      if(a == 0){
        a = atof(schowek);
      } else b = atof(schowek);
      break;
      case ADD: case SUBSTRACT : case MULTIPLY:
      token1 = schowek;
      break;

      case EQUALS:
      token2 = schowek;
      break;
      case PREV:
      if(a == 0){
        a = prevResult;
      } else b = prevResult;
      break;
    }
    if(a != 0 && b != 0){
      a = followToken(a,b, token1);
      b = 0;
    }
  }

    value = followToken(a,b, token2);
    prevResult = value;
    sprintf(result2Return, "%4.2f", value);
    return result2Return;

}

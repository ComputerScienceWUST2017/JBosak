#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>


typedef enum {
  EQUALS, ADD, SUBSTRACT, NUMBER, WORD, PREV, MULTIPLY, EXIT, DIVIDE
} TokenType;

TokenType getNextToken(char tk[], int len);
float followToken(float a, float b,TokenType token);
char * lineCalc(void);
static float prevResult;

int
main(){
  prevResult = 0;
  char *solution;
  while(solution != EOF){
     char* solution = lineCalc();
     printf("Solution: %s\n\n",solution );
}
  return 0;
}


char * lineCalc(void){
  float number[] = {0, 0};
  TokenType operation;
  TokenType sequel;
  char line[100];
  char linia[100];
  char *tmp;
  if(fgets(line, 100, stdin) == NULL){
    exit(0);
    return EOF;
  } else {
    memcpy(linia, line, strlen(line) + 1);
  }

  char separator[] = " ,";
  for(tmp = strtok(line, separator); tmp; tmp = strtok(NULL, separator)){
    TokenType res;
    switch (res = getNextToken(tmp, sizeof(tmp))) {

      case NUMBER:
        if(number[0] == 0){
          number[0] = atof(tmp);
        } else number[1] = atof(tmp);
        break;
      case ADD: case SUBSTRACT: case MULTIPLY: case DIVIDE:
        operation = res;
        break;

      case EQUALS:
        sequel = res;
        break;

      case PREV:
        if(number[0] == 0){
          number[0] = prevResult;
        } else number[1] = prevResult;
        break;
    }
    if(number[0] != 0 && number[1] != 0){
      number[0] = followToken(number[0], number[1], operation);
      number[1] = 0;
    }
  }

    number[0] = followToken(number[0],number[1], sequel);
    prevResult = number[0];

    static char result2Return[20];
    sprintf(result2Return, "%4.2f", number[0]);
    printf("%s",linia );
    return result2Return;

}

TokenType getNextToken(char tk[], int len){


  if(isdigit(tk[0]) != 0){
    return NUMBER;
  }

  if (!(stricmp("MULTIPLY", tk)) || tk[0] == '*') {
    return MULTIPLY;

  } else if (!(stricmp("DIVIDE", tk)) || tk[0] == '/' || !(stricmp("OVER", tk)) ) {
    return DIVIDE;

  } else if (!(stricmp("ADD", tk)) || tk[0] == '+' || !(stricmp("PLUS", tk))) {
    return ADD;

  } else if (!(stricmp("EQUALS\n", tk)) || tk[0] == '=') {
    return EQUALS;

  } else if (!(stricmp("SUBSTRACT", tk)) || tk[0] == '-' || !(stricmp("MINUS", tk))) {
    return SUBSTRACT;

  } else if (!stricmp("PREV", tk) || !(stricmp("“PREV_RESULT", tk))) {
    return PREV;
  } else if(stricmp("EXIT\n", tk) == 0){
    exit(0);
    return WORD;
  }

  return WORD;
}


float followToken(float a, float b ,TokenType token){
  switch (token) {
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

    case DIVIDE:
    a = a / b;
    break;
  }
  return a;
}

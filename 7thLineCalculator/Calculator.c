#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>


typedef enum {
  EQUALS, ADD, SUBSTRACT, NUMBER, WORD, PREV, MULTIPLY
} TokenType;

TokenType getNextToken(char tk[], int len);
int followToken(int a, int b,char *en);

int
main(){
  int a = 0;
  int b = 0;
  char *token1 = (char*) malloc  (sizeof(char)*10);
  char *token2 = (char*) malloc  (sizeof(char)*10);
  char line[60];
  char operation;
  char *schowek;
  char en[] = {0,0};
  fgets(line, 100, stdin);
  char delim[] = " ,";
  for(schowek = strtok(line, delim); schowek; schowek = strtok(NULL, delim)){

    switch (getNextToken(schowek, sizeof(schowek)/sizeof(TokenType))) {

      case NUMBER:
      if(a == 0){
        a = atoi(schowek);
      } else b = atoi(schowek);
      break;

      case ADD: case SUBSTRACT : case MULTIPLY:
      token1 = schowek;
      break;

      case EQUALS:
      token2 = schowek;
      break;
    }
  }
  a = followToken(a,b, token1);
  a = followToken(a,b, token2);

  return 0;
}

int followToken(int a, int b,char *en){
  switch (getNextToken(en, 20)) {
    case ADD:
    a = a + b;
    break;

    case SUBSTRACT:
    a = a - b;
    break;

    case EQUALS:
    printf("WYNIK:%d\n", a);
    break;

    case MULTIPLY:
    a = a * b;
    break;
  }
  return a;
}

TokenType getNextToken(char tk[], int len){
  printf("DIG%sX\n",tk );

  if(isdigit(tk[0]) != 0){
    printf("RETURNUJE number" );
    return NUMBER;

  }else if (!(memcmp("MULTIPLY", tk, 8)) || tk[0] == '*') {
    printf("RETURNUJE multi" );
    return MULTIPLY;

  } else if (!(memcmp("add", tk, 3)) || tk[0] == '+') {
    printf("RETURNUJE add" );
    return ADD;

  } else if (!(memcmp("equals", tk, 5)) || tk[0] == '=') {
    printf("EQUAL!" );
    return EQUALS;

  } else if (!(memcmp("substract", tk, 9)) || tk[0] == '-') {
    printf("RETURNUJE subst" );
    return SUBSTRACT;

  } else if (!stricmp("PREV", tk) != 0) {
    printf("RETURNUJE prev" );
    return PREV;
  }

  printf("RETURNUJE WORDA" );
  return WORD;
}

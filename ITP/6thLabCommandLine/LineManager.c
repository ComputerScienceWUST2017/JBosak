#include <stdio.h>
#include <ctype.h>
#include <string.h>

void change2LowerCase();
void change2UpperCase();
void switchCase();
void makeNames();


int
main(int argc, char *argv[]){
  if(argc >= 2){
    switch (argv[1][1]){
      case 'l' : case 'L' :
        change2LowerCase();
        break;
      case 'u' : case 'U' : default :
        change2UpperCase();
        break;
      case 'c' : case 'C' :
        switchCase();
        break;
      case 'n' : case 'N' :
       makeNames();
       break;
   }

  }
  return 0;
}

void change2LowerCase(){
  char c;
  do{
    c = getc(stdin);
    if(feof(stdin) ==0){

      if(isupper(c)){
        c = tolower(c);
      }
      printf("%c", c );

    }
  }  while(c != EOF);
}

void change2UpperCase(){
  char c;
  do{
    c = getc(stdin);
    if(feof(stdin) ==0){

      if(!isupper(c)){
        c = toupper(c);
      }
      printf("%c", c );

    }
  }  while(c != EOF);
}

void switchCase(){
  char c;
  do{
    c = getc(stdin);
    if(feof(stdin) == 0){

      if(isupper(c)){
        c = tolower(c);
      } else {
        c = toupper(c);
      }
      printf("%c", c );

    }
  }  while(c != EOF);
}

void makeNames(){
  char c;
  char lastChar = ' ';
  do{
    c = getc(stdin);
    if(feof(stdin) ==0){

      if(isspace(lastChar)){
        c = toupper(c);
      } else {
        c = tolower(c);
      }
      printf("%c", c );
      lastChar = c;

    }
  }  while(c != EOF);
}

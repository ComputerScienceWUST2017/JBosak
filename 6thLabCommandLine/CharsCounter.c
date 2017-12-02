
#include <stdio.h>
#include <ctype.h>
#include <string.h>

void counterChars( char arg);
void readingChars(int *chars);

int
main(int argc, char *argv[]){
  counterChars(argv[1][1]);// L or M
  return 0;
}

void counterChars(char arg){
  int allChars[256];
  readingChars(allChars);
  int appearsOften = 0;
  int appearsLeast = 0;

  int j;
  for (j = 0; j < 127; j++){
    if(allChars[appearsOften] <= allChars[j]){
      appearsOften = j;
    } else if(allChars[j] != 0 &&
       (allChars[j] <= allChars[appearsLeast] || appearsLeast == 0)){
      appearsLeast = j;
    }
  }
  if(arg == 'l' || arg == 'L'){
    printf("%c\t%d\n",appearsLeast, allChars[appearsLeast] );
  } else if (arg == 'm' || arg == 'M') {
    printf("%c\t%d\n",appearsOften, allChars[appearsOften] );
  }

}


void readingChars(int *chars){
  char c;
  int j;
  for (j = 0; j < 127; j++){
    chars[j]= 0;
  }
  do{
    c = getc(stdin);
    if(feof(stdin) ==0){
      if (isspace(c) == 0) {
        chars[c]++;
      }
    }
  }  while(c != EOF);
}

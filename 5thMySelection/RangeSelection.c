#include <stdio.h>
#include <string.h>
#include <ctype.h>


void startWith(char *pref);
void rangeSelection(char *from, char *to);
void startWithOrProceed(char *tag, int position);// 1 for "proceed", 2 for "follow"

int
main (int argc, char *argv[]){


	if(argc == 2){
		startWith(argv[1]);
	} else if(argc == 3) {
		if(strcmp(argv[1], "-") == 0){
			startWithOrProceed(argv[2], 1);
		} else if(strcmp(argv[2], "-") == 0){
			startWithOrProceed(argv[1], 2);
		} else if(strcmp(argv[1], "-") != 0 && strcmp(argv[2], "-") != 0){
			rangeSelection(argv[1], argv[2]);
		}
	}
	return 0;
}

void startWith(char *pref) {

	int lenOfStart = strlen(pref);
	char lineFromInput[100];

	while((feof(stdin) == 0)){


		fgets(lineFromInput, 99, stdin);

		char begginingOfInput[lenOfStart];

		int i;
		for(i = 0; i< lenOfStart; i++){
			begginingOfInput[i] = lineFromInput[i];
		}

		if(strcmp(pref, begginingOfInput) == 0){
			printf("%s\n", lineFromInput );
		}

	}

}

void rangeSelection(char *from, char *to) {

	int lenOfStart = strlen(to);
	char lineFromInput[100];


	while((feof(stdin) == 0)){

		gets(lineFromInput);
		char begginingOfInput[lenOfStart];

		int i;
		for(i = 0; i< lenOfStart; i++){
			begginingOfInput[i] = lineFromInput[i];
		}

		if((strcmp(from, begginingOfInput) <= 0) && (strcmp(to, begginingOfInput) >= 0)){
			printf("%s\n", lineFromInput );
		}

	}

}

void startWithOrProceed(char *tag, int a) {

	int lenOfTag = strlen(tag);
	char lineFromInput[100];


	while((feof(stdin) == 0)){

		gets(lineFromInput);

		char begginingOfInput[lenOfTag];

		int i;
		for(i = 0; i< lenOfTag; i++){
			if(isupper(lineFromInput[i])== 0){
				begginingOfInput[i] = lineFromInput[i];
			} else if(isupper(lineFromInput[i]) != 0){
				begginingOfInput[i] = tolower(lineFromInput[i]);
			}

		}

		if(a == 2){
			if(strcmp(tag, begginingOfInput) <= 0){
				printf("%s\n", lineFromInput );
			}
		} else if(a == 1) {
			if(strcmp(tag, begginingOfInput) >= 0){
				printf("%s\n", lineFromInput );
			}
		}
	}
}

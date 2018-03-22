#include<iostream>
#include<string.h>
#include <string>
#include <sstream>

using namespace std;

struct Element{
  int key;
  Element *next;
};

struct List{
  Element *head;
};

void init(List& l){
  l.head = NULL;
}

void insertHead(List& l, int x){
  Element *head = new Element;
  head->key = x;
  head->next = l.head;
  l.head = head;
}

bool deleteHead(List& l, int &oldHead){
  if(l.head != NULL){
    oldHead = l.head->key;
    delete l.head;
    l.head = l.head->next;
    return true;
  }
  return false;
}

void insertTail(List& l, int x){
    Element *tail = new Element;
    tail->key = x;
    tail->next = NULL;

    Element *el = l.head;
    if(el == NULL){
      l.head = tail;
      return;
    }
    while(el->next != NULL){
      el = el->next;
    }
    el->next = tail;
}

bool deleteTail(List& l, int &oldTail){
  if(l.head != NULL){
    Element *el = l.head;
    if(el->next != NULL){
      while(el->next->next != NULL){
        el = el->next;
      }
      oldTail = el->next->key;
      delete el->next;
      el->next = NULL;
    }else if(el->next == NULL){
      oldTail = el->key;
      l.head = NULL;
    }
    return true;
  }
	return false;
}

int findPosOfValue(List& l, int value){
  if(l.head != NULL){
    int index = 0;
    for(Element *el = l.head; el != NULL;el = el->next){
      if(el->key == value)
        return index;
      index++;
    }
  }
  return -1;
}

bool deleteValue(List& l, int value){
  if(l.head != NULL){
    Element *el = l.head;
    if(el->key == value){
      delete el;
      l.head = l.head->next;
      return true;
    }
    while(el->next != NULL){
      if(el->next->key == value){
        delete el->next;
        el->next = el->next->next;
        return true;
      }
      el = el->next;
    }
  }
  return false;
}

bool atPosition(List& l, int pos, int &value){
  if(l.head != NULL){
    int index = 0;
    for(Element *el = l.head; el != NULL;el = el->next){
      if(index == pos){
        value = el->key;
        return true;
      }
      index++;
    }
  }
	return false;
}

void showListFromHead(List& l){
  if(l.head != NULL){
    Element *a = l.head;
    cout<<a->key<<",";
    while(a->next != NULL){
      cout<<a->next->key<<",";
      a = a->next;
    }
  }
  cout<<"\n";
}

void clearList(List& l){
  if(l.head != NULL){
    Element *temp;
    Element *el = l.head;
    while(el->next != NULL){
      temp = el;
      el = el->next;
      delete temp;
    }
    delete el;
    l.head = NULL;
  }
}

void showBool(bool val){
	if(val)
		cout << "true" << endl;
	else
		cout << "false" << endl;
}


bool isCommand(const string command,const char *mnemonic){
	return command==mnemonic;
}

int main(){
	string line;
	string command;
	List *list=NULL;
	int currentL=0;
	int value;
	cout << "START" << endl;
	while(true){
		getline(cin,line);
		std::stringstream stream(line);
		stream >> command;
		if(line=="" || command[0]=='#')
		{
			// ignore empty line and comment
			continue;
		}

		// copy line on output with exclamation mark
		cout << "!" << line << endl;;

		// change to uppercase
		command[0]=toupper(command[0]);
		command[1]=toupper(command[1]);

		if(isCommand(command,"HA")){
			cout << "END OF EXECUTION" << endl;
			break;
		}


		// zero-argument command
		if(isCommand(command,"DH"))
		{
			int retValue;
			bool retBool=deleteHead(list[currentL],retValue);
			if(retBool)
				cout << retValue << endl;
			else
				showBool(retBool);
			continue;
		}
		if(isCommand(command,"DT"))
		{
			int retValue;
			bool retBool=deleteTail(list[currentL],retValue);
			if(retBool)
				cout << retValue << endl;
			else
				showBool(retBool);
			continue;
		}

		if(isCommand(command,"SH"))
		{
			showListFromHead(list[currentL]);
			continue;
		}

		if(isCommand(command,"CL"))
		{
			clearList(list[currentL]);
			continue;
		}

		if(isCommand(command,"IN"))
		{
			init(list[currentL]);
			continue;
		}

		// read next argument, one int value
		stream >> value;

		if(isCommand(command,"FP"))
		{
			int ret;
			ret=findPosOfValue(list[currentL],value);
			cout << ret << endl;
			continue;
		}

		if(isCommand(command,"DV"))
		{
			showBool(deleteValue(list[currentL],value));
			continue;
		}


		if(isCommand(command,"AT"))
		{
			int retValue;
			bool retBool=atPosition(list[currentL],value,retValue);
			if(retBool)
				cout << retValue << endl;
			else
				showBool(retBool);
			continue;
		}

		if(isCommand(command,"CH"))
		{
			currentL=value;
			continue;
		}

		if(isCommand(command,"IH"))
		{
			insertHead(list[currentL],value);
			continue;
		}

		if(isCommand(command,"IT"))
		{
			insertTail(list[currentL],value);
			continue;
		}

		if(isCommand(command,"GO"))
		{
			list=new List[value];
			continue;
		}

		cout << "wrong argument in test: " << command << endl;
	}
}

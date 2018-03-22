#include<iostream>
#include <string>
#include <sstream>

using namespace std;


// Two-way unordered cycled list without sentinel
struct Element{
  int content;
  Element *next;
  Element *prev;
};

struct List2W{
  Element *head;
};

void init(List2W& l){
  l.head = new Element;
  l.head = NULL;
}

void duplicateElements(List2W& l){
  if(l.head != NULL){
    Element *el1 = l.head;
    Element *el2;
    do{
      el2 = el1->next;
      Element *nElem = new Element;
      nElem->content = el1->content;
      el1->next = nElem;
      nElem->prev = el1;
      nElem->next = el2;
      el2->prev = nElem;
      el1 = el1->next->next;
    }while(el1!= l.head);
  }

}

void insertHead(List2W& l, int x){
  Element *head = new Element;
  head->content = x;

  if(l.head == NULL){
    head->next = head;
    head->prev = head;
  }else{
    head->next = l.head;
    head->prev = l.head->prev;
    head->prev->next = head;
    l.head->prev = head;
  }

  l.head = head;
}

bool deleteHead(List2W& l, int &value){
  if(l.head != NULL){


  if(l.head->prev == l.head){
    value = l.head->content;
    l.head = NULL;
    return true;
  }

    value = l.head->content;
    l.head->prev->next = l.head->next;
    l.head->next->prev = l.head->prev;
    l.head = l.head->next;
    return true;
  }
  return false;
}

void insertTail(List2W& l, int x){
  if(l.head == NULL){
    insertHead(l,x);
  }else{
    Element *tail = new Element;
    tail->content = x;
    if(l.head->prev == NULL){
      tail->prev = l.head;
    }else
    tail->prev = l.head->prev;
    tail->next = l.head;
    l.head->prev->next = tail;
    l.head->prev = tail;
  }
}

bool deleteTail(List2W& l, int &value){
  if(l.head != NULL){
    Element *tail = l.head->prev;
    if(l.head->prev == l.head){
      value = l.head->content;
      l.head = NULL;
      return true;
    }
    if(l.head != NULL){
      value = tail->content;
      tail->prev->next = tail->next;
      tail->next->prev = tail->prev;
      return true;
    }
  }
  return false;
}

int findValue(List2W& l, int value){
  if(l.head != NULL){
    Element *el = l.head;
    int index = 0;
    do{
      if(el->content == value){
        return index;
      }
      index++;
      el = el->next;
    }while(el != l.head);
  }
  return -1;
}

void removeAllValue(List2W& l, int value){
  if(l.head != NULL){
      Element *el = l.head;
      do{
        if(el->content == value){
          if(el == l.head){
            l.head = el->next;
            if(l.head->next == l.head){
              l.head = NULL;
              return;
            }
          }
          el->next->prev = el->prev;
          el->prev->next = el->next;
        }
        el = el->prev;
      }while(el!= l.head);
      int a = 5;
      if(l.head->content == value){
        deleteHead(l, a);
      }
    }
}

void showListFromHead(List2W& l){
  if(l.head != NULL && l.head->next != NULL){
    Element *a = l.head;
    cout<<a->content<<",";
    while(a->next != l.head && a->next != NULL){
      cout<<a->next->content<<",";
      a = a->next;
    }
  }
  cout<<"\n";
}

void showListFromTail(List2W& l){
  if(l.head != NULL){
    Element *a = l.head;
    do{
      a = a->prev;
      cout<<a->content<<",";
    }while(a != l.head);
  }
  cout<<"\n";
}

void clearList(List2W& l){
  if(l.head != NULL){
    Element *temp;
    Element *el = l.head;
    while(el->next != l.head){
      temp = el;
      el = el->next;
      delete temp;
    }
    delete el;
    l.head = NULL;
  }
}

void addList(List2W& l1,List2W& l2){
  if (l1.head == NULL){
    l1 = l2;
    l2.head = NULL;
  }
	else if (l2.head == NULL){return;}
	else if (l1.head == l2.head){return;}
  if(l2.head != NULL){
    Element *e2 = l2.head;
    do{
      insertTail(l1,e2->content);
      e2 = e2->next;
    }while(e2 != l2.head && e2->next != NULL);
    clearList(l2);
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
  List2W *list;
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
    if(isCommand(command,"IN")) //*
    {
      init(list[currentL]);
      continue;
    }
    if(isCommand(command,"DH")) //*
		{
			int retValue;
			bool retBool=deleteHead(list[currentL],retValue);
			if(retBool)
				cout << retValue << endl;
			else
				showBool(retBool);
			continue;
		}
		if(isCommand(command,"DT")) //*
		{
			int retValue;
			bool retBool=deleteTail(list[currentL],retValue);
			if(retBool)
				cout << retValue << endl;
			else
				showBool(retBool);
			continue;
		}

		if(isCommand(command,"SH")) //*
		{
			showListFromHead(list[currentL]);
			continue;
		}
    if(isCommand(command,"DP")) //*
		{
			duplicateElements(list[currentL]);
			continue;
		}

		if(isCommand(command,"ST")) //*
		{
			showListFromTail(list[currentL]);
			continue;
		}

		if(isCommand(command,"CL")) //*
		{
			clearList(list[currentL]);
			continue;
		}



		// read next argument, one int value
		stream >> value;

		if(isCommand(command,"FV")) //*
		{
			int ret;
			ret=findValue(list[currentL],value);
			cout << ret << endl;
			continue;
		}

		if(isCommand(command,"RV")) //*
		{
			removeAllValue(list[currentL],value);
			continue;
		}


		if(isCommand(command,"AD")) //*
		{
			addList(list[currentL],list[value]);
			continue;
		}

		if(isCommand(command,"CH")) //*
		{
			currentL=value;
			continue;
		}

		if(isCommand(command,"IH")) //*
		{
			insertHead(list[currentL],value);
			continue;
		}

		if(isCommand(command,"IT")) //*
		{
			insertTail(list[currentL],value);
			continue;
		}

		if(isCommand(command,"GO")) //*
		{
			list=new List2W[value];
			continue;
		}

		cout << "wrong argument in test: " << command << endl;
	}
}

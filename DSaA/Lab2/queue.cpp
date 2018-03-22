#include<iostream>
#include<string.h>
#include <string>
#include <sstream>

using namespace std;

	class Queue{
	public:
		int *arr;
		int size;
		int end;
	};

	void init(Queue& q, int size){
		q.end = 0;
		q.arr = new int[size];
		q.size = size;
	}

	void resize(Queue& q, int newSize){
		int *newArray = new int[newSize];
		int i;
		int maxValue;
		if(newSize >= q.size){
			maxValue = q.size;
		}else
			maxValue = newSize;
		for(i = 0; i < maxValue; i++){
			newArray[i] = q.arr[i];
		}
		delete[] q.arr;
		q.arr = newArray;
		q.size = newSize;
		if(q.end > q.size){
			q.end = q.size;
		}
	}
	bool isFull(Queue& q){
		return q.end == q.size;
	}

	bool enqueue(Queue& q, int value){
		if(isFull(q))
			return false;
		q.arr[q.end++] = value;
		return true;
	}

	bool isEmpty(Queue& q){
		return q.end == 0;
	}

	bool dequeue(Queue& q, int &value){
		if(isEmpty(q))
			return false;
		value = q.arr[0];
		for(int i = 1; i < q.end; i++){
			q.arr[i-1] = q.arr[i];
		}
		q.end--;
		return true;
	}

	void show(Queue& q){
		for(int i = 0; i < q.end; i++){
			cout<<q.arr[i]<<",";
		}
		cout<<"\n";
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
	Queue *queue=NULL;
	int currentQ=0;
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
		if(isCommand(command,"EM"))
		{
			showBool(isEmpty(queue[currentQ]));
			continue;
		}
		if(isCommand(command,"FU"))
		{
			showBool(isFull(queue[currentQ]));
			continue;
		}
		if(isCommand(command,"SH"))
		{
			show(queue[currentQ]);
			continue;
		}
		if(isCommand(command,"DE"))
		{
			int ret;
			bool retBool=dequeue(queue[currentQ],ret);
			if(!retBool)
				cout << "false" << endl;
			else
				cout << ret << endl;
			continue;
		}

		// read next argument, one int value
		stream >> value;

		if(isCommand(command,"GO"))
		{
			queue=new Queue[value];
			continue;
		}
		if(isCommand(command,"CH"))
		{
			currentQ=value;
			continue;
		}

		if(isCommand(command,"IN"))
		{
			init(queue[currentQ],value);
			continue;
		}

		if(isCommand(command,"EN"))
		{
			bool retBool=enqueue(queue[currentQ],value);
			showBool(retBool);
			continue;
		}
		if(isCommand(command,"RS")){
			resize(queue[currentQ], value);
			continue;
		}
		cout << "wrong argument in test: " << command << endl;
	}
}

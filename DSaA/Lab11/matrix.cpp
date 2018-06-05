#include <iostream>
#include <string.h>
#include <sstream>
#include <fstream>


using namespace std;

#define FILE_NAME "matrixFile.txt"
#define INFINITY 10000000

enum Color {BLACK, GREY, WHITE};

struct Graph{
  int **matrix;
  Color *color;
  int *queue;
  int queueSize;
  int size;
};
int minDistance(Graph &g, bool isIncluded[]){
  int min = INFINITY;
  int minIndex = 0;
  for(int i = 0;i<g.size;i++){
    if(!isIncluded[i] && g.queue[i]<=min){
      min = g.queue[i];
      minIndex = i;
    }
  }
  return minIndex;
}

void singleSourceShortestPath(Graph &g,int value){
  bool isIncluded[g.size];
  for(int i = 0;i<g.size;i++){
    g.queue[g.queueSize++] = INFINITY;
    isIncluded[i]= false;
  }

  g.queue[value] = 0;
  for(int i = 0;i<g.size;i++){
    for(int c = 0;c<g.size-1;c++){


      int u = minDistance(g,isIncluded);
      isIncluded[u] = true;
      for(int j = 0;j<g.size;j++){
        if(!isIncluded[j] &&
          g.matrix[u][j]!= INFINITY &&
          g.queue[u]!= INFINITY &&
          g.queue[u]+g.matrix[u][j] < g.queue[j]){
            g.queue[j] =g.queue[u] +  g.matrix[u][j];
          }
    }
  }
  cout<<i<<"("<<g.queue[i]<<")"<<"\n";

  }

}

int dequeue(Graph &g){
  int ret = -1;
  if(g.queueSize > 0){
    ret = g.queue[0];
    for(int i = 0;i < g.queueSize-1;i++){
      g.queue[i] = g.queue[i+1];
    }
  }
  g.queueSize--;

  return ret;
}
void dfsIterative(Graph &g, int value){
  int x = 0;
  g.queue[g.queueSize++] = value;
  while(g.queueSize != 0){
    x = dequeue(g);

  }

}

void bfsVisit(Graph &g, int value){
  for(int i = 0;i<g.size;i++){
    if(g.matrix[value][i] != 0 && g.matrix[value][i] != INFINITY){
      if(g.color[i] == WHITE){
        cout<<i<<",";
        g.color[i] = GREY;
        g.queue[g.queueSize++] = i;
       }
    }
  }
  g.color[value] = BLACK;
}

void breadthFirstSearch(Graph &g, int value){
  for(int i = 0;i<g.size;i++){
    g.color[i] = WHITE;
  }
  cout<<value<<",";
  g.color[value] = GREY;
  g.queue[g.queueSize++] = value;
   while(g.queueSize != 0){
     value = dequeue(g);
     if(value == -1){
       return;
     }
     bfsVisit(g,value);
   }
   cout<<"\n";
}



void dsfVisit(Graph &g, int u){
  g.color[u] = GREY;
  cout<<u<<",";
  for(int i = 0;i<g.size;i++){
    if(g.matrix[u][i] != 0 && g.matrix[u][i] != INFINITY){
      if(g.color[i] == WHITE){
        dsfVisit(g,i);
      }
    }
  }
  g.color[u] = BLACK;
}

void depthFirstSearch(Graph &g, int value){
  for(int i = 0;i<g.size;i++){
    g.color[i] = WHITE;
  }
  if(value < g.size){
    dsfVisit(g,value);
  }
  cout<<"\n";

}


void writeToFile(Graph &g){
  ofstream matrixFile;
  matrixFile.open(FILE_NAME);
  for(int i = 0;i<g.size;i++){
    for(int j = 0; j<g.size;j++){
      if(g.matrix[i][j] == INFINITY){
        matrixFile<<"-,";
      }else{
        matrixFile<<g.matrix[i][j]<<",";
      }
    }
    matrixFile<<"\n";
  }
  matrixFile.close();
}

void loadGraph(Graph &g, int n, int m){
  g.queue = new int[n];
  g.queueSize = 0;
  g.size = n;
  g.color = new Color[n];
  g.matrix = new int*[n];

  for(int i = 0;i<n;i++){
    g.matrix[i]= new int[n];
    for(int j = 0; j<n;j++){
      g.matrix[i][j] = INFINITY;
      if(i==j){
        g.matrix[i][j] = 0;
      }
    }
  }
    for(int j = 0; j<m;j++){
      int a, b;
      int c;
      cin>>a;
      cin>>b;
      cin>>c;
      g.matrix[a][b] = c;
  }
}

void insertEdge(Graph &g, int u, int v, double weight){
  if(u != v)
    g.matrix[u][v] = weight;
}

bool findEdge(Graph &g, int u, int v, double &weight){
  if(u != v){
    if(g.matrix[u][v] != INFINITY){
      weight = g.matrix[u][v];
      return true;
    }
  }
  return false;
}

void showAsMatrix(Graph &g){
  for(int i = 0;i<g.size;i++){
    for(int j = 0; j<g.size;j++){
      if(g.matrix[i][j] == INFINITY){
        cout<<"-,";
      }else{
        cout<<g.matrix[i][j]<<",";
      }
    }
    cout<<"\n";
  }
}

void showAsArrayOfLists(Graph &g){
  for(int i = 0; i < g.size; i++){
  cout<<i<< ":";
  for(int j = 0; j < g.size; j++){
    if(g.matrix[i][j] != 0 && g.matrix[i][j] != INFINITY){
      cout<<j<<"("<<g.matrix[i][j]<<")"<<",";
    }
  }
  cout<<"\n";
}
}

bool isCommand(const string command,const char *mnemonic){
	return command==mnemonic;
}


int main(){
	string line;
	string command;
	Graph *graph;
	int currentT=0;
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

		// zero-argument command
		if(isCommand(command,"HA")){
			cout << "END OF EXECUTION" << endl;
			break;
		}
		// zero-argument command
		if(isCommand(command,"SM"))
		{
			showAsMatrix(graph[currentT]);
			continue;
		}

		if(isCommand(command,"SA"))
		{
			showAsArrayOfLists(graph[currentT]);
			continue;
		}
    if(isCommand(command,"WF"))
    {
      writeToFile(graph[currentT]);
      continue;
    }

		// read next argument, one int value
		stream >> value;

    if(isCommand(command,"BF"))
    {
      breadthFirstSearch(graph[currentT],value);
      continue;
    }
    if(isCommand(command,"DF"))
    {
      depthFirstSearch(graph[currentT],value);
      continue;
    }
    if(isCommand(command,"SS"))
    {
      singleSourceShortestPath(graph[currentT],value);
      continue;
    }

		if(isCommand(command,"LG"))
		{
			int m;
			stream >> m;
			loadGraph(graph[currentT],value,m);
			continue;
		}

		if(isCommand(command,"IE"))
		{
			int v;
			double w;
			stream >> v >> w;
			insertEdge(graph[currentT],value,v,w);
			continue;
		}

		if(isCommand(command,"FE"))
		{
			int v;
			stream >> v;
			double w;
			bool ret=findEdge(graph[currentT],value,v,w);

			if(ret)
				cout << w << endl;
			else
				cout << "false" << endl;
			continue;
		}


		if(isCommand(command,"CH"))
		{
			currentT=value;
			continue;
		}

		if(isCommand(command,"GO"))
		{
			graph=new Graph[value];
			continue;
		}


		cout << "wrong argument in test: " << command << endl;
		return 1;
	}
}

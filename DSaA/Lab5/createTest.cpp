#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;
int randInt(int max){
    return rand()%(max+1);
}
void writeCommendToFile(int num, int x){
    switch(num){
        case 0:
        {
            cout<<"IS "<<x<<endl;
            return;
        }
        case 1:
        {
            cout<<"BS "<<x<<endl;
            return;
        }
        case 2:
        {
            cout<<"MI "<<x<<endl;
            return;
        }
    }
}
void generateNumbers(int x){
  for(int i = x;i!=0;i--){
    cout<<" "<<randInt(100);
  }cout<<"\n";
}
int main() {
    srand((unsigned)time(0));
    int x;

    for(int i=0;i<10;++i){
        x = randInt(100);
        writeCommendToFile(randInt(3),x);
        generateNumbers(x);
    }
    cout<<"HA\n"<<endl;
    return 0;
}

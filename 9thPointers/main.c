#include "func.h"


int
main(){
  struct personalData *data[10];
  int len = readPtrData(data,sizeof(data)/sizeof(*data));
  printAllData(data,len);

  weightSort(data,len);
  puts("after weight sort");
  printAllData(data,len);

  remarkstSort(data,len);
  puts("after remarks sort");
  printAllData(data,len);

  puts("index 2:");
  printData(data[2],len);
  puts("\n End of work!");

  return 0;
}

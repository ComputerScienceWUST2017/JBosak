#include "func.h"


int
main(){
  personalData data[10];
  int len = readData(data,sizeof(data)/sizeof(personalData));
  char *msgBad = "No available data";
  int idx;
  idx = getOldestPersen(data);
  printInfo(data, idx, "Oldest person", msgBad);
  idx = getSlimmestPersen(data, len);
  printInfo(data, idx, "slimmest person", msgBad);
  printInfo(data, len-1, "last person", msgBad);//last person who exist
  puts("\n End of work!");

  return 0;
}

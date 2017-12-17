#include "func.h"


int
main(){
  personalData data[10];
  int len = readData(data,sizeof(data)/sizeof(personalData));
  char *msgBad = "No available data";
  int idx;

  idx = getOldestPersen(data, len);
  printInfo(data, idx, "Oldest person", msgBad);
  idx = getSlimmestPersen(data, len);
  printInfo(data, idx, "slimmest person", msgBad);
  printInfo(data, len-1, "last person", msgBad);
  puts("\nEnd of work!");
  return 0;
}

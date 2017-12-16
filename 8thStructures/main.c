#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "func.h"


int
main()
{
  personalData data[10];
  int len= readData(data,sizeof(data)/sizeof(personalData));
  char *msgBad="No available data";
  int idx;
  idx=getOldestPersen(data, len);
  printInfo(data, idx, "Oldest person", msgBad);
  idx=getSlimmestPersen(data, len);
  printInfo(data, idx, "slimmest person", msgBad);
  puts("\nEnd of work!");
  return 0;
}

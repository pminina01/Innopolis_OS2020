#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <sys/resource.h>
int main(void) {
  int n=1024*1024*100;
  for (int i=0;i<10;++i){
    struct rusage usage;
    void *p=malloc(n);
    memset(p,0,n);
    getrusage(RUSAGE_SELF, &usage);
    printf("%ld\n",usage.ru_maxrss); 
    sleep(1);
  }
  return 0;
}
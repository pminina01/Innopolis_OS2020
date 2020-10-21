#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
int main(void) {
  int n=10000000;
  for (int i=0;i<10;++i){
    void *p=malloc(n);
    if(p!=NULL){
      memset(p,0,n);
    }
    sleep(1);
  }
}
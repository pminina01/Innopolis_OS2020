#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

int main(void) {
  char *s="This is a nice day";
  int f=open("ex1.txt",O_RDWR);
  int n = strlen(s);
  struct stat buff;
  fstat(f, &buff); 
  void *m = mmap(NULL, n, PROT_READ | PROT_WRITE, MAP_SHARED, f, 0);
  ftruncate(f, sizeof(char) * n);
  strcpy(m, s);
  close(f);
}
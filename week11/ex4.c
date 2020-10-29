#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>

int main () {
  int f1 = open("ex1.txt", O_RDONLY);
	int f2 = open("ex1.memcp.txt", O_CREAT | O_RDWR);

	struct stat buff;

  char* s1 = mmap(NULL, buff.st_size, PROT_READ, MAP_SHARED, f1, 0);
	ftruncate(f2, buff.st_size);
	char* s2 = mmap(NULL, buff.st_size, PROT_WRITE, MAP_SHARED, f2, 0);
  memcpy(s2, s1, buff.st_size);

	munmap(s1, buff.st_size);
	munmap(s2, buff.st_size);
	close(f1);
	close(f2);
	return 0;

}
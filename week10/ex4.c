#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <stdlib.h>
#include <values.h>
 


int main(int argc, char *argv[]) {
  int n=255;
	DIR *dirp = opendir("tmp/");
	if (dirp == NULL) {
		return -1;
	}
  char names[n];
  int ind[n];
	struct dirent *dp;
  struct stat *s = malloc(sizeof(struct stat));
	
	FILE *f = fopen("ex4.txt", "w");
  
	while ((dp = readdir(dirp)) != NULL) {
		snprintf(names, sizeof(names), "%s%s", "tmp/", dp->d_name); 
		if (s->st_nlink > 1) {
			fprintf(f, "%s\n", names);
		}
	}
	fclose(f);
	return 0;
}
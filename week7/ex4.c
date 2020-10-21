#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void *reallocc(void *ptrmem, size_t size) {
	void *new;
  if (ptrmem==NULL) {
    new = malloc(size);

	} else if (size == 0) {
		free(ptrmem);
    new=NULL;
		return new;

	}else {
    new = malloc(size);
    if (new) { // Copy content to new array
      memcpy(new, (char *)ptrmem, size);
    }
    free(ptrmem);
	}
  return new;
}
int main() {
	printf("Array of size 5: [");
	int *a = malloc(5*sizeof(int));
	for (int i = 0; i < 5; ++i) {printf("%d ", a[i]);}
	printf("]\n");

  printf("Array of new size 10: ["); 
	a = reallocc(a, 10*sizeof(int));
	for (int i = 0; i < 10; ++i) {printf("%d ", a[i]);}
	printf("]\n");

  printf("Array of new size 7: [");
	a = reallocc(a, 7*sizeof(int));
	for (int i = 0; i < 7; ++i) {printf("%d ", a[i]);}
	printf("]\n");

	return 0;
}
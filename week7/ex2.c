#include <stdio.h>
#include <stdlib.h>

int main() {
	int n = 0;
	int *a;

  //Ask user to enter N
  printf("N: ");
  scanf("%d", &n);
  printf("\n");

	a = malloc(n*sizeof(int)); //Dynamically allocate memory for an array
	for (int i = 0; i < n; ++i) {  //Fill the array 
		a[i] = i;
	}
	for (int i = 0; i < n; i++) { //Print the array
		printf("%d ", a[i]);
	}
	free(a); //Deallocate memory
}
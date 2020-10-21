#include <stdio.h>

int main(int argc, char *argv[]) {
	char c[200]={};
	printf("Command: ");
	while (scanf("%s", c) > 0) {
		system(c);
		printf("Command: ");
	}
}
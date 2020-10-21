#include <stdio.h>

int main(int argc, char *argv[]) {
	char command[200]={};
	printf("Command: ");
	while (fgets(command, 200, stdin) != NULL) {
		system(command);
		printf("Command: ");
	}
}	
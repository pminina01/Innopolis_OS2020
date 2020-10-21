#include <stdio.h>
int main(int argc, char *argv[]) {
	for (int i = 0; i <= 2; i++) {
		fork();
	}
	sleep(5);
}
/*
-bash----ex2---ex2---ex2---ex2
             |     |-ex2
			 |-ex2---ex2
			 |-ex2
*/
#include <stdio.h>
int main()
{
    int n = fork();
    if (n==0){
        printf("Hello from child [PID - %d]\n", getpid());
    }
    else{
        printf("Hello from parent [PID - %d]\n", getpid());
    }
}
/* ex2.sh :
gcc ex1.c -o ex1.out
for i in {1..10}
do
    ./ex1.out
done
*/
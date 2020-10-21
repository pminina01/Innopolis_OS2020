#include <stdio.h>
#include <pthread.h>

void *thread(void *threadid){
    printf("Hello from hread №%d\n",(int)threadid);
    printf("Thread is %ld\n",(long) pthread_self());
    printf("Exit from thread №%d\n\n",(int)threadid);
    pthread_exit(NULL);
}
int main()
{
    int n=3; //number of threads
    pthread_t th[n];
    for (int i=0;i<n;i++){
        pthread_create(th+i,NULL,thread,(void *)i);
        pthread_join(th[i],NULL);
        //printf("Created thread №%d\n",i);
    }
    pthread_exit(NULL);
}

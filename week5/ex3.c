#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

//GLOBAL VARIABLES:
int n=10; //size of buffer
int buffer[10]; //buffer for producer and consumer
int top=0; //top of buffer

int sleepC=1; //(Does) consumer sleep?
int sleepP=0; //(Does) producer sleep?
int numb=1; //number to write

//Produce function
void p(){
    while (1){
        while(top>=n){//here can occur busy waiting
            //when top>=n this means that there is no space to produce
            sleepP=1;
        }
        //Produce
        buffer[top]=numb; 
        printf("produce %d\n",buffer[top]);
        numb+=1;
        top+=1;
        sleepC=0; //wake up concumer
    }
}

//Consume function
void c(){
    while (1){
        
        while(top<=0){//here can occur busy waiting
            //top<=0 means that buffer is empty and 
            //there is nothing to comsume, so need to sleep,
            //wait for producer
            sleepC=1;
        }
        //consume from buffer
        printf("consume %d\n",buffer[top]);
        top-=1;
        sleepP=0; //wake up producer
    }
}
int main() {
    pthread_t producer, consumer;
    pthread_create(&producer, NULL, p, NULL);
    pthread_create(&consumer, NULL, c, NULL);
    pthread_join(producer, NULL);
}

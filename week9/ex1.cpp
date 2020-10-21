#include <stdio.h>
#include <stdlib.h>
#define n 10 // amount of page frames

struct frame{
    unsigned int age; // age of frame
    unsigned int page_number;
};

int hit = 0;		// number of hits
int miss = 0;		// number of misses
int clock_tick = 0;
struct frame frames[n];
FILE *input;

void update(int next_page) {
	int ind = 0;
	for (int i = 0; i < n; ++i) {
		if (frames[i].age < frames[ind].age) {
			ind = i;
		}
		frames[i].age = frames[i].age >> 1;
	}
	for (int i = 0; i < n; ++i) {
		if (frames[i].page_number == next_page) {
			frames[i].age = frames[i].age | (1 << 7);
			hit+=1;
			return;
		}
	}
	// Miss
	miss++;
	frames[ind].age = 1 << 7;
	frames[ind].page_number = next_page;
}

int main(int argc, char const *argv[])
{
    //Initialize
    for (int i = 0; i < n; i++){
        frames[i].age = 0;
        frames[i].page_number = 0;
    }
    //Open file
    input = fopen("input.txt", "r");
    //Aging algorithm
    int next_page;
    while (fscanf(input, "%d", &next_page)!=EOF){
        update(next_page);
    }
    printf("Hits\t%d\n", hit);
	printf("Misses\t%d\n", miss);
	printf("Hits/Misses\t%f\n", hit/(double)miss);
}
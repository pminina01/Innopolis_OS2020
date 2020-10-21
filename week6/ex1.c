#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
struct process
{
	int ct;
	int tat;
	int wt;
	int at;
	int bt;
};

int main()
{
    int n;
    double av_wt=0,av_tat=0;

    printf("Input number of processes: ");
    scanf("%d",&n);
    
    struct process a[n];
    
    printf("\nInput AT and BT(use space btw numbers):\n");
    
    //Read input
    for(int i=0;i<n;i++)
    {
        scanf("%d", &a[i].at);
		scanf("%d", &a[i].bt);
    }
    
    //Sorting array with processes
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (a[i].at < a[j].at){
                struct process t;
                t=a[i];
                a[i]=a[j];
                a[j]=t;
            }
        }
    }
    a[0].wt=0; //first process wait 0
 
    //Calculating waiting time
    for(int i=1;i<n;i++)
    {
        a[i].wt=0;
        for(int j=0;j<i;j++)
            a[i].wt+=a[j].bt;
    }
 
    printf("\nProcess\t\tBT\tWT\tTAT\tCT");
 
    //Calculating turnaround time and completion time
    for(int i=0;i<n;i++)
    {
        a[i].tat=a[i].bt+a[i].wt;
        a[i].ct=a[i].at+a[i].tat;
        printf("\nP%d\t\t%d\t%d\t%d\t%d",i+1,a[i].bt,a[i].wt,a[i].tat,a[i].ct);
    }
    //Calculating average Turnaround and average waiting time
    for(int i=0;i<n;i++)
    {
        av_wt+=a[i].wt;
        av_tat+=a[i].tat;
    }
    printf("\nAverage Turnaround Time:%lf",av_tat/n);
    printf("\nAverage Waiting Time:%lf",av_wt/n);

    return 0;
}
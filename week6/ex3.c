#include<stdio.h> 
struct process
{
	int ct;
	int tat;
	int wt;
	int at;
	int bt;
	int b_t;
};
int main() 
{ 
  int quantum;
  int n;
  double av_wt=0,av_tat=0;
  
  int count,time,remain,flag=0; 
  int at[10],bt[10],rt[10]; 
  
  printf("Input number of processes: ");
  scanf("%d",&n);
  struct process a[n];
  remain=n;
  
  printf("\nEnter Time Quantum: "); 
  scanf("%d",&quantum);
  
  printf("\nInput AT and BT(use space btw numbers):\n");
  //Read input
  for(int i=0;i<n;i++){
      scanf("%d", &a[i].at);
      scanf("%d", &a[i].bt);
      a[i].b_t=a[i].bt;
  }

   
  printf("\nProcess\t\tBT\tWT\tTAT\tCT"); 
  //Some feachures referenced
  for(time=0,count=0;remain!=0;) 
  { 
    if( a[count].bt<=quantum && a[count].bt>0) 
    { 
      time+=a[count].bt; 
      a[count].bt=0; 
      flag=1; 
    } 
    else if(a[count].bt>0) 
    { 
      a[count].bt-=quantum; 
      time+=quantum; 
    } 
    if(a[count].bt==0 && flag==1) 
    { 
      remain--; 
      a[count].tat=time-a[count].at;
      a[count].wt=time-a[count].at-a[count].bt;
      a[count].ct=a[count].at+a[count].tat;
      printf("\nP%d\t\t%d\t%d\t%d\t%d",count+1,a[count].b_t,a[count].wt,a[count].tat,a[count].ct);
      flag=0; 
    } 
    if(count==n-1) 
      count=0; 
    else if(a[count+1].at<=time) 
      count++; 
    else 
      count=0; 
  } 
  //Calculating average Turnaround and average waiting time
  for(int i=0;i<n;i++){
      av_wt+=a[i].wt;
      av_tat+=a[i].tat;
  }
  printf("\nAverage Turnaround Time:%lf",av_tat/n);
  printf("\nAverage Waiting Time:%lf",av_wt/n);
  return 0; 
}
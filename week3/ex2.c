#include <stdio.h> 
void bubble_sort(int a[], int n) 
{ 
    int t;
   for (int i = 0; i < n-1; i++)       
       for (int j = 0; j < n-i-1; j++)  
           if (a[j] > a[j+1]) {
            t=a[j];
            a[j]=a[j+1];
            a[j+1]=t;
           }
} 
int main() 
{ 
    int a[6] = {6,3,4,2,5,1}; 
    int n = sizeof(a)/sizeof(a[0]); 
    bubble_sort(a, n); 
    for (int i=0; i < n; i++){ 
        printf("%d ",a[i]); 
    }
} 
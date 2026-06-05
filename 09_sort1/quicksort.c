#include <stdlib.h>
#include <stdio.h>

static int qdebug=0;

void qsortDebug(int ano){
     qdebug=ano;
}

void PrintPartition(int a[],int lo,int hi,int median,int left,int right){
   int i;
   printf ("x=%2d:  [ ",median);
   if(right<lo)printf ("] ");
   for(i=lo;i<=hi;i++){
       if(i==left)printf ("[ ");
       printf("%2d ",a[i]);
       if(i==right)printf ("] ");
       }
   if(left>hi)printf ("[ ");
   printf ("]\n");
}

int GetRandom(int lo,int hi){
    return lo+rand()%(hi-lo+1);
}

void quicksort(int array[], int low, int high){
   int left, right, median, temp;

   if (high <= low) return;
   /* at least 2 elements */
   left=low; right=high;
   median=array[GetRandom(low,high)];
   /* partition array[low..high],  array[low..left-1]<=median and array[right+1..high]>=median */
   while(right >= left){
	   while(array[left] < median)left++;
       while(array[right] > median)right--;
       if(left > right) break;
       //swap
       temp=array[left]; array[left]=array[right]; array[right]=temp;
       left++; right--;
       }
    if(qdebug)PrintPartition(array,low,high,median,left,right);
   /* divide and conquer */
   quicksort(array, low, right);
   quicksort(array, left,  high);
 }





#include <stdio.h>
#include <stdlib.h>

void quickSort(int a[], int start,int end);
int partition(int a[],int start,int end);
//void randomizedPartiton(int *a,int start,int end);
int main()
{
  int a[10] = {9,7,5,3,1,8,6,2,0,4};
  quickSort(a,0,9);
  int i=0;
  for(i=0;i<10;i++)
    printf("%d ",a[i]);
  return 0;
}

int partition(int a[],int start,int end)
{
  int pivot = a[end];
  int partitionIndex = start;
  int i = partitionIndex;
  for(i=partitionIndex;i<=end;i++)
  {
    if(a[i]<pivot)
    {
      int temp = a[i];
      a[i] = a[partitionIndex];
      a[partitionIndex] = temp;
      partitionIndex++;
    }
  }
  int temp = a[partitionIndex];
  a[partitionIndex] = a[end];
  a[end] = temp;
  return partitionIndex;
}

void quickSort(int a[],int start, int end)
{
  if(start < end)
  {
    int partitionIndex = partition(a,start,end);
    quickSort(a,start,partitionIndex-1);
    quickSort(a,partitionIndex+1,end);
  }
}

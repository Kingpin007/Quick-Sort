/*
Author : Anirudh Kanabar
Date of Completion : 11/12/2015
Time : 10:36PM IST
Subject: Randomized quickSort in C
Time Complexity : Theta(nlogn)
Space Complexity : Theta(n) - For now
*/
#include <stdio.h>
#include <stdlib.h>

void quickSort(int a[], int start,int end);
int partition(int a[],int start,int end);
int randomizedPartiton(int a[],int start,int end);
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
int randomizedPartiton(int a[],int start,int end)
{
  int r = (rand() % (end+1-start))+start;
  int temp = a[r];
  a[r] = a[end];
  a[end] = temp;
  temp = partition(a,start,end);
  return temp;
}
void quickSort(int a[],int start, int end)
{
  if(start < end)
  {
    int partitionIndex = randomizedPartiton(a,start,end);
    quickSort(a,start,partitionIndex-1);
    quickSort(a,partitionIndex+1,end);
  }
}

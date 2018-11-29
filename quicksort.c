#include<stdio.h>
#include<stdlib.h>

void swap(int *a,int *b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}

int partition(int arr[],int low,int high)
{
	int i=low-1;
	for(int j=low;j<high;j++)
	{
		if(arr[j]<arr[high])
		{
			i++;
			swap(&arr[j],&arr[i]);
		}
	}
	swap(&arr[i+1],&arr[high]);
	return i+1;
}
void quicksort(int arr[],int low,int high)
{
	if(low<high)
	{
		int pi=partition(arr,low,high);
		quicksort(arr,low,pi-1);
		quicksort(arr,pi,high);
	}
}

int main()
{
	int n,arr[100],i;
	printf("Enter array size: ");
	scanf("%d",&n);
	printf("\nEnter array :");
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	quicksort(arr,0,n-1);
	printf("\nSorted array :");
	for(i=0;i<n;i++)
		printf("%d ",arr[i]);
	
}

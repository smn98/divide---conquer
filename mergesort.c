#include<stdlib.h>
#include<stdio.h>

void merge(int arr[],int l,int r,int m)
{
	int n1=m-l+1;
	int n2=r-m;
	int L[n1],R[n2];
	for(int i=0;i<n1;i++)
	{
		L[i]=arr[l+i];
	}
	for(int j=0;j<n2;j++)
	{
		R[j]=arr[m+1+j];
	}
	int i=0,j=0,k=l;
	while(i<n1 && j<n2)
	{
		if(L[i]<R[j])
			{
				arr[k]=L[i];
				i++;
				k++;
			}
		else
			{
				arr[k]=R[j];
				j++;
				k++;
			}
	}
	while(i<n1)
	{
		arr[k]=L[i];
		k++;
		i++;
	}
	while(j<n2)
	{
		arr[k]=R[j];
		k++;
		j++;
	}

}
void mergesort(int arr[],int l,int r)
{
	if(l<r)
	{
		int m=l+(r-l)/2;
		mergesort(arr,l,m);
		mergesort(arr,m+1,r);
		merge(arr,l,r,m);
	}
}

int main()
{
    int arr[] = {12, 11, 13, 5, 6, 7};
    int arr_size = sizeof(arr)/sizeof(arr[0]);
    mergesort(arr, 0, arr_size - 1);
    printf("\nSorted array is \n");
    for (int i=0; i < arr_size; i++)
        printf("%d ", arr[i]);
    return 0;
}

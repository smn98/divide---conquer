#include<stdio.h>

int binarySearch(int* arr,int l, int r, int search){
	if(l<=r){
	int mid = (l+r)/2;
	if(search == arr[mid])
		return mid;
	if(search < arr[mid])
		return binarySearch(arr,l,mid-1,search);
	if(search > arr[mid])
		return binarySearch(arr,mid+1,r, search);
	}
	return -1;
}

int main() 
{ 
   int arr[] = {2, 3, 4, 10, 40}; 
   int n = sizeof(arr)/ sizeof(arr[0]); 
   int x = 21; 
   int result = binarySearch(arr, 0, n-1, x); 
   (result == -1)? printf("Element is not present in array") 
                 : printf("Element is present at index %d", 
				 result); 
   return 0; 
} 

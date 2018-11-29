#include<stdlib.h>
#include<stdio.h>

struct pair{
	int min;
	int max;
};

struct pair minMax(int* arr, int low, int high){
	struct pair minmax, mml, mmr;
	int mid;
	
	if(low == high){
		minmax.min = arr[low];
		minmax.max = arr[low];
		return minmax;
	}
	
	if(high == low + 1){
		if(arr[low] < arr[high]){
			minmax.min = arr[low];
			minmax.max = arr[high];
		}
		else{
			minmax.min = arr[high];
			minmax.max = arr[low];
		}
		return minmax;	
	}
	
	mid = (low + high)/2;
	mml = minMax(arr,low, mid);
	mmr = minMax(arr, mid+1, high);
	
	if(mml.min < mmr.min)
		minmax.min = mml.min;
	else
		minmax.min = mmr.min;
		
	if (mml.max > mmr.max) 
    	minmax.max = mml.max; 
	else
	    minmax.max = mmr.max;      
	   
  	return minmax; 
}
int main()
{
    int arr[] = {1000, 11, 445,12, 330, 3000}; 
  int arr_size = 6; 
  struct pair minmax = minMax(arr, 0, arr_size-1); 
  printf("Minimum element is %d", minmax.min); 
  printf("\nMaximum element is %d", minmax.max);  
}

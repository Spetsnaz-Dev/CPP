#include <stdio.h>

// Merge two sorted subarrays arr[low .. mid] and arr[mid + 1 .. high]
int Merge(int arr[], int aux[], int low, int mid, int high)
{
	int k = low, i = low, j = mid + 1;
	int inversionCount = 0;
	
	// While there are elements in the left and right runs
	while (i <= mid && j <= high) 
	{
		if (arr[i] <= arr[j]) {
			aux[k++] = arr[i++];
		}
		else {
			aux[k++] = arr[j++];
			inversionCount += (mid - i + 1);	// NOTE
		}
	}

	// Copy remaining elements
	while (i <= mid)
		aux[k++] = arr[i++];

	// Don't need to copy second half

	// copy back to the original array to reflect sorted order
	for (int i = low; i <= high; i++)
		arr[i] = aux[i];
		
	return inversionCount;
}

// Sort array arr [low..high] using auxillary array aux
int MergeSort(int arr[], int aux[], int low, int high)
{
	// Base case
	if (high == low)	// if run size == 1
		return 0;

	// find mid point
	int mid = (low + ((high - low) >> 1));
	int inversionCount = 0;
	
	// recursively split runs into two halves until run size == 1,
	// then merge them and return back up the call chain

	inversionCount += MergeSort(arr, aux, low, mid);		// split / merge left half
	inversionCount += MergeSort(arr, aux, mid + 1, high); // split / merge right half
	inversionCount += Merge(arr, aux, low, mid, high);	// merge the two half runs

	return inversionCount;
}

int main()
{
	int arr[] = { 6,5,4,3,2,1 };
	bool res[5] =  {true};
    for(int i=0;i<5;i++)
        printf("%d", res[i]);
	int N = sizeof(arr)/sizeof(arr[0]);
 
	int aux[N];
	for (int i = 0; i < N; i++)
		aux[i] = arr[i];

	// get inversion count by performing merge sort on arr
	//printf("Inversion count is %d", MergeSort(arr, aux, 0, N - 1));

	return 0;
}

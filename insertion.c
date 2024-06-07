#include <stdio.h>

void InsertionSort(int arr[], int n)
{
    //cout<<"Welcome to Insertion Sort\n";

    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        // Move elements of arr[0..i-1],
        // that are greater than key, to one
        // position ahead of their
        // current position
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }

}



void group3(int array[], int array_size, int *output){
#pragma HLS INTERFACE mode=s_axilite port= group3
#pragma HLS INTERFACE mode=s_axilite port= array
#pragma HLS INTERFACE mode=s_axilite port= array_size
#pragma HLS INTERFACE mode=s_axilite port= output

	InsertionSort(array, array_size);

	for(int i=0; i<array_size; i++){
		output[i] = array[i];
	}
}

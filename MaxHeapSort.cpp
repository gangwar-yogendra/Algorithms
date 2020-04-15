/*
Max Heap Sort
*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>


void swap(int &a, int &b) {
    if(a == b) {
        return;
    }
    a=a+b;
    b=a-b;
    a=a-b;
}

void maxHeap(int arr[], int index, int arrSize) {
    int l = 2*index + 1;
    int r = 2*index + 2;
	
    int largest;
	
    if(l < arrSize && arr[l] > arr[index]) {
        largest = l;
    }
    else
    {
        largest = index;
    }
	
    if(r < arrSize && arr[r] > arr[largest]) {
        largest = r;
    }
	
    if(largest != index) {
        swap(arr[index], arr[largest]);
        maxHeap(arr, largest, arrSize);
    }
}

void heapSort(int arr[], int n) {
    for(int i = (n/2)-1; i>=0 ; i--) {
        maxHeap(arr, i, n);
    }
	
    // One by one extract an element from heap
    for (int i=n-1; i>=0; i--)
    {
        // Move current root to end
        swap(arr[0], arr[i]);
 
        // call max heapify on the reduced heap
        maxHeap(arr, 0, i);
    }

}

int main(int argc, char **argv)
{
    int arr[] = {9, 6, 5, 0, 8 ,2, 13, 7};	
    int sizeofArr = (sizeof(arr))/sizeof(arr[0]);
	
	heapSort(arr, sizeofArr);
	
	std::cout<<"Sorted array: "<<std::endl;
	// Print sorted array
	for(int i = 0; i<sizeofArr; i++) {
       std::cout<<arr[i]<<" ";
	}
	std::cout<<"\n";
    
	return 0;
}


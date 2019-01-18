1. Insert Sort
-----------------

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main(int argc, char **argv)
{
   if(argc < 2) {
      std::cout<<"usage: argv[0] <num 1> ....."<<std::endl;
      exit(-1);
   }
   
   std::cout<<"argc: "<<argc<<std::endl;
   int arr[argc-1];

   for (int i = 0; i<argc-1; i++) {
       arr[i] = atoi(argv[i+1]);
   }

   std::cout<<"Given array: "<<std::endl;
   for (int i = 0; i<argc-1; i++) {
       std::cout<<arr[i]<<" ";	   
   }
   std::cout<<"\n";
   
   int key;
   int j;
   // Start insertsion sort algorithm
   for(int i=0; i<argc-1; i++) {
	   key = arr[i];
	   j = i-1;
	   
	   while(j>=0 && arr[j] > key) {
		   arr[j+1] = arr[j];
		   j = j-1;
	   }
	   arr[j+1] = key;
   }
   
   
   std::cout<<"Sorted array: "<<std::endl;
   // Print sorted array
   for(int i = 0; i<argc-1; i++) {
	   std::cout<<arr[i]<<" ";
   }
   std::cout<<"\n";

   return 0;
}



2. Merge Sort
-------------------

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define INT_MAX_VALUE 3000

void merge(int arr[], int p, int q, int r) {
    int n1 = q-p+1;
    int n2 = r-q;
	
    int L[n1];
    int R[n2];
	
    for(int m = 0; m < n1; m++) {
        L[m] = arr[p+m];
    }
    
    for(int n = 0; n < n2; n++) {
        R[n] = arr[q+n+1];
    }
    L[n1] = INT_MAX_VALUE;
    R[n2] = INT_MAX_VALUE;
	
    int i=0, j=0;
    int k=0;
    for(k = p; k<=r; k++) {
        if(L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
    }
}

void mergeSort(int arr[], int l, int r) {
    if(r>l) {
        int mid = l+(r-l)/2;
		
        mergeSort(arr, l, mid);
        mergeSort(arr, mid+1, r);
		
        merge(arr, l, mid, r);
    }
}

int main(int argc, char **argv)
{
   if(argc < 2) {
      std::cout<<"usage: argv[0] <num 1> ....."<<std::endl;
      exit(-1);
   }
   
   std::cout<<"argc: "<<argc<<std::endl;
   int arr[argc-1];

   for (int i = 0; i<argc-1; i++) {
       arr[i] = atoi(argv[i+1]);
   }

   std::cout<<"Given array: "<<std::endl;
   for (int i = 0; i<argc-1; i++) {
       std::cout<<arr[i]<<" ";	   
   }
   std::cout<<"\n";
   
   int arr_size = sizeof(arr)/sizeof(arr[0]);
   mergeSort(arr, 0, arr_size-1);
   
   
   std::cout<<"Sorted array: "<<std::endl;
   // Print sorted array
   for(int i = 0; i<argc-1; i++) {
       std::cout<<arr[i]<<" ";
   }
   std::cout<<"\n";

   return 0;
}

3. Quick Sort
-----------------

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define INT_MAX_VALUE 3000

void swap(int &a, int &b) {
	if(a == b) {
		return;
	}
	a=a+b;
	b=a-b;
	a=a-b;
}

int partition(int arr[], int p, int r) {
    // Create key as the last element in array
    int key = arr[r];
    int i = p-1;
	int j;
	
	// traverse the array till r-1th element using j
	for(j = p; j<=r-1; j++) {
		if(arr[j] <= key) {
			i++;
            swap(arr[i], arr[j]);
		}
	}
    // After swaping all the array need to swap i+1 element off array with key value
	swap(arr[i+1], arr[r]);
	// retun the sorted element
	return (i+1);
}

void quickSort(int arr[], int l, int r) {
    if(r>l) {
        // q is index for sorted element
		int q = partition(arr, l, r);
        quickSort(arr, l, q-1);
        quickSort(arr, q+1, r);
    }
}

int main(int argc, char **argv)
{
   if(argc < 2) {
      std::cout<<"usage: argv[0] <num 1> ....."<<std::endl;
      exit(-1);
   }
   
   std::cout<<"argc: "<<argc<<std::endl;
   int arr[argc-1];

   for (int i = 0; i<argc-1; i++) {
       arr[i] = atoi(argv[i+1]);
   }

   std::cout<<"Given array: "<<std::endl;
   for (int i = 0; i<argc-1; i++) {
       std::cout<<arr[i]<<" ";	   
   }
   std::cout<<"\n";
   
   int arr_size = sizeof(arr)/sizeof(arr[0]);
   quickSort(arr, 0, arr_size-1);
   
   
   std::cout<<"Sorted array: "<<std::endl;
   // Print sorted array
   for(int i = 0; i<argc-1; i++) {
       std::cout<<arr[i]<<" ";
   }
   std::cout<<"\n";

   return 0;
}

4. Count Sort
-----------------

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>

/* Why we use count sort */
/* 
	If there are 1000000 number whose range are from 1-100 then we need to use count sort 
	for linear time O(n+k) which is less than O(nlogn)
*/ 

/* 
// Prototype Encoding 
CountingSort(A)
  //A[]-- Initial Array to Sort
  //Complexity: O(k)
  for i = 0 to k do
  c[i] = 0
 
  //Storing Count of each element
  //Complexity: O(n)
  for j = 0 to n do
  c[A[j]] = c[A[j]] + 1
 
  // Change C[i] such that it contains actual
  //position of these elements in output array
  ////Complexity: O(k)
  for i = 1 to k do
  c[i] = c[i] + c[i-1]
 
  //Build Output array from C[i]
  //Complexity: O(n)
  for j = n-1 downto 0 do
  B[ c[A[j]]-1 ] = A[j]
  c[A[j]] = c[A[j]] - 1
end func
*/


void countSort(int A[], int size) {
    int k = 10;
    int arrSize = size;
    int B[arrSize];
    int C[k];

    for(int i = 0; i<k; i++) {
        C[i] = 0;
    }

    for(int i = 0; i<size; i++) {
        C[A[i]] = C[A[i]] + 1;
    }
		
    for(int i = 1; i < k; i++) {
        C[i] = C[i] + C[i-1];
    }
	
    for(int j = size-1; j>=0; j--) {
        B[C[A[j]]-1] = A[j];
        C[A[j]] = C[A[j]]-1;
    }
	
    std::cout<<"Sorted Array: "<<std::endl;	
    for (int i=0; i<size; i++)
        printf("%d ", B[i]);
	
    std::cout<<"\n";
}

int main(int arc, char **argv) {
	int A[] = {5, 2, 2, 6, 3, 3 ,1, 2};
	int aSize = sizeof(A)/sizeof(A[0]);
	
	std::cout<<"Given Array: "<<std::endl;
	for(int i = 0; i< aSize; i++) {
		std::cout<<A[i]<<" ";
	}
	std::cout<<"\n";
	
	countSort(A, aSize);
}


5. Heap Sort
------------------

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


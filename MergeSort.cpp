/*
Merge sort algorithm
*/

#include <iostream>

void merge(int arr[], int p, int q, int r) {
    int n1 = q - p + 1;
    int n2 = r - q;

    int *L = new int[n1+1];
    int *R = new int[n2+1];

    for (int m = 0; m < n1; m++) {
        L[m] = arr[p + m];
    }

    for (int n = 0; n < n2; n++) {
        R[n] = arr[q + 1 + n];
    }
    L[n1] = INT_MAX;    //    INT_MAX_VALUE;
    R[n2] = INT_MAX;    //_VALUE;

    int i = 0, j = 0;
    int k = 0;
    for (k = p; k <= r; k++) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
    }

    delete[] L;
    delete[] R;

}

void mergeSort(int arr[], int l, int r) {
    if (r > l) {
        int mid = l + (r - l) / 2;

        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, r);

        merge(arr, l, mid, r);
    }
}

int main(int argc, char** argv)
{
    int arr[] = { 23, 34, 12, 33, 78, 45, 55, 89, 85, 46 };
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    std::cout << "Given array: " << std::endl;
    for (int i = 0; i < arr_size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
	
    mergeSort(arr, 0, arr_size - 1);

    std::cout << "Sorted array: " << std::endl;
    for (int i = 0; i < arr_size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";

    return 0;
}

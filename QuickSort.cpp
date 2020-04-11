#include <iostream>

void swap(int& a, int& b) {
    if (a == b) {
        return;
    }
    int t = a;
    a = b;
    b = t;
}

int partition(int arr[], int p, int r) {
    // Create key as the last element in array
    int key = arr[r];
    int i = p - 1;
    int j;

    // traverse the array till r-1 th place using j
    for (j = p; j <= r - 1; j++) {
        // arr[j] < key, then increase i and 
        // swap i, j th index value in array
        if (arr[j] <= key) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    // After trversing the array swap i+1 index value with key value
    swap(arr[i + 1], arr[r]);

    // retun the index
    return (i + 1);
}

void quickSort(int arr[], int l, int r) {
    if (r > l) {
        // q is index for sorted element
        int q = partition(arr, l, r);

        quickSort(arr, l, q - 1);
        quickSort(arr, q + 1, r);
    }
}

int main(int argc, char** argv)
{
    int arr[] = { 10, 7, 8, 9, 1, 5 };
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    std::cout << "Given array: " << std::endl;
    for (int i = 0; i < arr_size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";

    //int arr_size = sizeof(arr) / sizeof(arr[0]);
    quickSort(arr, 0, arr_size - 1);


    std::cout << "Sorted array: " << std::endl;
    // Print sorted array
    for (int i = 0; i < arr_size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";

    return 0;
}

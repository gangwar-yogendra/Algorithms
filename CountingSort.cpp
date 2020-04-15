/* Counting sort algorithm */

#include <iostream>

using namespace std;

void countingSort(int arr[], int n)
{
	int maxValue = INT_MIN;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] > maxValue)
		{
			maxValue = arr[i];
		}
	}

	/* Define new array of size maxValue */
	int* arr1 = new int[maxValue + 1];
	for (int i = 0; i <= maxValue; ++i)
	{
		arr1[i] = 0;
	}
	/* Print arr1[] */
	cout << "Initialized arr1:\n";
	for (int i = 0; i <= maxValue; i++)
	{
		std::cout << arr1[i] << " ";
	}
	std::cout << "\n";

	for (int i = 0; i < n; ++i)
	{
		arr1[arr[i]] = arr1[arr[i]] + 1;
	}

	/* Print arr1[] */
	for (int i = 0; i <= maxValue; i++)
	{
		std::cout << arr1[i] << " ";
	}
	std::cout << "\n";

	int k = 0;

	for (int i = 0; i <= maxValue; ++i)
	{
		if (arr1[i] != 0) {
			for (int j = 0; j < arr1[i]; j++)
			{
				arr[k] = i;
				k++;
			}
		}
	}

	/* Print Sorted Array[] */
	cout << "Sorted Array:\n";
	for (int i = 0; i <n; i++)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << "\n";

	delete[] arr1;
}

int main()
{
	int arr[] = { 3, 5, 8, 10, 1, 4, 2, 1 };
	int size = sizeof(arr) / sizeof(arr[0]);

	cout << "Given Array: \n";
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << "\n";
	countingSort(arr, size);

	return 0;
}

/* Longest Common Subsequence */
#include <iostream>

int LIS(int arr[], int n)
{
	int list[n];
	for(int k=0; k<n; k++)
	{
		list[k] = 1;
	}
	
	for(int i = 1; i<n; i++)
	{
		for(int j=0; j<i; j++)
		{
			if(arr[i] > arr[j] && list[i] < list[j] + 1)
			{
				list[i] = list[j] + 1;
			}
		}
	}
	
	/* Get max value from list array */
	int max = 0;
	for(int i = 0; i<n; i++)
	{
		if(max < list[i])
			max = list[i];
	}
		
	return max;
}

int main(int argc, char** argv)
{
	int arr[] = {50, 3, 10, 7, 40, 80};
	int n = sizeof(arr)/sizeof(arr[0]);
	
	std::cout<<"LIS: "<<LIS(arr, n)<<std::endl;
	return 0;
}
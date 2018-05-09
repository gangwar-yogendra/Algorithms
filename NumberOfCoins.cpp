/* Find minimum number of coins required to make total value */

#include <iostream>
#include <vector>

int findMinCoins(int arr[], int value, int sizeofArray)
{
	int numberofCoins = 0;
	std::vector<int> result;
	
	for(int i = sizeofArray-1 ; i>=0; i--)
	{
		while(value >= arr[i])
		{
			value -= arr[i];
			result.push_back(arr[i]);
		}
	}
	
	for(std::vector<int>::iterator it=result.begin(); it!=result.end(); it++)
	{
		numberofCoins++;
		std::cout<<*it<<" ";
	}
	
	return numberofCoins;
}

int main(int argc, char** argv)
{
	int arr[] = {1, 2, 5, 10, 20, 50, 100, 500, 1000};
	
	int n = sizeof(arr)/sizeof(arr[0]);
	std::cout<<"\nMin coins required for "<<findMinCoins(arr, 93, n);
	
	return 0;
}
/* 4. Minimum Number of Platforms Required for a Railway/Bus Station */
#include <iostream>
#include <algorithm>

using namespace std;

int findMinNumOfTrains(int arriveTime[], int departureTime[], int n)
{
	sort(arriveTime, arriveTime + n);
	sort(departureTime, departureTime + n);

	std::cout<<"ArriveTime sorted array: \n";	
	for(int i=0; i<n; i++)
	{
		std::cout<<arriveTime[i]<<" ";
	}
	
	std::cout<<"DepartureTime sorted array: \n";	
	for(int i=0; i<n; i++)
	{
		std::cout<<departureTime[i]<<" ";
	}
		
	int maxPlatform = 0;
	int platforRequired = 0;
	
	int i = 0; j = 0;
	
	// Logic simlar to Merging of two arrays
	while(i < n && j < n)
	{
		if(arriveTime[i] < departureTime[j])
		{
			// New train arrived
			platforRequired++;
			i++;
			
			if(platforRequired > maxPlatform)
				maxPlatform = platforRequired;
		}
		else
		{
			platforRequired--;
			j++;
		}
	}
	
	return maxPlatform;
}

int main()
{
	int arriveTime[] = {900, 940, 950, 1100, 1500, 1800};
	int departureTime[] = {910, 1200, 1120, 1130, 1900, 2000};
	
	int n = sizeof(arriveTime)/sizeof(arriveTime[0]);
	
	std::cout<<"Minimum number of platfor required: "
			 <<findMinNumOfTrains(arriveTime, departureTime, n)<<std::endl;
			 
	return 0;
}
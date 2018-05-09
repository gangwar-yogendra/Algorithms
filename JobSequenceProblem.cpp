#include <iostream>
#include <algorithm>

struct Job
{
	char id[3];
	int deadline;
	int profit;
};

bool compare(Job j1, Job j2)
{
	return (j1.profit > j2.profit);
}

int minValue(int x, int y)
{
	if(x<y)
		return x;
	else
		return y;
}

int findMax(int x, int y)
{
	if(x>y)
		return x;
	else
		return y;
}

void printJobSequence(Job arr[], int n)
{
	// Find max slot in the job
	int dmax = 0;	// max value of deadline
	for(int i = 0; i<n; i++)
	{
		dmax = findMax(arr[i].deadline, dmax);
	}
	std::cout<<"Deadline Maximum Value: "<<dmax<<std::endl;
	
	
	// Sort job based on profit (greater profit first then smaller and so on)
	// sort in descending order
	std::sort(arr, arr+n, compare);
	
	int timeSlot[dmax];
	// Create a timeslot array for dmax
	for(int j = 0; j<dmax; j++)
	{
		timeSlot[j] = -1;
	}
	
	int fillTimeSlot = 0;
	int k;
	for(int i = 0; i < n; i++)
	{
		k = minValue(dmax, arr[i].deadline);
		for(int j = k-1; j>=0; j--)
		{
			if(timeSlot[j] == -1)
			{
				timeSlot[j] = i;
				fillTimeSlot++;
				break;
			}
		}
		
		if(fillTimeSlot == dmax)
		{
			break;
		}
	}
	
	// Required Jobs
	for(int i=0; i<dmax; i++)
	{
		std::cout<<arr[timeSlot[i]].id;
		
		if(i<dmax)
			std::cout<<"-->";
	}
	
	int maxProfit = 0;
	for(int j = 0; j<dmax; j++)
	{
		maxProfit += arr[timeSlot[j]].profit;
	}
	std::cout<<"\nMax profit: "<<maxProfit;	
}

int main()
{
	Job arr[] = {
					{"J1", 2, 20}, {"J2", 2, 15}, {"J3", 1, 10}, {"J4", 3, 5}, {"J5", 3, 1},
					/*{"j1", 2,  60},
					{"j2", 1, 100},
					{"j3", 3,  20},
					{"j4", 2,  40},
					{"j5", 1,  20},*/
				};
				
	printJobSequence(arr, 5);
	return 0;
}
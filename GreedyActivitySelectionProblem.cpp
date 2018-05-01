/*	You are given n activities with their start and finish times. 
	Select the maximum number of activities that can be performed 
	by a single person, assuming that a person can only work on a 
	single activity at a time.
*/
#include <iostream>
#include <algorithm>

using namespace std;

struct ActivityTime
{
    int startTime;
    int finishTime;
};

bool activityCompare(ActivityTime s1, ActivityTime s2)
{
    return (s1.finishTime < s2.finishTime);
}

void SelectMaxActivity(ActivityTime arr[], int n)
{
    sort(arr, arr + n, activityCompare);
    
    std::cout<<"\n";	
    std::cout<<"("<<"Start"<<", "<<"Finish"<<"): ";
    int i = 0;	
    std::cout<<"("<<arr[i].startTime<<", "<<arr[i].finishTime<<") ";
	
    for(int j = 1; j<n; j++)
	{
        /*	If activity has start time is greater than or
            equal to the finish time of previously selected finish
            time activity then select it
        */
        if(arr[j].startTime >= arr[i].finishTime)
        {
            std::cout<<"("<<arr[j].startTime << ", "<<arr[j].finishTime<<") ";
            i = j;
        }
    }
}

int main(int argc, char**argv)
{
    ActivityTime arr[] = {{5,9}, {1,2}, {3,4}, {0, 6},
                                       {5, 7}, {8, 9}};
                                       
    int size = sizeof(arr)/sizeof(arr[0]);
    std::cout<<"(Start, Finish): ";
    
    for(int i = 0; i<size; i++)
    {        
        std::cout<<"("<<arr[i].startTime<<", "<<arr[i].finishTime<<") ";
    }
    std::cout<<"\n";    
    SelectMaxActivity(arr, size);

    return 0;
}
/* There are two fuction insert one element push(int value) 
	and resize the size of array resize(int x) without using malloc, realloc
*/
#include <iostream>
using namespace std;

int *arr;
unsigned int count = 0;
unsigned int totalsize = 0;


void push(int x)
{
    if (count == 0)
    {
        arr = new int[1];
        arr[count] = x;
        count++;
    }
    else
    {
        int *tmp = new int[count];
        for(int i=0; i<count; i++)
        {
            tmp[i] = arr[i];
        }
        arr = new int[count+1];
        
        for(unsigned int i = 0; i<count; ++i)
        {
            arr[i] = tmp[i];
        }
        
        arr[count] = x;
        count++;
        delete []tmp;
    }
}

void resize(int size)
{
    int *tmp = new int[count];
    for(int i=0; i<count; i++)
    {
        tmp[i] = arr[i];
    }
       
    arr = new int[count+size];
	    
    int i;
    for(i=0; i<count; i++)
    {
        arr[i] = tmp[i];
    }
    
    for(; i<size; i++)
    {
        arr[i] = 0;
    }
	
    delete []tmp;
}

int main() {
    push(10);
    push(20);
    push(30);
    push(40);
	
    cout<<"Count: "<<count<<endl;
	
    for(int i = 0; i<count; i++)
    {
        cout<<arr[i]<<" ";
    }
	
    int size = 5;
    resize(size);
    cout<<"\nCount: "<<count<<endl;
	
    for(int i = 0; i<count+size; i++)
    {
        cout<<arr[i]<<" ";
    }
}
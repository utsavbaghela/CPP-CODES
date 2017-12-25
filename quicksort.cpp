//============================================================================
// Name        : quicksort.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

void quick_sort(int A[],int low,int high)
{
	if(high>low)
	{
	int z=high;
	int pivot=A[z];
	int i,j;
	i=low,j=low;
	while(i<=high && j<=high)
	{
		if(A[j]<=pivot)
		{
			swap(A[i],A[j]);
			i++;j++;
		}
		else
		{
			j++;
		}
	}
	quick_sort(A,low,i-2);
	quick_sort(A,i,high);
	}

}

int main() {

	int A[8]={8,7,6,5,4,3,2,1};
		quick_sort(A,0,7);
		//merge(A,0,2,5);
		for(int i=0;i<8;i++)
		{
			cout<<A[i]<<" ";
		}

		return 0;

	return 0;
}

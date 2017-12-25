//============================================================================
// Name        : BINARY.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
bool binarysearch(int A[],int low,int high,int n)
{
	while(high>=low)
	{
		int mid=(low+high)/2;
		if(n==A[mid])
		return true;
		if(A[mid]>n)
		high=mid-1;
		else
		low=mid+1;
	}
	return false;
}

int main()
{
	int A[]={1,2,3,4,5,6,7,8,9};
	int n=10;
	if(binarysearch(A,0,8,n))
	{
		cout<<"true";
	}
	else
		cout<<"false";

	return 0;
}

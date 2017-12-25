//============================================================================
// Name        : MERGE.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
void mergesort1(int a[],int low,int high);
void merge1(int a[],int low,int mid , int high);
void mergesort1(int a[],int low,int high)
{
	if(low<high)
	{
		int mid=low+high/2;
		mergesort1(a,0,mid);
		mergesort1(a,mid+1,high);
		merge1(a,low,mid,high);
	}
}

void merge1(int a[],int low, int mid , int high)
{
	int nl=mid-low+1;
	int nr=high-mid;
	int l[nl],r[nr];
	for(int i=0;i<nl;i++)
		l[i]=a[low+i];
	for(int j=0;j<nr;j++)
		r[j]=a[mid+j+1];

	int i=0,j=0,k=low;
	while(i<nl && j<nr)
	{
		if(l[i]>r[j])
		{
			a[k]=l[i];
			i++;k++;
		}
		else
		{
			a[k]=r[j];
			j++;k++;
		}
		while(i<nl)
		{
			a[k]=r[i];
			k++;i++;
		}
		while(i<nr)
		{
			a[k]=r[j];
			k++;i++;
		}


	}
}
int main()
{
	int n;
	int a[10]={9,8,7,6,5,4,3,2,1,0};
	n=sizeof(a)/sizeof(a[0]);
	cout<<"BEFORE SORTING"<<endl;
	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";

	mergesort1(a,0,n-1);

	cout<<endl<<"AFTER SORTING"<<endl;
		for(int i=0;i<n;i++)
			cout<<a[i]<<" ";


	return 0;
}

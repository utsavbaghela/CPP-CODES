
#include <iostream>
#include <stdlib.h>

using namespace std;

void maxheapify(int a[],int i,int n)
{
	int l=2*i+1;
	int r=2*i+2;
	int largest;
	if(l<n && a[l]>a[i])
		largest=l;
	else
		largest=i;
	if(l<n && a[r]>a[i])
		largest=r;
	if(largest!=i)
	{
		int temp=a[i];
		a[i]=a[largest];
		a[largest]=temp;
		maxheapify(a,largest,n);
	}
}

void builtheap(int a[],int n)
{
	for(int i=(n/2-1);i>=0;i--)
		maxheapify(a,i,n);
}

int main() {
	int a[]={10,8,5,3,2,1,7};
	int n=sizeof(a)/sizeof(a[0]);
	cout<<"BEFORE : ";
	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";
	cout<<endl;
	builtheap(a,n);

	cout<<"AFTER  : ";
for(int i=0;i<n;i++)
	cout<<a[i]<<" ";

	return 0;
}


/*



 */

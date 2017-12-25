
#include <iostream>
using namespace std;
void merge(int A[],int low ,int mid,int high)
{
	int i,j,k;
	int l=mid-low+1;
	int r=high-mid;
	int left[l];
	int right[r];
	for(i=0;i<l;i++)
	{
		left[i]=A[low+i];//
	}
	for(i=0;i<r;i++)
	{
		right[i]=A[mid+1+i];
	}
	i=0,k=low,j=0;
	while(i<l && j<r)
	{

		if(left[i]<=right[j])
		{
			A[k]=left[i];
			i++;k++;
		}
		else if(left[i]>right[j])
		{
			A[k]=right[j];
			j++;k++;
		}
	}
	while(i<l)
	{
		A[k]=left[i];
		i++;k++;
	}
	while(j<r)
	{
		A[k]=right[j];
		j++;k++;
	}

}

void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = (l+r)/2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}


int main() {

	int A[9]={8,7,6,5,4,3,2,1,4};
	mergeSort(A,0,8);
	//merge(A,0,2,5);
	for(int i=0;i<8;i++)
	{
		cout<<A[i]<<" ";
	}

	return 0;
}

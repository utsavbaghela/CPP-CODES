#include <iostream>
#include <time.h>
using namespace std;
struct sack{
	float weight;
	float profit;
};



int main()
{
	clock_t t;
	    t = clock();

	int sackweight=10,remainingweight;
	int i, j;
	sack sacks[5] =
	{
			{1,  61},
			{1, 104},
			{1,  37},
			{1,  42},
			{5,  20},
	};
	int n=sizeof(sacks)/sizeof(sacks[0]);
	//cout<<n;
	float pw[5];
	for(int i=0;i<n;i++)
	{
		pw[i]=sacks[i].profit/sacks[i].weight;
	}


	for(int i=n-1;i>=0;i--)
	{
		for(int j=0;j<i;j++){
			if(pw[j]<pw[i])
			{
				sack temp1=sacks[j];
				sacks[j]=sacks[i];
				sacks[i]=temp1;

			}
		}
	}

	for(int i=0;i<n;i++)
			{
				cout<<sacks[i].weight<<" "<<sacks[i].profit<<endl;
			}

	float profit=0,weight=sackweight;
	for(int i=0;i<n;i++)
	{
		if(weight<=0)
			break;
		if(sacks[i].weight<weight)
		{
			profit=profit+sacks[i].profit;
			weight=weight-sacks[i].weight;
		}
		else
		{
			profit=profit+sacks[i].profit*weight/sacks[i].weight;
			weight=weight-sacks[i].weight;
		}
	}
	cout<<"MAX profit : "<<profit<<endl;
	//cout<<"weight :"<<weight<<endl;


	 t = clock() - t;
		    double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
		    cout<<"time taken : "<<time_taken<<endl;

	return 0;
}




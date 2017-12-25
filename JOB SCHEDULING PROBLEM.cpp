
#include <iostream>
using namespace std;
struct job{
	char id[5];
	int deadline;
	int profit;
};
int main()
{
	int i, j;
	job jobs[5] =
	{
			{"j1", 2,  60},
			{"j2", 1, 100},
			{"j3", 3,  20},
			{"j4", 2,  40},
			{"j5", 1,  20},
	};

	job temp;
	int n=sizeof(jobs)/sizeof(jobs[0]);
	//cout<<n;


	for(int i=n-1;i>=0;i--)
	{
		for(int j=0;j<i;j++){
			if(jobs[j].profit<jobs[i].profit)
			{
				job temp1=jobs[j];
				jobs[j]=jobs[i];
				jobs[i]=temp1;

			}
		}
	}
	cout<<"AFTER SORTING:"<<endl;

		for(int j=0;j<5;j++)
		{
			cout<<jobs[j].id<<" "<<jobs[j].deadline<<" "<<jobs[j].profit<<endl;
		}
		cout<<endl;


	//JSP(jobs,n);

	return 0;
}

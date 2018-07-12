
#include <iostream>
using namespace std;

int calmonth(int month,int year)
{
		bool leapyear;
			if(year%4==0)
			{
				leapyear=true;
			}
	int days=0;
	for(int i=1;i<month;i++)
		{

			if(i==2)
			{
				if(leapyear==true)
				{
					days=days+29;
				}
				else
				days=days+28;
				continue;
			}
			if(i==1 ||i==3 ||i==5 ||i==7 || i==8|| i==10 || i==12)
			{
				days=days+31;
				continue;
			}if(i==4 ||i==6 ||i==9 ||i==11 )
			{
				days=days+30;
				continue;
			}
		}
	return days;
}

int calyear(int year)
{
	year=year-1;
	int odddays=0;
	int loopyear=year;
	while(loopyear--)
	{
		if(loopyear%400==0)
		{
			break;
		}
	}
	year=year%loopyear;


	int year1=year;

	int x1=year/100;
	int y1=x1*24;

	year1=year1%100;
	int x2=(year1/4);
	int y2=x2+y1;//96
	int x3=y2*2;//192

	int y3=year-y2;
	y3=y3+x3;
	odddays=y3%7;
	return odddays%7;

}

int main()
{
	int date;
	int month;
	int year;
	cin>>date>>month>>year;

	int ydays=calmonth(month,year);

	int zodddays=calyear(year);

	int odddays=(date+ydays)%7;

	odddays=odddays+zodddays;




	cout<<"ODD DAYS : "<<odddays%7<<endl;
	if(odddays%7==0)
	{
		cout<<"SUNDAY"<<endl;
	}if(odddays%7==1)
	{
		cout<<"MONDAY"<<endl;
	}if(odddays%7==2)
	{
		cout<<"TUESDAY"<<endl;
	}if(odddays%7==3)
	{
		cout<<"WEDNESDAY"<<endl;
	}if(odddays%7==4)
	{
		cout<<"THUSDAY"<<endl;
	}if(odddays%7==5)
	{
		cout<<"FRIDAY"<<endl;
	}if(odddays%7==6)
	{
		cout<<"SATURDAY"<<endl;
	}

	return 0;
}

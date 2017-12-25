#include<iostream>
using namespace std;

int main ()
{
	int t;
	char move,ans;
	char u[4][4]={
			{'1','3','5'},
			{'2','6','4'},
			{'7','0',' '},
	};
	cout<<"    WELCOME TO MY PUZZLE!!!!!"<<endl;
	cout<<"    "
			"_________________________"<<endl<<endl;
		printf("         ENTER MOVE\n");
		printf("       ______________\n");
		printf("          W for Up\n");
		printf("          A for Down\n");
		printf("          D for Right\n");
		printf("          A for Left\n\n");
		cout<<"HERES THE PROBLEM"<<endl;
		cout<<"GO SOLVE IT!!! ALL THE BEST"<<endl<<endl;;
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
			printf("%3c ",u[i][j]);

	printf("\n");
	}
	printf("\n");
	int x=2,y=2;

	int i=0;
	do
	{
		i=0;
	do
	{
		i++;
		int position=u[x][y];
		cin>>move;

		switch (move)
		{
		case 'w':
		    {
		    	if(x-1<0 || x-1>3)
		    	{
		    		cout<<"Wrong move";
		    		continue;
		    	}
		    		t=position;
		    		u[x][y]=u[x-1][y];
		    		u[x-1][y]=t;
		    		x=x-1;
		    		break;
		    }
		case 's':
			{
				if(x+1<0 || x+1>3)
						    	{
						    		cout<<"Wrong move";
						    		continue;
						    	}

				t=position;
				u[x][y]=u[x+1][y];
				u[x+1][y]=t;
				x=x+1;
				break;
			}
		case 'd':
			{
				if(y+1<0 || y+1>3)
						    	{
						    		cout<<"wrong move";
						    		continue;
						    	}

				t=position;
				u[x][y]=u[x][y+1];
				u[x][y+1]=t;
			    y=y+1;
				break;
			}
		case 'a':
			{
				if(y-1<0 || y-1>3)
						    	{
						    		cout<<"wrong move";
						    		continue;
						    	}

				t=position;
				u[x][y]=u[x][y-1];
				u[x][y-1]=t;
				y=y-1;
				break;
			}
		}

		for(int i=0;i<4;i++)
			{
				for(int j=0;j<4;j++)
					printf("%3c ",u[i][j]);

			printf("\n");
			}
	}
	while(i<=5);
	cout<<"SORRY YOU ARE OUT OF MOVES :( :( :( :(!!!!!!"<<endl;
	cout<<"DO YOU WANT TO PLAY AGAIN????(Y/N)"<<endl;
	cin>>ans;
	}
	while(ans=='y');

	cout<<"THANKS FOR PLAYING :) :)"<<endl;

	return 0;

}

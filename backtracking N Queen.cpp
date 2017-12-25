//============================================================================
// Name        : backtracking.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#define N 4
using namespace std;
bool issafe(int sol[N][N],int row,int col)
{

	for (int i = 0; i < col; i++)
	        if (sol[row][i])
	            return false;
	for (int i = 0; i < row; i++)
	        if (sol[i][col])
	            return false;
	int i,j;
		for (i=row, j=col; i>=0 && j>=0; i--, j--)
	        if (sol[i][j])
	            return false;
	    for (i=row, j=col; j>=0 && i<N; i++, j--)
	        if (sol[i][j])
	            return false;
	    for (i=row, j=col; i>=0 && j<N; i--, j++)
	    	        if (sol[i][j])
	    	            return false;
	    for (i=row, j=col; j<N && i<N; i++, j++)
	    	        if (sol[i][j])
	    	            return false;


	return true;

}
void printsol(int sol[N][N])
{
	for(int i=0;i<N;i++)
					{
						for(int j=0;j<N;j++)
						{
							cout<<sol[i][j]<<" ";
						}
						cout<<endl;
					}
				cout<<endl;
}
void clear(int sol[N][N])
{
	for(int i=0;i<N;i++)
		{
			for(int j=0;j<N;j++)
			{
				sol[i][j]=0;
			}
		}
}
bool nqueenutil(int sol[N][N],int level)
{	if (level >= N)
	{
	//printsol(sol);
	return true;
	}

	for(int i=0;i<N;i++)
	{
		if(issafe(sol,level,i)==true)
		{
			sol[level][i]=1;
			if(nqueenutil(sol,level+1)==true)
			{
				if(level==0)
					{
					printsol(sol);
					clear(sol);
					if(i==N-2)////<- BUG IS HERE
						return true;
					continue;
					}

				return true;
			}
		}
		sol[level][i]=0;

	}
	return false;
}

void Nqueen()
{
	int sol[N][N];
	clear(sol);
cout<<"POSSIBLE COMINATIONS FOR QUEEN : "<<endl;
	if(nqueenutil(sol,0)==false)
		cout<<"NO SOLUTION POSSIBLE"<<endl<<endl;



}
int main() {

	Nqueen();
	return 0;
}

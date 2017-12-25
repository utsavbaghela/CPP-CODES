
#include <iostream>
using namespace std;
#define N 8
int i=0;
void printSolution(int sol[N][N])
{
    for (int x = 0; x < N; x++)
    {
        for (int y = 0; y < N; y++)
            printf(" %2d ", sol[x][y]);
        printf("\n");
    }
}
bool issolvable(int x,int y,int sol[][N])
{
	if(x>=0 && x<N*N && y>=0 && y<N*N && sol[x][y]==-1)
		return true;
	else
		return false;
}
bool KTutil(int x,int y,int movei,int sol[N][N],int xmove[],int ymove[])
{
	if(movei==N*N)
		return true;
	for(int k=0;k<8;k++)
	{
		int nextx= x + xmove[k];
		int nexty= y + ymove[k];

		if(issolvable(nextx,nexty,sol)==true)
		{
			sol[nextx][nexty]=movei;
			if(KTutil(nextx,nexty,movei+1,sol,xmove,ymove)==true)
			{
				return true;
			}
			else
				sol[nextx][nexty]=-1;/////->BACKTRACKING
		}
	}
	return false;
}
void KT()
{
	int sol[N][N];
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			sol[i][j]=-1;
		}
	}
	sol[0][5]=0;
	int xmove[8]={1,1,2,2,-1,-1,-2,-2};
	int ymove[8]={-2,2,-1,1,2,-2,-1,1};

	if (KTutil(0, 5, 1, sol, xmove, ymove) == false)
	    {
	        printf("Solution does not exist");
	    }
	    else
	        printSolution(sol);
}


int main() {
	KT();
	return 0;
}

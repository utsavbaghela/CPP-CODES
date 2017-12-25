//============================================================================
// Name        : backtracking.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#define V 5
void printSolution(int color[])
{
	for(int i=0;i<V;i++)
	{
		cout<<color[i]<<" ";
	}
}
bool issafe(int v,bool graph[V][V],int color[],int m,int c)
{
	for(int i=0;i<V;i++)
	{
		if(graph[v][i]==true && c==color[i])
			return false;
	}
	return true;

}
bool graphColoringUtil(bool graph[V][V], int m,int color[], int i)
{
	if(i==V)
		return true;
	for(int c=1;c<=m;c++)
	{
		if(issafe(i,graph,color,m,c))//i=1,c=1
		{
			color[i]=c;
			cout<<"true "<<i <<"->"<<c<<" "<<endl;
			if(graphColoringUtil(graph,m,color,i+1)==true)
			{
				return true;
			}
			color[i]=0;//BACKTRACKING
		}
	}

	return false;
}
void graphColoring(bool graph[V][V],int m)
{
	int color[V];
	for (int i = 0; i < V; i++)
	       color[i] = 0;

	 	    if (graphColoringUtil(graph, m, color, 0) == false)
	 	    {
	 	    		printf("Solution does not exist");
	 	    }

	    printSolution(color);
	    //return true;
}

int main()
{
	bool graph[V][V] = { {0, 1, 0, 0, 1},
	        				{1, 0, 1, 1,1},
						{0, 1, 0, 1,0},
						{0, 1, 1, 0,1},
						{1, 1, 0, 1,0}
						};


	    int m = 3;
	    graphColoring (graph, m);
	    return 0;

	return 0;
}

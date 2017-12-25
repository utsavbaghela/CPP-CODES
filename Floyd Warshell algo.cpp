
#include <iostream>
#include <iomanip>
using namespace std;
int V = 4;
#define INF 99999
void printgraph(int dist[4][4])
{
	cout<<"Shortest distances between every pair of vertices \n";
	cout<<setw(7)<<"0"<<setw(4)<<"1"<<setw(4)<<"2"<<setw(4)<<"3"<<endl;
	cout<<"_____________________"<<endl;
		for(int i=0;i<V;i++)
		{
		cout<<i<<"| ";
			for(int j=0;j<V;j++)
			{
				if (dist[i][j] == INF)
						cout<<setw(4)<<"INF";
						else
							cout<<setw(4)<<dist[i][j];
			}
			cout<<endl;
		}
}
void FW(int graph[4][4])
{
	int dist[4][4],i,k,j;
	for(int i=0;i<V;i++)
	{
		for(int j=0;j<V;j++)
		{
			dist[i][j]=graph[i][j];
		}
	}
	for (k = 0; k < V; k++)
	    {

	        for (i = 0; i < V; i++)
	        {

	            for (j = 0; j < V; j++)
	            {

	                if (dist[i][k] + dist[k][j] < dist[i][j])
	                    dist[i][j] = dist[i][k] + dist[k][j];
	            }
	        }
	    }
	printgraph(dist);

}

	int main()
	{

		int graph[4][4] = { {0,   5,  INF, 10},
		                        {INF, 0,   3, INF},
		                        {INF, INF, 0,   1},
		                        {INF, INF, INF, 0}
		                      };


	    // Print the solution
	   FW(graph);

	    return 0;
	}



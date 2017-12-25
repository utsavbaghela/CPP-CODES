
#include <iostream>
using namespace std;

class graph
{
	int cap,rear,front;
	bool visited[100];
	int queue[100];

public:
	graph(int n)
	{
		cap=20;
		rear=front=-1;
		for(int i=0;i<n;i++)
		{
			visited[i]=false;
		}
	}
	void enqueue(int x)
	{
		rear=(rear+1)%cap;
		queue[rear]=x;
	}
	int dequeue()
	{
		int x=queue[front];
		front=(front+1)%cap;
		return x;
	}

	void BFS(int G[][5],int n,int s)
	{
		visited[s]=true;
		enqueue(s);
		cout<<s<<" ";
		while(front<=rear)
		{
			int v=dequeue();
			//cout<<v<<" ";
			for(int i=0;i<n;i++)
			{
				//cout<<"utsav"<<endl;
				if(G[v][i]==1 && visited[i]==false)
				{
					cout<<i<<" ";
					enqueue(i);
					visited[i]=true;
				}
			}
		}
	}


};
int main()
{

	int n=5;
	graph g(n);
	int G[5][5] = 		{ {0, 1, 0, 1,0},
	                      {1, 0, 1, 0,0},
	                      {0, 1, 0, 1,1},
	                      {1, 0, 1, 0,1},
						  {0, 0, 1, 1,0},
	                     };
	g.BFS(G,n,0);
	return 0;
}

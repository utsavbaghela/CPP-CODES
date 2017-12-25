
#include <iostream>
using namespace std;
# define V 5
int flag=0;
	struct node
	{
		int number;
		int weight;
		node* next;
	};
	struct arr
	{
		node * head;
	};

class graph
{

		int totaledge;
	int dist[20];
	//int new1[20];
	int visited[20];
	int number;
		int data;
	struct arr* a;
public:
	graph(int v,int n)
	        {
					totaledge=0;
					number=n;
			        data = v;
	            a = new arr[v];
	            for (int i = 0; i < v; ++i)
	                a[i].head = NULL;
	            for(int i=0;i<20;i++)
	            		visited[i]=0;
	        }

	void addEdge(int src,int des,int weight)
	{
		totaledge++;
		node* newnode= new node;
		newnode->number=des;
		newnode->weight=weight;
		newnode->next=a[src].head;
		a[src].head=newnode;

		return;
	}

	void printgraph()
	{
					int i;
					cout<<"FOR GRAPH : "<<number<<endl;
					cout<<"TOTAL NUMBER OF EDGES: "<<totaledge<<endl;
			        for (i = 0; i < data; ++i)
			        {
			            node* pCrawl = a[i].head;
			            cout<<endl<<"|"<< i<<"|";
			            while (pCrawl)
			            {
			                cout<<"->"<< pCrawl->number<<"("<<pCrawl->weight<<")";
			                pCrawl = pCrawl->next;
			            }
			            //cout<<endl;
			        }
			        cout<<endl;
			        cout<<"_______________________"<<endl<<endl<<endl;
	}

	void bellmanford()
	{
		for(int i=0;i<V;i++)
		{
			dist[i]=INT_MAX;
			//new1[i]=INT_MAX;
			visited[i]=0;
		}
		dist[0]=0;
		//new1[0]=0;
		for(int u=0;u<V-1;u++)
		{
			for(int v=0;v<V;v++)
			{
				struct node* temp=a[v].head;
				while(temp!=NULL)
				{
					int src=v;
					int dest=temp->number;
					int weight=temp->weight;
					int s=dist[src]+weight;

					if(dist[src]!=INT_MAX && s <dist[dest])
					dist[dest]=s;

						temp=temp->next;
				}
				display();
				cout<<endl;
			}
			//cout<<endl;

			/*cout<<"dist :"<<endl;
						for(int i=0;i<V;i++)
						cout<<dist[i]<<" ";
						cout<<endl;
						cout<<"new1 :"<<endl;
						for(int i=0;i<V;i++)
						cout<<new1[i]<<" ";
						cout<<endl;*/
		}
		for(int v=0;v<V;v++)
					{
						struct node* temp=a[v].head;
						while(temp!=NULL)
						{
							int src=v;
							int dest=temp->number;
							int weight=temp->weight;
							if(dist[src]!=INT_MAX)
							{
							int s=dist[src]+weight;
							if(s <dist[dest])
							{
								flag=1;
							}
							}

							temp=temp->next;
						}
					}


	}

	void display()
	{
		for(int i=0;i<V;i++)
		{
			cout<<"vertex "<<i<< "  : "<<dist[i]<<endl<<endl;
		}
	}



};

int main()
{

		int v=5;
		graph g(v,1);
			g.addEdge(0, 1, 6);
		    g.addEdge(0, 2, 7);
		    g.addEdge(1,2,8);
		    g.addEdge(1,3,5);
		    g.addEdge(1,4,-4);
		    g.addEdge(2,3,-3);
		    g.addEdge(2,4,9);
		    g.addEdge(3,1,-2);
		    g.addEdge(4,3,7);
		/* g.addEdge(0, 1, 1);
		 g.addEdge(1, 2, 2);
		 g.addEdge(2, 1, -3);*/
		    	g.printgraph();
		    	g.bellmanford();
		    	g.display();
		    	if(flag==1)
		    cout<<"YES!!!!Graph contains negative weight cycle"<<endl;
		    else
		    cout<<"NO !!!! Graph does not contain negative weight cycle"<<endl;

	return 0;
}

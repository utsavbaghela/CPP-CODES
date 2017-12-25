
#include <iostream>
using namespace std;
# define V 5
int flag=0;
	struct node
	{
		int value;
		node* next;
	};
	struct arr
	{
		node * head;
	};

class graph
{
	int visited[20];
	int cap;
	bool initial[V];
	bool rs[V];
	bool dead[V];
	int number;
	int data;
	struct arr* a;
public:
	graph(int v,int n)
	        {

				cap=20;
				number=n;
	            data = v;
	            for(int i=0;i<V;i++)
	            			{
	            				initial[i]=true;
	            				rs[i]=false;
	            				dead[i]=false;
	            			}
	            a = new arr[v];
	            for (int i = 0; i < v; ++i)
	                a[i].head = NULL;
	            for(int i=0;i<20;i++)
	            		visited[i]=0;
	        }

	void addEdge(int src,int des)
	{
		node* newnode= new node;
		newnode->value=des;
		newnode->next=a[src].head;
		a[src].head=newnode;

		return;
	}

	void printgraph()
	{
					int i;
					cout<<"FOR GRAPH : "<<number<<endl;
			        for (i = 0; i < data; ++i)
			        {
			            node* pCrawl = a[i].head;
			            cout<<endl<<"|"<< i<<"|";
			            while (pCrawl)
			            {
			                cout<<"->"<< pCrawl->value;
			                pCrawl = pCrawl->next;
			            }
			            //cout<<endl;
			        }
			        cout<<endl;
			        cout<<"_______________________"<<endl<<endl<<endl;
	}

	void iscyclic(int src)
	{
		for(int i=0;i<V;i++)
		{
			if(initial[i]==true)
			{
				DFS(0);
			}
		}
	}

	void DFS(int v)
	{
		initial[v]=false;
				rs[v]=true;
		cout<<"CURRENT NODE : "<< v <<endl;
		display();
		node* temp=a[v].head;
		if(temp!=NULL)
		{	cout<<"temp->value : "<<temp->value;  }
			cout<<endl<<endl<<endl;
		if(temp==NULL)
		{
			dead[v]=true;
			rs[v]=false;
		}

		while(temp!=NULL)
		{

			if(rs[temp->value]==true)
				{//cout<<"GRAPH HAS CYCLE"<<endl;
				flag++;
				}
			else if(initial[temp->value]==true)
				DFS(temp->value);


			temp=temp->next;
		}
		dead[v]=true;
		rs[v]=false;

	}
	void display()
	{

		cout<<"initial  : "<<endl;
				for(int i=0;i<V;i++)
				{
					 cout<<initial[i]<<" ";
				}
				cout<<endl;
				cout<<"RS  : "<<endl;
						for(int i=0;i<V;i++)
						{
							 cout<<rs[i]<<" ";
						}
						cout<<endl;
						cout<<"dead  : "<<endl;
								for(int i=0;i<V;i++)
								{
									 cout<<dead[i]<<" ";
								}
								cout<<endl;

	}
};

int main()
{

		int v=5;
		graph g(v,1);
			g.addEdge(0, 1);
		    g.addEdge(1, 2);
		    g.addEdge(2, 3);
		    g.addEdge(2, 4);
		    g.addEdge(3, 4);
		    g.addEdge(3, 0);
		    	g.printgraph();
		    	g.iscyclic(0);
		    	cout<<flag<<endl;
		    	cout<<endl<<endl;
		    			cout<<"FINAL : "<<endl;
		    			cout<<"--------"<<endl;
		    	g.display();
		    	cout<<endl<<"RESULT  : "<<endl;
		    	if(flag==0)
		    	{
		    		cout<<"GRAPH HAS NO CYCLE "<<endl;
		    	}
		    	else
		    		cout<<"GRAPH HAS CYCLE";




	return 0;
}

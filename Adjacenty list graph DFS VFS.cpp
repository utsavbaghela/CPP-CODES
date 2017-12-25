
#include <iostream>
using namespace std;

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
		int queue[20];
		int front;
		int rear;
	int number;
	int data;
	struct arr* a;
public:
	graph(int v,int n)
	        {
				cap=20;
				front=0;
				rear=front-1;
				number=n;
	            data = v;
	            a = new arr[v];
	            for (int i = 0; i < v; ++i)
	                a[i].head = NULL;
	            for(int i=0;i<20;i++)
	            		visited[i]=0;
	        }
	void enqueue(int item)
	{
		rear=(rear+1)%cap;
		queue[rear]=item;
	}
	int dequeue()
	{
		int item=queue[front];
		front=(front+1)%cap;
		return item;
	}
	void addEdge(int src,int des)
	{
		node* newnode= new node;
		newnode->value=des;
		newnode->next=NULL;

		newnode->next=a[src].head;
		a[src].head=newnode;

		node* newnode1=new node;
		newnode1->value=src;
		newnode1->next=NULL;

		newnode1->next=a[des].head;
		a[des].head=newnode1;

	}

	void printgraph()
	{
					int i;
					cout<<"FOR GRAPH : "<<number<<endl;
					cout<<"Adjacency list of vertex"<<endl;
			        for (i = 0; i < data; ++i)
			        {
			            node* pCrawl = a[i].head;

			            cout<<"| "<<i<<" |";

			            while (pCrawl)
			            {
			                cout<<"->"<< pCrawl->value;
			                pCrawl = pCrawl->next;
			            }
			            cout<<endl;


			        }
			        cout<<endl;
			        cout<<"_______________________"<<endl<<endl;
	}

	void BFT(int s)
	{
		//cout<<"UTSAV";
		visited[s]=1;
		enqueue(s);

		while(front<=rear)
		{
			int v=dequeue();
			cout<<v<<" ";
			node *temp;
			temp=a[v].head;
			while(temp!=NULL)
			{
				//cout<<v<<" ";
				if(visited[temp->value]==0)
				{
					enqueue(temp->value);
					visited[temp->value]=1;
				}
				temp=temp->next;

			}
		}
		cout<<endl;
		for(int i=0;i<20;i++)
			visited[i]=0;
	}
	void DFT(int s)
	{
		cout<<s<<" ";
		visited[s]=1;
		node*temp;
		temp=a[s].head;
		while(temp!=NULL)
		{

			if(visited[temp->value]==0)
			{
				DFT(temp->value);
			}

			temp=temp->next;
		}
	}
};


int main()
{

		int v=6;
		graph g(v,1);
			g.addEdge(0, 5);
			g.addEdge(0, 1);
		    g.addEdge(1, 3);
		    g.addEdge(1, 4);
		    g.addEdge(3, 4);
		    g.addEdge(2, 4);
		    g.printgraph();
		    cout<<"BFT IS : ";
		    g.BFT(0);
		    cout<<"DFT IS : ";
		    g.DFT(0);




	return 0;
}

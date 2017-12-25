
#include <iostream>
#define INT_MAX 9999999;
using namespace std;

struct node
	{
		long int number;
		long int weight;
		node* next;
	};
struct key
{
	long int weight;
	long int vertexno;
};
struct arr{
	node* head;
};
long int totaledge=0;
long int heapsize=0;
void graph(long int n,struct arr* a,bool visited[])
{
	for(long int i=0;i<n;i++)
	{
		a[i].head=NULL;
		visited[i]=false;
	}
}
void addedge(struct arr* a,long int n,long int s,long int d,long int w)
{
	totaledge++;
			node* newnode= new node;
			newnode->number=d;
			newnode->weight=w;
			newnode->next=a[s].head;
			a[s].head=newnode;

			node* newnode1= new node;
						newnode1->number=s;
						newnode1->weight=w;
						newnode1->next=a[d].head;
						a[d].head=newnode1;

}
void printgraph(arr* a,long int n)
	{
					long int i;

					cout<<"TOTAL NUMBER OF EDGES: "<<totaledge<<endl;
			        for (i = 0; i < n; ++i)
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
void minheapify(struct key a[],long int i,long int n,long int pos[])
{
	long int l=2*i+1;
	long int r=2*i+2;
	long int smallest=i;
	if(l<n && a[l].weight<a[i].weight)
		smallest=l;
		if(l<n && a[r].weight<a[i].weight)
		smallest=r;
	if(smallest!=i)
	{
		pos[a[smallest].vertexno] = i;
		pos[a[i].vertexno]=smallest  ;
		struct key temp=a[i];
		a[i]=a[smallest];
		a[smallest]=temp;
		minheapify(a,smallest,n,pos);
	}
}
long int extractmin(struct key a[],long int pos[],long int s)
{
	struct key root=a[0];
	struct key last=a[heapsize-1];
	long int min=root.vertexno;
	a[0]=last;
	pos[root.vertexno]=heapsize-1;
	pos[last.vertexno]=0;
	heapsize--;
	minheapify(a,0,heapsize,pos);
	return min;
}
void decreasekey(struct key key[],long int v, long int newvalue,long int pos[])
{
	long int i=pos[v];
	key[i].weight=newvalue;
	while (i && key[i].weight < key[(i - 1) / 2].weight)
	    {
	        pos[key[i].vertexno] = (i-1)/2;
	        pos[key[(i-1)/2].vertexno] = i;
	        swap(key[i],  key[(i - 1) / 2]);

	        i = (i - 1) / 2;
	    }

}
bool isInMinHeap(long int v,long int pos[])
{
	if(pos[v] < heapsize)
     return true;

   return false;
}
void DIJKSTRA(struct arr* a,long int n,long int pos[],long int s,bool visited[],int x,int k)
{


	struct key key[n];
	long int key1[n];
	if(s-1<=k)
	{
	for(long int i=0;i<k;i++)
			{
			pos[i]=i;
			key[i].weight=x;
			key[i].vertexno=i;
			key1[i]=x;
			}
	for(long int i=k;i<n;i++)
				{
				pos[i]=i;
				key[i].weight=INT_MAX;
				key[i].vertexno=i;
				key1[i]=INT_MAX;
				}
	}
	else
	{
		for(long int i=0;i<n;i++)
						{
						pos[i]=i;
						key[i].weight=INT_MAX;
						key[i].vertexno=i;
						key1[i]=INT_MAX;
						}

	}
		key[s-1].weight=0;
		key1[s-1]=0;
		//cout<<heapsize<<endl;
		decreasekey(key,s-1,0,pos);
		/*for(long int i=0;i<n;i++)
					{
					cout<<key[i].weight<< " ";
					cout<<key[i].vertexno<<endl;
					}*/

		while(heapsize!=0)
		{

			long int u=extractmin(key,pos,s);
			//cout<<endl<<" u : "<<u<<endl;
			//visited[u]=true;
			//cout<<" kEY : "<<endl;
			//for(int i=0;i<n;i++)
		//	{
				//cout<<key1[i]<<" ";
			//}
			//cout<<endl;

			struct node* temp=a[u].head;
			while(temp!=NULL)
			{
			//cout<<"temp number: "<<temp->number<<endl;
			//cout<<"key1[u] : "<<key1[u]<<endl;
			long int c=key1[u]+ temp->weight;
			//cout<<"key1[u] "<<key1[u]<<endl;
			//cout<<" c: "<<c<<" "<<endl;

			if( isInMinHeap(temp->number,pos)==true && c<key1[temp->number] )
			{
				key1[temp->number]=c;
				//cout<<" chosen : "<<temp->number<<endl;
				decreasekey(key,temp->number,c,pos);
				//minheapify(key,0,n,pos);

			}
			temp=temp->next;
			}
		}

		for (long int i = 0; i < n; i++)
		{
		 cout<<key1[i]<<" ";
		}
		cout<<endl;
}



int main()
{
	long int t;
	cin>>t;
	while(t--)
	{
		long int n,k,x,m,s;
		cin>>n>>k>>x>>m>>s;
		heapsize=n;
		bool visited[n];

			long int position[n];
			struct arr* a=new arr[n];
			graph(n,a,visited);

			/*for(long int i=0;i<k;i++)
			{

				for(long int j=i;j<k;j++)
				{
					if(i==j)
						continue;
					addedge(a,n,i,j,x);

				}
			}*/


			//printgraph(a,n);
		for(long int i=0;i<m;i++)
		{
			long int c1,c2,wt;
			cin>>c1>>c2>>wt;
			addedge(a,n,c1-1,c2-1,wt);
		}
		//printgraph(a,n);

		DIJKSTRA(a,n,position,s,visited,x,k);
	}


	return 0;
}

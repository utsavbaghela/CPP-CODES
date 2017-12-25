
#include <iostream>
using namespace std;
int V = 5;
int heapsize=V;
int pos[5];
int key1[5];
struct key
{
	int weight;
	int vertexno;
};
void minheapify(struct key a[],int i,int n)
{
	int l=2*i+1;
	int r=2*i+2;
	int smallest=i;
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
		minheapify(a,smallest,n);
	}
}
int extractmin(struct key a[])
{
	struct key root=a[0];
	struct key last=a[heapsize-1];
	int min=root.vertexno;
	a[0]=last;
	pos[root.vertexno]=heapsize-1;
	pos[last.vertexno]=0;
	--heapsize;
	minheapify(a,0,heapsize);
	return min;
}
void decreasekey(struct key key[],int v, int newvalue)
{
	int i=pos[v];
	key[i].weight=newvalue;
	while (i && key[i].weight < key[(i - 1) / 2].weight)
	    {
	        pos[key[i].vertexno] = (i-1)/2;
	        pos[key[(i-1)/2].vertexno] = i;
	        swap(key[i],  key[(i - 1) / 2]);

	        i = (i - 1) / 2;
	    }

}
void printMST(int parent[], int n, int graph[5][5])
{
   printf("Edge   Weight\n");
   for (int i = 1; i < n; i++)
      printf("%d - %d    %d \n", parent[i], i, graph[i][parent[i]]);
}
bool isInMinHeap(int v)
{
	if(pos[v] <= heapsize)
     return true;

   return false;
}
void primMST(int graph[5][5])
{

	struct key key[V];
	int parent[V];
	for(int i=0;i<V;i++)
		{
		pos[i]=i;
		key[i].weight=INT_MAX;
		key[i].vertexno=i;
		key1[i]=INT_MAX;
		}
	key[0].weight=0;
	key1[0]=0;

	while(heapsize!=0)
	{

		int u=extractmin(key);
		cout<<"MIN : "<<u<<endl;
		cout<<"heapsize :"<<heapsize<<endl;
		cout<<"POSITION : ";
		for(int i=0;i<V;i++)
			cout<<pos[i]<<" ";

		cout<<endl;

		for(int v=0;v<V;v++)
		{
			if(isInMinHeap(v)==true && graph[u][v]!=0 && key1[v]>graph[u][v])
				{
				parent[v]=u;
				key1[v]=graph[u][v];
				decreasekey(key,v,key1[v]);
				}
		}


	}
	printMST(parent, V, graph);

}
	int main()
	{
	   /* Let us create the following graph
	          1    9
	      (0)--(1)--(2)
	       |   / \   |
	      3| 8/   \2 |3
	       | /     \ |
	      (3)-------(4)
	            3
	                     */
	   int graph[5][5] = {{0, 1, 0, 3, 0},
	                      {1, 0, 9, 8, 2},
	                      {0, 9, 0, 0, 3},
	                      {3, 8, 0, 0, 3},
	                      {0, 2, 3, 3, 0},
	                     };



	    // Print the solution
	    primMST(graph);

	    return 0;
	}

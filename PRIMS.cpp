//============================================================================
// Name        : PRIMS.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
int V =5;
int heapsize=V;
struct key
{
	int weight;
	int vertexno;
};
void minheapify(struct key a[],int i,int n)
{
	int l=2*i+1;
	int r=2*i+2;
	int smallest;
	if(l<=n && a[l].weight<a[i].weight)
		smallest=l;
	else
		smallest=i;
	if(l<=n && a[r].weight<a[i].weight)
		smallest=r;
	if(smallest!=i)
	{
		struct key temp=a[i];
		a[i]=a[smallest];
		a[smallest]=temp;
		minheapify(a,smallest,n);
	}
}

int extractmin(struct key a[],int n )
{
	int min=a[0].vertexno;
	//cout<<":::::"<<a[0].vertexno<<endl;
	a[0]=a[heapsize-1];
	heapsize--;
	//minheapify(a,1,n);
	return min;

}


void printMST(int parent[], int n, int graph[5][5])
{
   printf("Edge   Weight\n");
   for (int i = 1; i < n; i++)
      printf("%d - %d    %d \n", parent[i], i, graph[i][parent[i]]);
}

void primMST(int graph[5][5])
{
	int parent[V];
	struct key key[V];
	struct key q[V];

			for (int i = 0; i < V; i++)
			{
			key[i].weight = INT_MAX;
			key[i].vertexno = i;
			}

     key[0].weight = 0;


     parent[0]=0;
     while(heapsize!=0)
     {

    	 int u=extractmin(key,V);
    	 cout<<"min: "<<u<<endl;
    	 for (int v = 0; v < V; v++)
    	 {
    	           if (graph[u][v]!=0 && graph[u][v] < key[v].weight)
    	           {
    	        	   parent[v]  = u;
    	        	   key[v].weight=graph[u][v];
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

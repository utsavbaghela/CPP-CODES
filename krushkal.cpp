

#include <iostream>
using namespace std;
struct edge{
	int src,dest,weight;
};
struct graph{
	int V,E;
	struct edge* edgearr;
};
struct subset{
	int parent;
	int rank;
};

graph *creategraph(int v,int e)
{
	struct graph* graph = (struct graph*) malloc( sizeof(struct graph) );
	//struct graph *graph = new (struct graph*) (sizeof(graph));
	graph->V=v;
	graph->E=e;
	graph->edgearr = (struct edge*) malloc( e * sizeof( struct edge ) );
	//graph->edgearr=new (struct edge*) (e*sizeof(struct edge));
	return graph;
}

int find(struct subset subsets[],int i)
{
	if(subsets[i].parent==i)
		return i;
	else
		subsets[i].parent= find(subsets,subsets[i].parent);

	return subsets[i].parent;

}
void union1(struct subset subsets[],int x,int y)
{
	int xroot=find(subsets,x);
	int yroot=find(subsets,y);
	if(subsets[xroot].rank<subsets[yroot].rank)
		subsets[xroot].parent=yroot;
	else if(subsets[xroot].rank>subsets[xroot].rank)
		subsets[yroot].parent=xroot;
	else
	{
		subsets[yroot].parent=xroot;
		subsets[xroot].rank++;
	}

}
int mycomp(const void *a,const void *b)
{
	struct edge* a1=(struct edge*) a;
	struct edge* b1=(struct edge*) b;
	return (a1->weight > b1->weight);

}
void krushkal(struct graph* graph)
{
	qsort(graph->edgearr , graph->E , sizeof(graph->edgearr[0]), mycomp);
	int e=0,i=0,V=graph->V;
	struct edge result[V];
	struct subset *subsets =
	        (struct subset*) malloc( V * sizeof(struct subset) );

	for (int v = 0; v < V; ++v)
	    {
	        subsets[v].parent = v;
	        subsets[v].rank = 0;
	    }
	while(e<V-1)
	{
		struct edge temp=graph->edgearr[i++];
		int x=find(subsets,temp.src);
		int y=find(subsets,temp.dest);
		if(x!=y)
		{
			result[e++]=temp;
			union1(subsets,x,y);
		}


	}
for(int i=0;i<=e;i++)
	cout<<result[i].src<<" "<<result[i].dest<<" "<<result[i].weight;
return;


}


int main()
{
	int V=4,E=5;
	struct graph* graph=creategraph(V,E);
	graph->edgearr[0].src=0;
	graph->edgearr[0].dest=1;
	graph->edgearr[0].weight=10;

	graph->edgearr[0].src=0;
	graph->edgearr[0].dest=1;
	graph->edgearr[0].weight=10;

	graph->edgearr[0].src=0;
	graph->edgearr[0].dest=1;
	graph->edgearr[0].weight=10;

	graph->edgearr[0].src=0;
	graph->edgearr[0].dest=1;
	graph->edgearr[0].weight=10;

	krushkal(graph);
	return 0;


}

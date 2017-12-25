

#include <stdio.h>
#include <stdlib.h>

struct node
{
	int value;
	struct node* next;
};
struct array
{
	struct node * head;
};
struct graph
{
	int data;
	struct array* a;
};

void addEdge(struct graph* graph,int src,int des)
{
	struct node* newnode=(struct node*)malloc(sizeof(struct node));
	newnode->value=des;
	newnode->next=graph->a[src].head;
	graph->a[src].head=newnode;

	struct node* newnode1=(struct node*)malloc(sizeof(struct node));
	newnode1->next=graph->a[des].head;
	graph->a[des].head=newnode1;

}



int main(void)

{
	int v=5;
	struct graph* graph;
	graph->data=v;//5
	graph->a=(struct array*) malloc(v * sizeof(struct array));

	for(int i=0;i<v;i++)
	{
		graph->a[i].head=NULL;
	}

		addEdge(graph, 0, 1);
	    addEdge(graph, 0, 4);
	    addEdge(graph, 1, 2);
	    addEdge(graph, 1, 3);
	    addEdge(graph, 1, 4);
	    addEdge(graph, 2, 3);
	    addEdge(graph, 3, 4);

	    int i;
	        for (i = 0; i < 5; ++i)
	        {
	            struct node* pCrawl = graph->a[i].head;
	            printf("\n Adjacency list of vertex %d\n head ", i);
	            while (pCrawl)
	            {
	                printf("-> %d", pCrawl->value);
	                pCrawl = pCrawl->next;
	            }
	            printf("\n");
	        }
	return 0;
}

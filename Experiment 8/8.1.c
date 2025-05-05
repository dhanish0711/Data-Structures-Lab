// Implementation of directed graph and its operations using adjacent lists.

//GraphMain3.c
#include<stdio.h>
#include<stdlib.h>
#include "GraphsAdjacencyListDirectedGraph.c" 

void main() {
	int x, op;
	int N,E,s,d,i,j;
	GNODE p,q;
	printf("Enter the number of vertices : ");
	scanf("%d",&N);
	printf("Enter the number of edges : ");
	scanf("%d",&E);
	for(i=1;i<=E;i++) {
		printf("Enter source : ");
		scanf("%d",&s);
		printf("Enter destination : ");
		scanf("%d",&d);
		q=(GNODE)malloc(sizeof(struct node));
		q->vertex=d;
		q->next=NULL;
		if(graph[s]==NULL)
			graph[s]=q;
		else {
			p=graph[s];
			while(p->next!=NULL)
				p=p->next;
			p->next=q;
		}
	}
	while(1) {
		printf("1.Insert vertex 2.Insert edge 3.Delete vertex 4.Delete edge 5.Print adjacency list 6.Exit\n");
		printf("Enter your option : ");
		scanf("%d", &op);
		switch(op) {
			case 1:	
					insertVertex(&N);
					break;
			case 2:
					insertEdge(&N);
					break;
			case 3: 
					deleteVertex(&N);
					break;
			case 4:
					deleteEdge(&N);
					break;
			case 5:
					print(&N);
					break;
			case 6:
					exit(0);
		}
	}
}

// GraphsAdjacencyListDirectedGraph.c
struct node {
	struct node *next;
	int vertex;
};
typedef struct node *GNODE;
GNODE graph[20];

void print(int *N) {
	for (int i = 1; i <= *N; i++) {
		if (graph[i] != NULL) {
			printf("%d=>", i);
			GNODE temp = graph[i];
			while (temp != NULL) {
				printf("%d\t", temp->vertex);
				temp = temp->next;
			}
		printf("\n");
		}
	}
}

void insertVertex(int * N) {
	(*N)++;
	printf("After inserting vertex the adjacency list is : \n");
	print(N);
}

void insertEdge(int *N) {
	int source, destination;
	printf("Enter the source vertex of the edge : ");
	scanf("%d", &source);
	printf("Enter the destination vertex of the edge : ");
	scanf("%d", &destination);
	if (source <= *N && destination <= *N) {
		GNODE q = (GNODE)malloc(sizeof(struct node));
		q->vertex = destination;
		q->next = NULL;
		if (graph[source] == NULL) {
			graph[source] = q;
		} else {
			GNODE p = graph[source];
			while (p->next != NULL) {
				p = p->next;
			}
			p->next = q;
		}
		printf("After inserting edge the adjacency list is : \n");
		print(N);
	} else {
		printf("Invalid vertices.\n");
	}
}

void deleteVertex(int *N) {
	int vertex;
	printf("Enter the vertex to be deleted : ");
	scanf("%d", &vertex);
	if (vertex <= *N) {
		for (int i = 1; i <= *N; i++) {
			GNODE p = graph[i], prev = NULL;
			while (p != NULL) {
				if (p->vertex == vertex) {
					if (prev == NULL) {
						graph[i] = p->next;
						free(p);
						p = graph[i];
					} else {
						prev->next = p->next;
						free(p);
						p = prev->next;
					}
				} else {
					prev = p;
					p = p->next;
				}
			}
		}
		GNODE temp = graph[vertex];
		while (temp != NULL) {
			GNODE toDelete = temp;
			temp = temp->next;
			free(toDelete);
		}
		for (int i = vertex; i < *N; i++) {
			graph[i] = graph[i + 1];
		}
		graph[*N] = NULL;
		for (int i = 1; i < *N; i++) {
			GNODE p = graph[i];
			while (p != NULL) {
				if (p->vertex > vertex)
					p->vertex--;
				p = p->next;
			}
		}
		(*N)--;
		printf("After deleting vertex the adjacency list is : \n");
		print(N);
	} else {
		printf("Invalid vertex.\n");
	}
}

void deleteEdge(int *N) {
	int source, destination;
	printf("Enter the source vertex of the edge : ");
	scanf("%d", &source);
	printf("Enter the destination vertex of the edge : ");
	scanf("%d", &destination);
	if (source <= *N && destination <= *N) {
		GNODE p = graph[source], prev = NULL;
		while (p != NULL) {
			if (p->vertex == destination) {
				if (prev == NULL) {
					graph[source] = p->next;
				} else {
					prev->next = p->next;
				}
				free(p);
				break;
			}
			prev = p;
			p = p->next;
		}
		printf("After deleting edge the adjacency list is : \n");
		print(N);
	} else {
		printf("Invalid vertices.\n");
	}
}

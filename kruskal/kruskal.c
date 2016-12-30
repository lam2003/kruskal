#include <malloc.h>
#include "kruskal.h"
#include "quickSort.h"
#include <time.h>
#include <stdio.h>
static int find(int *parent, int f)
{
	while (parent[f] > 0)
	{
		f = parent[f];
	}
	return f;
}

void kruskal(int graph[20][20], int n)
{
	int edgeNum = 0;
	int i = 0, j = 0, k = 0;
	int a = 0, b = 0;
	for (int i = n - 1; i > 0; i--)
	{
		edgeNum += i;
	}
	TEdge *edges = (TEdge *)malloc(sizeof(TEdge)*edgeNum);
	int *parent = (int *)malloc(sizeof(int)*edgeNum);
	for (i = 0; i < n-1; i++)
	{
		for (j = i+1; j < n; j++)
		{
			edges[k].start = i;
			edges[k].end = j;
			edges[k].weight = graph[i][j];
			k++;
		}
	}

	quickSort(edges, k);
	for (i = 0; i < k; i++)
	{
		parent[i] = 0;
	}
	for (i = 0; i < k; i++)
	{
		a = find(parent, edges[i].start);
		b = find(parent, edges[i].end);
		if (a != b)
		{
			parent[a] = b;
			printf("(%d,%d)%d\n", edges[i].start, edges[i].end, edges[i].weight);
		}
	}
	free(edges);
	free(parent);
}
int main()
{
	int graph[20][20];

	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			graph[i][j] = -1;
		}
	}
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			if (graph[i][j] < 0)
			{
				if (i == j)
				{
					graph[j][i] = graph[i][j] = 0;
					continue;
				}
				graph[i][j] = rand() % 20;
				if (graph[i][j] == 0)
				{
					graph[i][j]++;
				}
				graph[j][i] = graph[i][j];
			}

		}
	}
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			printf("%d\t", graph[i][j]);
			if ((j + 1) % 6 == 0)
			{
				printf("\n");
			}
		}
	}
	kruskal(graph, 6);
}
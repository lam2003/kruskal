#include <malloc.h>
#include <time.h>
#include <stdio.h>
#include "kruskal.h"
#include "quickSort.h"
#define MAX 65535
static int find(int *son, int f)
{
	while (son[f] > 0)
	{
		f = son[f];
	}
	return f;
}





void prim(int **graph, int n, int sv)
{
	int *parent = (int *)malloc(sizeof(n));
	int *v = (int *)malloc(sizeof(n));
	int *cost = (int *)malloc(sizeof(n));
	int i = 0, j = 0;
	for (i = 0; i < n; i++)
	{
		cost[i] = graph[sv][i];
		parent[i] = sv;
		v[i] = 0;
	}
	v[sv] = 1;
	for (i = 0; i < n; i++)
	{
		int min = MAX;
		int index = -1;
		for (j = 0; j < n; j++)
		{
			if (!v[j] && cost[j] < min)
			{
				index = j;
				min = cost[j];
			}
		}
		if (index != -1)
		{
			v[index] = 1;
			printf("(%d,%d)\t%d\n", parent[index], index, cost[index]);
		}
		for (j = 0; j < n; j++)
		{
			if (!v[j] && graph[index][j] < cost[j])
			{
				cost[j] = graph[index][j];
				parent[j] = index;
			}
		}
	}
	
}





void kruskal(int **graph, int n)
{
	int edgeNum = 0;
	int i = 0, j = 0, k = 0;
	int a = 0, b = 0;
	for (int i = n - 1; i > 0; i--)
	{
		edgeNum += i;
	}
	TEdge *edges = (TEdge *)malloc(sizeof(TEdge)*edgeNum);
	int *son = (int *)malloc(sizeof(int)*edgeNum);
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
		son[i] = 0;
	}

	for (i = 0; i < k; i++)
	{
		a = find(son, edges[i].start);
		b = find(son, edges[i].end);
		if (a != b)
		{
			son[a] = b;
			printf("(%d,%d)\t%d\n", edges[i].start, edges[i].end, edges[i].weight);
		}
	}
	free(edges);
	free(son);
}
int main()
{
	int **graph = NULL;
	srand((unsigned int)time(NULL));
	graph = (int **)malloc(sizeof(int *)* 20);
	for (int i = 0; i < 20; i++)
	{
		graph[i] =(int *)malloc(sizeof(int)* 20);
	}
	

	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			graph[i][j] = -1;
		}
	}
	int vertexNum = 0;
	printf("请输入要生成图的点数:(小于20)\n");
	scanf_s("%d", &vertexNum); 
	if (vertexNum > 20)
	{
		return -1;
	}
	for (int i = 0; i < vertexNum; i++)
	{
		for (int j = 0; j < vertexNum; j++)
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
	for (int i = 0; i < vertexNum; i++)
	{
		for (int j = 0; j < vertexNum; j++)
		{
			printf("%d\t", graph[i][j]);
			if ((j + 1) % vertexNum == 0)
			{
				printf("\n");
			}
		}
	}
	printf("_______________________迷之分界线_______________________\n");
	prim(graph, vertexNum,0);
	printf("_______________________迷之分界线_______________________\n");
	kruskal(graph, vertexNum);
	free(graph);
	return 0;
}
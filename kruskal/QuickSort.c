#include "quickSort.h"

static void swap(TEdge edges[], int lo, int hi)
{
	int tmp = edges[lo].weight;
	edges[lo].weight = edges[hi].weight;
	edges[hi].weight = tmp;
}
static int partition(TEdge edges[], int lo, int hi)
{
	int tmp = edges[lo].weight;
	while (lo < hi)
	{
		while (lo < hi&&tmp <= edges[hi].weight)
			hi--;
		swap(edges, lo, hi);
		while (lo < hi&&tmp >= edges[lo].weight)
			lo++;
		swap(edges, lo, hi);
	}
	return lo;
}
static void qSort(TEdge edges[], int lo, int hi)
{
	if (lo < hi)
	{
		int pos = partition(edges, lo, hi);
		qSort(edges, lo, pos - 1);
		qSort(edges, pos + 1, hi);
	}
}

void quickSort(TEdge edges[], int len)
{
	qSort(edges, 0, len-1);
}


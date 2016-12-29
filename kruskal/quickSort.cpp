/**************************
@author:lam
@time:2016-12-30 00:21:37
@email:lam_2003@126.com
***************************/
#include "quickSort.h"
#define NUM 1024
static void swap(int a[], int i, int j)
{
	int tmp = a[i];
	a[i] = a[j];
	a[j] = tmp;
}

static int partition(int a[], int lo, int hi)
{
	int tmp = a[lo];
	while (lo < hi)
	{
		while (lo < hi&&tmp <= a[hi])
			hi--;
		if (tmp>a[hi])
			swap(a, lo, hi);
		while (lo < hi&&tmp >= a[lo])
			lo++;
		if (tmp < a[lo])
			swap(a, lo, hi);
	}
	return lo;
}

static void QSort(int a[], int lo, int hi)
{
	if (lo < hi)
	{
		int pos = partition(a, lo, hi);
		QSort(a, lo, pos - 1);
		QSort(a, pos + 1, hi);
	}
}

void QuickSort(int a[], int lo, int hi)
{
	QSort(a, lo, hi-1);
}

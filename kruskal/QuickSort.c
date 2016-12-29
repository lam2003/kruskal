#include "quickSort.h"
#include <stdio.h>
static int partition(int a[], int lo, int hi)
{
	int tmp = a[lo];
	while (lo < hi)
	{
		while (lo < hi&&tmp <= a[hi])
			hi--;
		if (tmp > a[hi])
		{
			int tmp = a[lo];
			a[lo] = a[hi];
			a[hi] = tmp;
		}
		while (lo < hi&&tmp >= a[lo])
			lo++;
		if (tmp < a[lo])
		{
			int tmp = a[lo];
			a[lo] = a[hi];
			a[hi] = tmp;
		}
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
void QuickSort(int a[], int len)
{
	QSort(a, 0, len-1);
}

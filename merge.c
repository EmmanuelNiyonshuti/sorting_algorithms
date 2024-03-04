#include "sort.h"
#include <stdlib.h>
/**
 * merge - Merges two sorted subarrays into one
 * @array: Original array
 * @lt: Left index of the first subarray
 * @mid: Right index of the first subarray
 * @rt: Right index of the second subarray
 */
void merge(int *array, int lt, int mid, int rt)
{
	int *tmp1, *tmp2, size1, size2;
	int i, j, k, n, m;

	size1 = mid - lt + 1;
	size2 = rt - mid;
	tmp1 = malloc(size1 * sizeof(int));
	if (tmp1 == NULL)
		return;
	tmp2 = malloc(size2 * sizeof(int));
	if (tmp2 == NULL)
		return;
	for (i = 0; i < size1; i++)
		tmp1[i] = array[lt + i];

	for (j = 0; j < size2; j++)
		tmp2[j] = array[mid + 1 + j];
	k = lt;
	n = 0;
	m = 0;
	while (n < size1 && m < size2)
	{
		if (tmp1[n] <= tmp2[m])
		{
			array[k] = tmp1[n];
			n++;
		}
		else
		{
			array[k] = tmp2[m];
			m++;
		}
		k++;
	}
	while (n < size1)
	{
		array[k] = tmp1[n];
		n++;
		k++;
	}
	while (m < size2)
	{
		array[k] = tmp2[m];
		m++;
		k++;
	}
	free(tmp1);
	free(tmp2);
}

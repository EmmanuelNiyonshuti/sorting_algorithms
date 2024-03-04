#include "sort.h"
#include <stdlib.h>
#include <stdio.h>

void merge_sort_recursive(int *array, int lt, int rt)
{
	int mid;

	if (lt < rt)
	{
		mid = lt +  (rt - lt)/2;
		merge_sort_recursive(array, lt, mid);
		merge_sort_recursive(array, mid + 1, rt);
		merge(array, lt, mid, rt);
		
        	printf("Merging...\n[left]: ");
        	print_array(array + lt, mid - lt + 1);
        	printf("[right]: ");
        	print_array(array + mid + 1, rt - mid);
        	printf("[Done]: ");
        	print_array(array + lt, rt - lt + 1);
        	printf("\n");
	}
}

void merge(int *array, int lt, int mid, int rt)
{
	int *tmp1, *tmp2;
	int size1, size2;
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


void merge_sort(int *array, size_t size)
{
	if (size < 2)
		return;
	merge_sort_recursive(array, 0, size - 1);
}


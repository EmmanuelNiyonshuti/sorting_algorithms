#include "sort.h"
#include <stdlib.h>
#include <stdio.h>
/**
 * merge_sort_recursive - Recursively divides and merges the array
 * @array: Array to be sorted
 * @lt: Left index of the subarray
 * @rt: Right index of the subarray
 */
void merge_sort_recursive(int *array, int lt, int rt)
{
	int mid;

	if (lt < rt)
	{
		mid = lt +  (rt - lt) / 2;
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
/**
 * merge_sort - Sorts an array using the Merge Sort algorithm
 * @array: Array to be sorted
 * @size: Size of the array
 */
void merge_sort(int *array, size_t size)
{
	if (size < 2)
		return;

	merge_sort_recursive(array, 0, size - 1);
}


#include "sort.h"
/**
 * quick_sort - sorts an array of integers in ascending order
 * using the Quick sort algorithm.
 *It partitions the array using the Lomuto Partition Scheme.
 * @array: The array to be sorted.
 * @size: The size of the array.
 *
 * Return: Void.
*/
void quick_sort(int *array, size_t size)
{
	if (size < 2)
		return;
	quick_sort_recursive(array, 0, size - 1, size);
}


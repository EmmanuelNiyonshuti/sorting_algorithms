#include "sort.h"
/**
 * lomuto_partition - partitions an array
 * using the Lomuto Partition Scheme.
 * It chooses the pivot as the last element.
 * @array: The array to be partitioned.
 * @first: The starting index of the partition.
 * @last: The ending index of the partition.
 * @size: The size of the array.
 *
 * Return: The index of the partitioned element.
 */

int Lomuto_partition(int *array, int first, int last, size_t size)
{
	int pivot, i, j, temp;

	pivot = array[last];
	i = first - 1;

	/* Iterate through the array to partition */
	for (j = first; j < last; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (j > i)
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
				print_array(array, size);
			}
		}
	}
	/*place pivot at correct position*/
	temp = array[i + 1];
	array[i + 1] = array[last];
	array[last] = temp;
	print_array(array, size);


	return (i + 1);
}

/**
 * quick_sort_recursive - sorts an array recursively
 * using the Quick sort algorithm.
 * It partitions the array using the Lomuto Partition Scheme.
 * @array: The array to be sorted.
 * @start: The starting index of the partition.
 * @last: The ending index of the partition.
 * @size: The size of the array.
 *
 * Return: Void.
 */
void quick_sort_recursive(int *array, int first, int last, size_t size)
{
	int pi;

	if (first < last)
	{
		/*Partition the array and get the partitioning index*/
		pi = Lomuto_partition(array, first, last, size);


		/*Recursively sort the left subarray*/
		quick_sort_recursive(array, first, pi - 1, size);
		/*Recursively sort the right subarray*/
		quick_sort_recursive(array, pi + 1, last, size);
	}
}

/**
 * quick_sort - sorts an array of integers in ascending order
 * using the Quick sort algorithm.
 * It partitions the array using the Lomuto Partition Scheme.
 * @array: The array to be sorted.
 * @size: The size of the array.
 *
 * Return: Void.
*/
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_sort_recursive(array, 0, size - 1, size);
}

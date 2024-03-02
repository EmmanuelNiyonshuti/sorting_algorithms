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

int lomuto_partition(int *array, int first, int last, size_t size)
{
	int pivot, i, j, tmp;

	pivot = array[last];
	i = first - 1;

	/* Iterate through the array to partition */
	for (j = first; j < last; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (i != j)
			{
				tmp = array[i];
				array[i] = array[j];
				array[j] = tmp;
				/*swap(&array[i], &array[j]);*/
				print_array(array, size);
			}
		}
	}
	/*place pivot at correct position*/
	if (i + 1 != last)
	{
		tmp = array[i + 1];
		array[i + 1] = array[last];
		array[last] = tmp;
		/*swap(&array[i + 1], &array[last]);*/
		print_array(array, size);
	}


	return (i + 1);
}

/**
 * quick_sort_recursive - sorts an array recursively
 * using the Quick sort algorithm.
 * It partitions the array using the Lomuto Partition Scheme.
 * @array: The array to be sorted.
 * @first: The starting index of the partition.
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
		pi = lomuto_partition(array, first, last, size);

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
	if (size < 2 || array == NULL)
		return;

	quick_sort_recursive(array, 0, size - 1, size);
}

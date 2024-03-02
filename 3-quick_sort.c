#include "sort.h"
/**
 * lomuto_partition - partitions an array
 * using the Lomuto Partition Scheme.
 * It chooses the pivot as the last element.
 * @array: The array to be partitioned.
 * @low: The starting index of the partition.
 * @high: The ending index of the partition.
 * @size: The size of the array.
 *
 * Return: The index of the partitioned element.
 */

int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot, i, j, temp;

	if (array == NULL || size < 2)
		return;

	pivot = array[high];
	i = low - 1;

	/* Iterate through the array to partition */
	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (i != j)
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
	array[i + 1] = array[high];
	array[high] = temp;
	print_array(array, size);


	return (i + 1);
}

/**
 * quick_sort_recursive - sorts an array recursively
 * using the Quick sort algorithm.
 * It partitions the array using the Lomuto Partition Scheme.
 * @array: The array to be sorted.
 * @low: The starting index of the partition.
 * @high: The ending index of the partition.
 * @size: The size of the array.
 *
 * Return: Void.
 */
void quick_sort_recursive(int *array, int low, int high, size_t size)
{
	int pi;

	if (array == NULL || size < 2)
		return;

	if (low < high)
	{
		/*Partition the array and get the partitioning index*/
		pi = lomuto_partition(array, low, high, size);


		/*Recursively sort the left subarray*/
		quick_sort_recursive(array, low, pi - 1, size);
		/*Recursively sort the right subarray*/
		quick_sort_recursive(array, pi + 1, high, size);
	}
}

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
	if (array == NUU || size < 2)
		return;
	quick_sort_recursive(array, 0, size - 1, size);
}

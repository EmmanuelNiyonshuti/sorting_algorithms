#include "sort.h"
/**
 * selection_sort - sorts an array of integers.
 * @array: Pointer an array of integers.
 * size: Size of the array.
 *
 * Return: Nothing.
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, num;

	if (size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		num = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[num])
				num = j;
			if (num != i)
				swap(&array[num], &array[i]);
		}
		print_array(array, size);

	}
}

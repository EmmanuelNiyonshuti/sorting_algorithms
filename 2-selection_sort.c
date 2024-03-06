#include "sort.h"
/**
 * selection_sort - sorts an array of integers.
 * @array: Pointer an array of integers.
 * @size: Size of the array.
 *
 * Return: Nothing.
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, small_num;
	size_t temp;

	for (i = 0; i < size - 1; i++)
	{
		/*searching for smaller number in the array*/
		small_num = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[small_num])
				small_num = j;
		}
		/*if the found small number is not at the start of the unsorted array swap*/
		if (small_num != i)
		{
			temp = array[small_num];
			array[small_num] = array[i];
			array[i] = temp;
			print_array(array, size);
		}
	}
}
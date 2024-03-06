#include "sort.h"
/**
 * shell_sort -  sorts an array of integers in ascending order
 * using the Shell sort algorithm, using the Knuth sequence.
 * @array: pointer to the array of pointers.
 * @size: size to of the array.
 *
 *Return: Void.
 */
void shell_sort(int *array, size_t size)
{
	size_t i, j, gap;
	int tmp;

	gap = 1;

	while (gap < size / 3)
	{
		gap = (gap * 3) + 1;
	}
	while (gap > 0)
	{
		for (i = gap; i < size; i++)
		{
			tmp = array[i];
			j = i;
			while (j >= gap && array[j - gap] > tmp)
			{
				array[j] = array[j - gap];
				j -= gap;
			}
			array[j] = tmp;
		}
		print_array(array, size);
		gap = (gap - 1) / 3;
	}
}

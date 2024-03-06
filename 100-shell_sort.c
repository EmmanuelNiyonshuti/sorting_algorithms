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
	size_t i, j, n;
	int tmp;

	if (size < 2 || array == NULL)
		return;

	n = 1;

	while (n < size / 3)
	{
		n = (n * 3) + 1;
	}
	while (n > 0)
	{
		for (i = n; i < size; i++)
		{
			tmp = array[i];
			j = i;
			while (j >= n && array[j - n] > tmp)
			{
				array[j] = array[j - n];
				j -= n;
			}
			array[j] = tmp;
		}
		print_array(array, size);
		n = (n - 1) / 3;
	}
}

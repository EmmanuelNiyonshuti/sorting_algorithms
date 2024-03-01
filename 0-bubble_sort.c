#include "sort.h"
/**
 * bubble_sort - sorts an array of integers in ascending order
 * using the Bubble sort algorithm(optimized).
 *@array: Pointer to the array.
 *@size: size of the array.
 *
 *Return: Nothing.
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j, temp;
	int sorted;

	if (size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		sorted = 0;
		for (j = 0; j < size - 1 - i; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				print_array(array, size);
				sorted = 1;
			}
		}
	/*break the outer loop when the array is already sorted*/
	if (sorted == 0)
		break;
	}
}

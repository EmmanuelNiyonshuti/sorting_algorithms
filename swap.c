#include "sort.h"
/**
 * swap - helper function to swap array elements.
 * @a: pointer to integer value.
 * @b: pointer to integer value.
 *
 * Return: Void.
 */

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

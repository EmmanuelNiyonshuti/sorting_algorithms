#include <stdio.h>
#include <stdlib.h>
#include "../sort.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
	int array[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7, 4, 6, 8, 9, 12, 45, 67, 89, 90, 12, 34, 5, 7, 78, 789, 987, 900, 145, 678, 100, 134, 456, 744};
	size_t n = sizeof(array) / sizeof(array[0]);

	print_array(array, n);
	printf("\n");
	bubble_sort(array, n);
	printf("\n");
	print_array(array, n);
	return (0);
}

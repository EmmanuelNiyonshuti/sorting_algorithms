#include "sort.h"
/**
 * insertion_sort_list - sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm.
 * @list: Pointer to a pointer to a linked list.
 *
 * Return: Void.
*/
void insertion_sort_list(listint_t **list)
{
	listint_t *sorted;
	listint_t *curr;
	listint_t *next;
	listint_t *tmp;

	sorted = NULL;
	curr = *list;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	while (curr != NULL)
	{
		next = curr->next;
		curr->prev = curr->next = NULL;
		/*Find the correct position to insert current node in the sorted list*/
		if (sorted == NULL || sorted->n >= curr->n)
		{
			curr->next = sorted;
			if (sorted != NULL)
				sorted->prev = curr;
			sorted = curr;
		}
		else
		{
			/*start traversing the sorted list*/
			tmp = sorted;
			while (tmp->next != NULL && tmp->next->n < curr->n)
				tmp = tmp->next;
			curr->next = tmp->next;

			if (tmp->next != NULL)
				tmp->next->prev = curr;

			tmp->next = curr;
			curr->prev = tmp;
			print_list(*list);
		}
		curr = next;
	}
	*list = sorted;
}

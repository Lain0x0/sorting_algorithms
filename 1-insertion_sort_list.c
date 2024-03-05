#include "sort.h"

/**
 * swap_nodes - Swap two nodes in a listint_t doubly-linked list.
 * @h: A pointer to the head of the doubly-linked list.
 * @n1st: A pointer to the first node to swap.
 * @n2nd: The second node to swap.
 */
void swap_nodes(listint_t **h, listint_t **n1st, listint_t *n2nd)
{
	(*n1st)->next = n2nd->next;
	if (n2nd->next != NULL)
		n2nd->next->prev = *n1st;

	n2nd->prev = (*n1st)->prev;
	n2nd->next = *n1st;

	if ((*n1st)->prev != NULL)
		(*n1st)->prev->next = n2nd;
	else
		*h = n2nd;

	(*n1st)->prev = n2nd;
	*n1st = n2nd->prev;
}

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 * using the insertion sort algorithm.
 * @list: A pointer to the head of a doubly-linked list of integers.
 *
 * Description: Prints the list after each swap.
 */
void insertion_sort_list(listint_t **list)
{

	listint_t *iter, *tmp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (iter = (*list)->next; iter != NULL; iter = tmp)
	{
		tmp = iter->next;

		while (iter->prev != NULL && iter->n < iter->prev->n)
		{
			swap_nodes(list, &(iter->prev), iter);
			print_list((const listint_t *)*list);
		}
	}
}

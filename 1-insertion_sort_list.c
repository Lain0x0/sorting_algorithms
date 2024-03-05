#include "sort.h"

/**
 * swap_nodes - Swap two nodes in a listint_t doubly-linked list.
 * @h: A pointer to the head of the doubly-linked list.
 * @na: A pointer to the first node to swap.
 * @nb: The second node to swap.
 */
void swap_nodes(listint_t **h, listint_t **na, listint_t *nb)
{
	(*na)->next = nb->next;
	if (nb->next != NULL)
		nb->next->prev = *na;
	nb->prev = (*na)->prev;
	nb->next = *na;
	if ((*na)->prev != NULL)
		(*na)->prev->next = nb;
	else
		*h = nb;
	(*na)->prev = nb;
	*na = nb->prev;
}

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 *                       using the insertion sort algorithm.
 * @list: A pointer to the head of a doubly-linked list of integers.
 *
 * Description: Prints the list after each swap.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *iter, *insert, *tmp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	int i, key, j;
	for (i = 1; i < n; i++) 
	{
		key = arr[i];
		j = i - 1;

		while (j >= 0 && arr[j] > key) 
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}
	{
		swap_nodes(list, &insert, iter);
		print_list((const listint_t *)*list);
	}
}

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
	listint_t *iter, *insert, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (iter = (*list)->next; iter != NULL; iter = temp)
	{
		temp = iter->next;
		insert = iter->prev;
		while (insert != NULL && iter->n < insert->n)
		{
			swap_nodes(list, &insert, iter);
			print_list((const listint_t *)*list);
		}
	}
}

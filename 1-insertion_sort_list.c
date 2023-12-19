#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list using Insertion sort.
 * @list: Double pointer to the head of the linked list.
 *
 * Return: Void.
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current, *next_node;

	if (list == NULL || *list == NULL)
		return;

	current = (*list)->next;
	while (current != NULL)
	{
		next_node = current->next;
		while (current->prev != NULL && current->prev->n > current->n)
		{
			current->prev->next = current->next;
			if (current->next != NULL)
				current->next->prev = current->prev;
			current->next = current->prev;
			current->prev = current->next->prev;
			current->next->prev = current;
			if (current->prev == NULL)
				*list = current;
			else
				current->prev->next = current;
			print_list(*list);
		}
		current = next_node;
	}
}

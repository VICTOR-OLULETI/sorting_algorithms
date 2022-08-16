#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers
 * in ascending order using insertion sort algorithm
 *
 * @list: linked list
 * Return: void.
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *next_num = NULL, *node = NULL, *temp = NULL;

	node = *list;
	if (!list || !(*list) || (*list)->next == NULL)
		return;

	for (node = *list; node;)
	{
		if (node->next && (node->n > node->next->n))
		{
			next_num = node->next;
			for (temp = next_num; temp->prev; temp = temp->prev)
				if (temp->prev->n < temp->n)
					break;
			if (next_num->next && next_num->prev)
			{
				next_num->prev->next = next_num->next;
				next_num->next->prev = next_num->prev;
			}
			else
			{
				next_num->prev->next = NULL;
			}
			next_num->next = temp;
			if (temp->prev)
			{
				temp->prev->next = next_num;
				next_num->prev = temp->prev, temp->prev = next_num;
			}
			else
			{
				temp->prev = next_num;
				next_num->prev = NULL, *list = next_num;
			}
			print_list(*list), node = *list;
			continue;
		}
		node = node->next;
	}
}

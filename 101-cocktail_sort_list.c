#include "sort.h"

/**
 * swap - swaps a node with the next node in the list
 * @list: double pointer to the beginning of the list
 * @node: node to be swapped
 *
 * Return: void.
 */
void swap(listint_t **list, listint_t *node)
{
	listint_t *next_num, *num;

	next_num = node->next;
	num = node;
	if (next_num->next && next_num->prev)
	{
		next_num->prev->next = next_num->next;
		next_num->next->prev = next_num->prev;
	}
	else
	{
		next_num->prev->next = NULL;
	}
	next_num->next = num;
	if (num->prev)
	{
		num->prev->next = next_num;
		next_num->prev = num->prev;
		num->prev = next_num;
	}
	else
	{
		num->prev = next_num;
		next_num->prev = NULL;
		*list = next_num;
	}
}

/**
 * cocktail_sort_list - sorts a doubly linked list of integers
 * in ascending order using insertion sort algorithm
 *
 * @list: linked list
 * Return: void.
 */

void cocktail_sort_list(listint_t **list)
{
	listint_t *next_num, *node, *num;
	char swapped = 1;

	node = *list;
	while (swapped != 0)
	{
		swapped = 0;
		for (node = *list; node->next;)
		{
			num = node, next_num = node->next;
			if (next_num && num->n > next_num->n)
			{
				swap(list, num);
				swapped = 1;
				print_list(*list);
			}
			else
			{
				node = node->next;
			}
		}
		if (swapped == 0)
			break;
		swapped = 0;
		while (node->prev)
		{
			num = node->prev, next_num = node;
			if (num->n > next_num->n)
			{
				swap(list, num);
				swapped = 1;
				print_list(*list);
			}
			else
			{
				node = node->prev;
			}
		}
	}
}

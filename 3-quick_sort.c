#include "sort.h"

/**
 * swap - swaps two integers in the arra
 * @num1: integer
 * @num2: integer
 * Return: void
 */
void swap(int *num1, int *num2)
{
	int temp;

	temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}

/**
 * partition - helps to sort array in ascending order
 * @end: final index of array
 * @start: where to start the array
 * @array: array of integers
 * @size: size of @array.
 * Return: index of array to start the next sort
 */

size_t partition(int *array, size_t start, size_t end, size_t size)
{
	size_t i, j;
	int pivot = array[end];

	i = start - 1;
	for (j = start; j < end; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (i != j)
			{
				swap(&array[i], &array[j]);
				print_array(array, size);
			}
		}
	}

	if (pivot < array[i + 1])
	{
		swap(&array[i + 1], &array[end]);
		print_array(array, size);
	}
	return (i + 1);
}

/**
 * quick_sort_tmp -  sorts an array of integers in ascending order
 * using the Quick sort algorithm, lomuto partition scheme
 *
 * @array: array of integers
 * @low: chosen starting point of array
 * @size: size of array
 * @h1: chosen end point of the array
 *
 * Return: void.
 */

void quick_sort_tmp(int *array, int low, int h1, size_t size)
{
	int par;

	if (low < h1)
	{
		par = partition(array, low, h1, size);
		quick_sort_tmp(array, low, par - 1, size);
		quick_sort_tmp(array, par + 1, h1, size);
	}
}

/**
 * quick_sort - sorts an array of integers in ascending
 * order using the Quick sort algorithm, lomuto partition scheme
 *
 * @array: array of integers
 * @size: size of array
 */

void quick_sort(int *array, size_t size)
{
	quick_sort_tmp(array, (size_t)0, size - 1, size);
}

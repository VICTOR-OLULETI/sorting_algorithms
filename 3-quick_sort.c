#include "sort.h"

/**
 * check_sorted - checks if subarray is sorted
 * @array: array of integers
 * @index_last: point where array is divided
 * @start: point wher subarray begins
 *
 * Return: 0 if not sorted, 1 if sorted
 */
int check_sorted(int *array, size_t index_last, size_t start)
{
	size_t i;

	for (i = index_last; i > start; i--)
	{
		if (array[i] < array[i + 1])
			return (0);
	}
	return (1);
}

/**
 * quick_sort_tmp - quick sort with a start point
 * @array: array of integers
 * @size: size of @array
 * @start: starting point
 * @total: total size of array
 * Return: void
 */

void quick_sort_tmp(int *array, size_t size, size_t start, size_t total)
{
	size_t i, index_last;
	int temp1, temp2;
	int flag, flag2;

	index_last = size - 1;
	i = start;
	for (; start < size; start++)
	{
		for (; i < index_last; i++)
		{
			if (array[i] > array[index_last])
			{
				temp1 = array[i];
				array[i] = array[index_last - 1];
				array[index_last - 1] = temp1;
				temp2 = array[index_last - 1];
				array[index_last - 1] = array[index_last];
				array[index_last] = temp2;
				index_last = index_last - 1;
				break;
			}
		}
	}
	if (index_last != 0)
	{
		print_array(array, total);
		flag = check_sorted(array, index_last, 0);
		flag2 = check_sorted(array, size, index_last + 1);
		if (flag == 0)
			quick_sort_tmp(array, index_last, 0, total);
		if (flag2 == 0)
			quick_sort_tmp(array, size, index_last + 1, total);
	}
}

/**
 * quick_sort - sorts an array of integers in ascending order
 * using the Quick sort algorithm
 *
 * @array: array of integers to sort
 * @size: size of @array
 *
 * Return: void.
 */

void quick_sort(int *array, size_t size)
{
	size_t k, i, index_last;
	int temp1, temp2;
	int flag, flag2;

	index_last = size - 1;
	for (k = 0; k < size; k++)
	{
		for (i = 0; i < index_last; i++)
		{
			if (array[i] > array[index_last])
			{
				temp1 = array[i];
				array[i] = array[index_last - 1];
				array[index_last - 1] = temp1;
				temp2 = array[index_last - 1];
				array[index_last - 1] = array[index_last];
				array[index_last] = temp2;
				index_last = index_last - 1;
				break;
			}
		}
	}
	print_array(array, size);
	if (index_last != 0)
	{
		flag = check_sorted(array, index_last, 0);
		flag2 = check_sorted(array, size, index_last + 1);
		print_array(array, size);
		if (flag == 0)
			quick_sort_tmp(array, index_last, 0, size);
		if (flag2 == 0)
			quick_sort_tmp(array, size, index_last + 1, size);
	}
	else
	{
		flag = check_sorted(array, size, 0);
		if (flag == 0)
			quick_sort(array, size);
	}
}

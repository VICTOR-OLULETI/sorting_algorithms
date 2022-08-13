#include "sort.h"

/**
 * min - finds the minimum integer in an array
 * @i: start of the next sublist of the @array
 * @array: array of integers
 * @size: size of @array of integers
 * Return: index of array
 */
int min(size_t i, int *array, size_t size)
{
	int min_num;
	size_t j = 0;

	min_num = array[i];
	for (; i < size; i++)
	{
		if (min_num > array[i])
			min_num = array[i];
	}
	for (; j < size; j++)
	{
		if (min_num == array[j])
			break;
	}
	return (j);
}

/**
 * selection_sort - sorts an array of integers in ascending order
 * using the selection sort algorithm
 * @array: array of integers
 * @size: size of @array of integers
 *
 * Return: void.
 */

void selection_sort(int *array, size_t size)
{
	size_t i, j, index;
	int temp, value;

	j = 0, i = 0;
	if (size <= 1)
		return;

	for (; i < size - 1; i++)
	{
		index = min(i, array, size);
		value = array[index];
		temp = array[i];
		array[j] = value;
		array[index] = temp;
		if (j == index)
		{
			j++;
			continue;
		}
		print_array(array, size);
		j++;
	}
}

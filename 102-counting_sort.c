#include "sort.h"

/**
 * counting_array - returns the count array for the
 * Counting sort algorithm
 * @array: array to be sorted
 * @size: size of @array
 * @count_size: size of new array;
 *
 * Return: new array
 */

int *counting_array(int *array, size_t size, size_t count_size)
{
	int *count_array, element;
	unsigned int i, k = 0, count;

	count_array = malloc(sizeof(int) * count_size);
	if (count_array == NULL)
		free(count_array);
	for (i = 0; i < count_size; i++)
		count_array[i] = 0;

	for (i = 0; i < size; i++)
	{
		k = 0;
		element = array[i];
		for (count = 0; count < size; count++)
		{
			if (array[count] == element)
				k++;
		}
		count_array[element] = k;
	}
	return (count_array);
}
/**
 * counting_sort - sorts an array of integers in ascending order
 * using the Counting sort algorithm
 * @array: array of integers to be sorted
 * @size: size of @array
 *
 * Return: void.
 */

void counting_sort(int *array, size_t size)
{
	unsigned int i, count_size;
	int max;
	int *count_array, *sorted_array;

	if (array == NULL || size < 2)
		return;

	max = array[0];
	for (i = 0; i < size; i++)
	{
		if (max < array[i])
			max = array[i];
	}
	count_size = max + 1;
	count_array = counting_array(array, size, count_size);
	for (i = 0; i < count_size - 1; i++)
	{
		count_array[i + 1] += count_array[i];
		print_array(count_array, count_size);
	}
	sorted_array = malloc(sizeof(int) * size);
	if (sorted_array == NULL)
	{
		free(sorted_array);
	}
	for (i = 0; i < size; i++)
	{
		sorted_array[count_array[array[i]] - 1] = array[i];

	}
	print_array(sorted_array, size);
	for (i = 0; i < size; i++)
	{
		array[i] = sorted_array[i];
	}
	free(count_array);
	free(sorted_array);
}

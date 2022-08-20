#include "sort.h"

/**
 * getMax - gets the maximum value from an array
 * @array: array of integers
 * @size: size of @array
 *
 * Return: maximum value in array
 */
int getMax(int *array, size_t size)
{
	int max = array[0];
	size_t i;

	for (i = 1; i < size; i++)
		if (array[i] > max)
			max = array[i];

	return (max);
}

/**
 * countingSort - sorts an array using counting sort
 * @array: array of integers
 * @size: size of array
 * @place: indicates the place of each digit(unit, tens, hundreds,..)
 * Return: void.
 */
void countingSort(int *array, size_t size, int place)
{
	int max = (array[0] / place) % 10, *output, *count, j;
	size_t count_size, i;

	for (i = 1; i < size; i++)
	{
		if (((array[i] / place) % 10) > max)
			max = array[i];
	}
	count_size = max + 1;
	count = malloc(sizeof(int) * count_size);
	if (count == NULL)
		return;
	for (i = 0; i < count_size; i++)
		count[i] = 0;

	/* calculating the count of elements */
	for (i = 0; i < size; i++)
		count[(array[i] / place) % 10]++;
	/* calculating the cumulative count */
	for (i = 1; i < count_size; i++)
		count[i] += count[i - 1];
	/* creating the output array */
	output = malloc(sizeof(int) * size);
	if (output == NULL)
		return;
	/* placing the elements in sorted order */
	for (j = size - 1; j >= 0; j--)
	{
		output[count[(array[j] / place) % 10] - 1] = array[j];
		count[(array[j] / place) % 10]--;
	}
	/* copying the sorted elements into the original array */
	for (i = 0; i < size; i++)
		array[i] = output[i];

	free(count);
	free(output);
}

/**
 * radix_sort - sorts an array of integers in ascending order
 * using the Radix sort algorithm
 * @array: array of integers to be sorted
 * @size: size of @array
 *
 * Return: void.
 */
void radix_sort(int *array, size_t size)
{

	int max, place;

	if (array == NULL || size < 2)
		return;

	max = getMax(array, size);
	for (place = 1; (max / place) > 0; place *= 10)
	{
		countingSort(array, size, place);
		print_array(array, size);
	}
}

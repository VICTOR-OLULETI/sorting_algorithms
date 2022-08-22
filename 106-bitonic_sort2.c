#include "sort.h"

/**
 * bitonic_compare - compares bitonic sequences
 * @array: array of integers
 * @count: size of array;
 * @lowIndex: low index of array
 * @direction: direction of bitonic sort
 * Return: void.
 */
void bitonic_compare(int *array, int lowIndex, int count, char direction)
{
	int swap, k, i;

	k = count / 2;
	for (i = lowIndex; i < lowIndex + k; i++)
	{
		if (direction == (array[i] > array[i + k]))
		{
			swap = array[i + k];
			array[i + k] = array[i];
			array[i] = swap;
		}
	}
}
/**
 * bitonicMerge - merges a bitonic sort
 * @array: array of integers
 * @lowIndex: low index
 * @count: size of subarray
 * @direction: either 1 or 0. up or down.
 * Return: void.
 */
void bitonicMerge(int *array, int lowIndex, int count, char direction)
{
	int k;

	if (count > 1)
	{
		k = count / 2;
		bitonic_compare(array, lowIndex, count, direction);
		bitonicMerge(array, lowIndex, k, direction);
		bitonicMerge(array, lowIndex + k, k, direction);
	}
}
/**
 * bit_sort - sorts using bitonic sort algorithm
 * @array: array of integers
 * @lowIndex: low index of array
 * @count: size of sub-array
 * @direction: either up or down, 1 0r 2.
 * @size: size of entire array
 * Return: void.
 */
void bit_sort(int *array, int lowIndex, int count, char direction, size_t size)
{
	int k;

	if (count > 1)
	{
		printf("Merging [%u/%lu] (%s):\n", count, size,
				(direction == 1) ? "UP" : "DOWN");
		print_array(array, count);
		k = count / 2;
		bit_sort(array, lowIndex, k, 1, size);
		bit_sort(array, (lowIndex + k), k, 0, size);
		bitonicMerge(array, lowIndex, count, direction);
		printf("Result [%u/%lu] (%s):\n", count, size,
				(direction == 1) ? "UP" : "DOWN");
		print_array(array, count);
	}
}
/**
 * bitonic_sort - sorts an array of integers in ascending
 * order using the Bitonic sort algorithm
 * @array: array of integers
 * @size: size of @array
 *
 * Return: void.
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	bit_sort(array, 0, size, 1, size);
}

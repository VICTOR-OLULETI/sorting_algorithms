#include "sort.h"

/**
 * bubble_sort - sorts an array in ascending order
 * using the Bubble sort algorithm
 *
 * @array: The array containing the unsorted elements
 * @size: size of the @array
 *
 */

void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int temp;

	i = 0, count = 0;
	for (j = 0; j < size; j++)
	{
		for (; i < size; i += 1)
		{
			if (array[i] > array[i + 1])
			{
				temp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = temp;
				print_array(array, size);
			}
		}
	}
}

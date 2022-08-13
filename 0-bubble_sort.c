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
	size_t i;
	size_t count;
	int temp;

	i = 0, count = 0;
	while (true)
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
			else
			{
				count += 1;
			}
		}
		if (count == size)
			break;
		count = 0;
		i = 0;
	}
	print_array(array, size);
}

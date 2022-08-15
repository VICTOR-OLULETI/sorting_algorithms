#include "sort.h"

/**
 * shell_sort - sorts an array of integers in ascending order
 * using the Shell sort algorithm, using the Knuth Sequence
 * n+1 = n * 3 + 1
 * 1, 4, 13, 40, 121, ....
 * @array: array of integers to be sorted
 * @size: size of @array
 *
 * Return: void.
 */

void shell_sort(int *array, size_t size)
{
	unsigned int gap, j, flag = 0, i, n = size;
	int temp;

	if (array == NULL)
		return;
	if (size < 2)
		return;

	while (gap < n / 3)
		gap = gap * 3 + 1;

	while (gap > 0)
	{
		for (i = gap; i < n; i += 1)
		{
			temp = array[i];
			for (j = i; (j >= gap) && (array[j - gap] > temp); j -= gap)
			{
				array[j] = array[j - gap];
			}
			flag = 1;
			array[j] = temp;
		}
		if (flag == 1)
			print_array(array, size);
		flag = 0;
		gap /= 3;
	}
}

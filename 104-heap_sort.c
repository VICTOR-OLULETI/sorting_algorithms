#include "sort.h"

/**
 * swapped - swaps two index values in an array
 * @a: first value
 * @b: second value
 * Return: void.
 */
void swapped(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
/* iParent(i) = ((i - 1) / 2)*/

/**
 * iLeftChild - left node index
 * @i: index
 * Return: modified index;
 */

int iLeftChild(int i)
{
	return (2 * i + 1);
}

/*iRightChild(i) = (2 * i + 2)*/

/**
 * siftDown - rearranges the heap properly
 * @array: array of integers
 * @start: start
 * @end: end
 * @size: size of entire array
 *
 * Return: void.
 */

void siftDown(int *array, int start, int end, size_t size)
{
	int root = start, swap, child;

	/*iLeftChild = 2 * root + 1;*/
	while (iLeftChild(root) <= end)
	{

		child = iLeftChild(root);
		swap = root;

		if (array[swap] < array[child])
			swap = child;
		if (child + 1 <= end && array[swap] < array[child + 1])
			swap = child + 1;
		if (swap == root)
		{
			return;
		}
		else
		{
			swapped(&array[root], &array[swap]);
			root = swap;
		}
		print_array(array, size);
	}
}

/**
 * heapify - structures an array to a heap
 *
 * @array: array of integers
 * @size: size of @array
 *
 * Return: void.
 */
void heapify(int *array, int size)
{
	int count = size, start;

	/*start = iParent(count - 1);*/
	start = ((count - 1) - 1) / 2;

	while (start >= 0)
	{
		siftDown(array, start, count - 1, (size_t) size);

		start = start - 1;
	}
}

/**
 * heap_sort - sorts an array of integers in ascending order
 * using the Heap sort algorithm
 *
 * @array: array of integers to be sorted
 * @size: size of @array
 *
 * Return: void.
 */

void heap_sort(int *array, size_t size)
{
	int count = size, end;

	heapify(array, count);

	end = count - 1;
	while (end > 0)
	{
		swapped(&array[end], &array[0]);
		end = end - 1;

		print_array(array, size);
		siftDown(array, 0, end, size);
	}
}

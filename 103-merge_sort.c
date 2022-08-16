#include "sort.h"

/**
 * copyArray - copies an array's value into another
 * @A: array to be copied from
 * @B: array to be copied to
 * @iEnd: size of array
 * @iBegin: beginning of array
 *
 * Return: void.
 */

void copyArray(int *A, size_t iBegin, size_t iEnd, int *B)
{
	unsigned int k;

	for (k = iBegin; k < iEnd; k++)
	{
		B[k] = A[k];
	}
}

/**
 * printMerge - prints the merged elements
 * @A: first array
 * @iBegin: begining of array
 * @iMiddle: middle of array
 * @iEnd: end of array
 * @B: second array
 *
 * Return: void.
 */

void printMerge(int *A, size_t iBegin, size_t iMiddle, size_t iEnd, int *B)
{
	unsigned int i, k, j;
	char *sep;

	i = iBegin, j = iMiddle;
	printf("Merging...\n");

	sep = "";
	printf("[left]: ");
	i = iBegin;
	for (k = iBegin; k < iEnd; k++)
	{
		if (i < iMiddle)
		{
			printf("%s%d", sep, A[i]);
			sep = ", ";
			i += 1;
		}
	}
	printf("\n");
	sep = "";
	printf("[right]: ");
	j = iMiddle;
	for (k = iBegin; k < iEnd; k++)
	{
		if (j < iEnd)
		{
			printf("%s%d", sep, A[j]);
			sep = ", ";
			j += 1;
		}
	}
	printf("\n");
	sep = "";
	printf("[Done]: ");
	for (k = iBegin; k < iEnd; k++)
	{
		printf("%s%d", sep, B[k]);
		sep = ", ";
	}
	printf("\n");
}
/**
 * topDownMerge - merges the top down split
 *
 * @A: first array
 * @iBegin: beginning of array
 * @iMiddle: middle of array
 * @iEnd: End of array
 * @B: second array
 *
 * Return: void.
 */

void topDownMerge(int *A, size_t iBegin, size_t iMiddle, size_t iEnd, int *B)
{
	unsigned int i, k, j;

	printMerge(A, iBegin, iMiddle, iEnd, B);
	i = iBegin, j = iMiddle;
	for (k = iBegin; k < iEnd; k++)
	{

		if (i < iMiddle && (j >= iEnd || A[i] <= A[j]))
		{
			B[k] = A[i];
			i = i + 1;
		}
		else
		{
			B[k] = A[j];
			j = j + 1;
		}
	}
}

/**
 * topDownSplitMerge - implements the top down split technique
 * for merge sort algorithm
 *
 * @B: second array
 * @iBegin: beginning of array
 * @iEnd: end of array
 * @A: first array
 *
 * Return: void
 */

void topDownSplitMerge(int *B, size_t iBegin, size_t iEnd, int *A)
{
	size_t iMiddle;

	if (iEnd - iBegin <= 1)
		return;
	iMiddle = (iEnd + iBegin) / 2;

	topDownSplitMerge(A, iBegin, iMiddle, B);
	topDownSplitMerge(A, iMiddle, iEnd, B);
	topDownMerge(B, iBegin, iMiddle, iEnd, A);
}

/**
 * merge_sort - sorts an array of integers in ascending order
 * using the Merge sort algorithm
 * @arrayA: array of integers
 * @size: size of @array
 *
 * Return: void.
 */

void merge_sort(int *arrayA, size_t size)
{
	int *arrayB;

	if (size < 2)
		return;

	arrayB = malloc(sizeof(int) * size);
	if (arrayB == NULL)
		return;
	copyArray(arrayA, 0, size, arrayB);
	topDownSplitMerge(arrayB, 0, size, arrayA);
	free(arrayB);
}

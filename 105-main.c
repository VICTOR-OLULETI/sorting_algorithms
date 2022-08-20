#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
    /*int array[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7, 4, 8, 12, 3, 100, 60, 24, 28, 77, 76};
*/
    int array[] = {2, 0, 1};
    size_t n = sizeof(array) / sizeof(array[0]);

    print_array(array, n);
    printf("\n");
    radix_sort(array, n);
    printf("\n");
    print_array(array, n);
    return (0);
}

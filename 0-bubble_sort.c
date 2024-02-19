#include "sort.h"
#include <stdio.h>

/**
 * swap_elements - Swap two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void swap_elements(int *a, int *b)
{
int tmp;

tmp = *a;
*a = *b;
*b = tmp;
}

/**
 * bubble_sort - Sorts an array of integers in ascending
 * order using
 *   the Bubble sort algorithm.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void bubble_sort(int *array, size_t size)
{
size_t i, j;
int swapped;

if (array == NULL || size < 2)
{
return;
}

for (i = 0; i < size - 1; i++)
{
swapped = 0; /* Flag to check if any swap
occurs in this pass */
for (j = 0; j < size - i - 1; j++)
{
if (array[j] > array[j + 1])
{
/* Swap the elements */
swap_elements(&array[j], &array[j + 1]);
swapped = 1; /* Set swapped flag to true */
print_array(array, size); /* Print array after each swap */
}
}
/* If no two elements were swapped in the inner loop,
then the array is sorted */
if (swapped == 0)
break;
}
}

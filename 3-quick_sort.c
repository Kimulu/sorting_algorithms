#include "sort.h"

/**
 * lomuto_partition - Lomuto partition scheme for quicksort
 * @array: array to partition
 * @low: lower index of the partition
 * @high: higher index of the partition
 * @size: size of the array
 *
 * Return: index of the pivot element
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
int pivot = array[high];
int i = low - 1;
int j, tmp;

for (j = low; j <= high - 1; j++)
{
if (array[j] <= pivot)
{
i++;
tmp = array[i];
array[i] = array[j];
array[j] = tmp;
if (i != j)
print_array(array, size);
}
}
tmp = array[i + 1];
array[i + 1] = array[high];
array[high] = tmp;
if (i + 1 != high)
print_array(array, size);
return (i + 1);
}

/**
 * quicksort - recursive function to sort a partition of an array
 * @array: array to sort
 * @low: lower index of the partition
 * @high: higher index of the partition
 * @size: size of the array
 */
void quicksort(int *array, int low, int high, size_t size)
{
if (low < high)
{
int pi = lomuto_partition(array, low, high, size);

quicksort(array, low, pi - 1, size);
quicksort(array, pi + 1, high, size);
}
}

/**
 * quick_sort - sorts an array of integers in ascending order
 *  using the Quick sort algorithm
 * @array: array to sort
 * @size: size of the array
 */
void quick_sort(int *array, size_t size)
{
if (array == NULL || size < 2)
return;

quicksort(array, 0, size - 1, size);
}

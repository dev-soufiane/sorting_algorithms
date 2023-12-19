#include "sort.h"

/**
 * lomuto_partition - Finds the partition for Quick sort using Lomuto scheme.
 * @array: Array to sort.
 * @low: Lowest index of the partition.
 * @high: Highest index of the partition.
 * @size: Size of the array.
 *
 * Return: Index of the partition.
 */
size_t lomuto_partition(int *array, ssize_t low, ssize_t high, size_t size)
{
	ssize_t i, j;
	int temp, pivot;

	pivot = array[high];
	i = low - 1;

	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (i != j)
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
				print_array(array, size);
			}
		}
	}
	if (array[high] < array[i + 1])
	{
		temp = array[i + 1];
		array[i + 1] = array[high];
		array[high] = temp;
		print_array(array, size);
	}
	return (i + 1);
}

/**
 * quicksort - Sorts a partition of an array of integers.
 * @array: Array to sort.
 * @low: Lowest index of the partition.
 * @high: Highest index of the partition.
 * @size: Size of the array.
 *
 * Return: void.
 */
void quicksort(int *array, ssize_t low, ssize_t high, size_t size)
{
	ssize_t pivot;

	if (low < high)
	{
		pivot = lomuto_partition(array, low, high, size);
		quicksort(array, low, pivot - 1, size);
		quicksort(array, pivot + 1, high, size);
	}
}

/**
 * quick_sort - Sorts an array of integers using Quick sort.
 * @array: The array to sort.
 * @size: The size of the array.
 *
 * Return: void.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quicksort(array, 0, size - 1, size);
}

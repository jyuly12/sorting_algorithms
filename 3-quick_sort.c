#include "sort.h"

/**
 * partition - lomuto partition chooses a pivot that is typically the
 * last element in the array
 * @array: array of integers
 * @size: size of array
 * @min: value
 * @max: value
 */
int partition(int *array, size_t size, int min, int max)
{
	int pivot = array[max];
	int j = min, i = min, tmp;

	for (; j < max; j++)
	{
		if (array[j] < pivot)
		{
			if (array[j] != array[i])
			{
				tmp = array[j];
				array[j] = array[i];
				array[i] = tmp;
				print_array(array, size);
			}
			i++;
		}
	}

	if (array[max] != array[i])
	{
		tmp = array[i];
		array[i] = array[max];
		array[max] = tmp;
		print_array(array, size);
	}
	return (i);
}

/**
 * recursion - recursion function
 * @array: array of integers
 * @size: size of array
 * @min: value
 * @max: value
 */
int recursion(int *array, size_t size, int min, int max)
{
	int r = 0;

	if (min < max)
	{
		r = partition(array, size, min, max);
		recursion(array, size, min, r - 1);
		recursion(array, size, r + 1, max);
	}
	return (*array);
}

/**
 * quick_sort - sorts an array of integers in ascending
 * @array: array of integers
 * @size: size of array
 */
void quick_sort(int *array, size_t size)
{
	int min = 0, max = size - 1;

	if (size < 2)
		return;

	recursion(array, size, min, max);
}

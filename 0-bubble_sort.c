#include "sort.h"
/**
 * bubble_sort - sorts an array of integers in ascending order.
 *
 * @array: Integers to sorts
 * @size: size to array.
 */
void bubble_sort(int *array, size_t size)
{
	int tmp;
	size_t i = 0, j = 0;

	if (!array || !size)
		return;

	for (; i < size; i++)
	{
		for (; j < size - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
				print_array(array, size);
			}

		}
	}
}

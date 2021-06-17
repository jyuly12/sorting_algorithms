#include "sort.h"

/**
 * selection_sort - sorts an array of integers in ascending order.
 * @array: array of integers
 * @size: size of array
 */
void selection_sort(int *array, size_t size)
{
	unsigned int i = 0, j, min_value, tmp;

	min_value = i;

	for (; i < size; i++)
	{
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[i])
			{
				min_value = j;
			}
		}
		if (min_value != i)
		{
			/*swap value*/
			tmp = array[i];
			array[i] = array[min_value];
			array[min_value] = tmp;

			print_array(array, size);
		}
	}
}

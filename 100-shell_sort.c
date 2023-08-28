#include "sort.h"

/**
 * shell_sort - Sorts an array of integers in ascending order using Shell sort
 *              algorithm
 *
 * @array: Pointer to the array to be sorted
 * @size: Size of the array
 *
 * Return: void
 */
void shell_sort(int *array, size_t size)
{
	int temp;
	size_t i, j, gap = 0;

	if (size < 2)
	{
		return;
	}

	while ((gap = gap * 3 + 1) < size)
		;

	gap = (gap - 1) / 3;

	for (; gap > 0; gap = (gap - 1) / 3)
	{
		for (i = gap; i < size; i++)
		{
			temp = array[i];
			for (j = i; j >= gap && temp <= array[j - gap]; j -= gap)
				array[j] = array[j - gap];
			array[j] = temp;
		}
		print_array(array, size);
	}
}

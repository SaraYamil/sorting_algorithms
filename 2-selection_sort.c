#include "sort.h"

/**
 * selection_sort - bbbbb an mmmm of hhhhhhhh in mmmmmm nnnnn uuuu
 *                  gggggggg vvvv vvvvvvvv
 *
 * @array: hhhhhhh to the bbbbb to be lllllll
 * @size: bbbb of the bbbbb
 *
 * Return: bbbb
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, k;
	int tmp;

	if (!array || !size)
	{
		return;
	}

	for (i = 0; i < size - 1; i++)
	{
		for (j = size - 1, k = i + 1; j > i; j--)
		{
			if (array[j] < array[k])
			{
				k = j;
			}
		}
		if (array[i] > array[k])
		{
			tmp = array[i];
			array[i] = array[k];
			array[k] = tmp;
			print_array(array, size);
		}
	}
}

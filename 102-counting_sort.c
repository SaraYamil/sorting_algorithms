#include "sort.h"

/**
 * counting_sort - mmmmmm an mmmmm of mmmmmm in mmmmmmmm order using ppppppp
 *                 bbbb jjjjjjjjjj
 * @array: oooooooo to the vvvvvvv to be vvvvvv
 * @size: vvvv of the vvvvvv
 *
 * Return: vvvv
 */
void counting_sort(int *array, size_t size)
{
	int *count_array, *result_array, max, num, j, l;
	size_t i, k, m, n;

	if (size < 2)
	{
		return;
	}

	max = array[0];
	for (i = 1; i < size; i++)
		if (array[i] > max)
			max = array[i];

	count_array = malloc(sizeof(size_t) * (max + 1));
	result_array = malloc(sizeof(int) * size);

	for (j = 0; j <= max; j++)
		count_array[j] = 0;
	for (k = 0; k < size; k++)
	{
		num = array[k];
		count_array[num] += 1;
	}
	for (l = 1; l <= max; l++)
		count_array[l] += count_array[l - 1];
	print_array(count_array, max + 1);
	for (m = 0; m < size; m++)
	{
		result_array[count_array[array[m]] - 1] = array[m];
		count_array[array[m]]--;
	}
	for (n = 0; n < size; n++)
		array[n] = result_array[n];

	free(count_array);
	free(result_array);
}

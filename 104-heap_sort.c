#include "sort.h"

void heapify(int *array, int heap, int i, int size);

/**
 * heap_sort - Sorts an array of integers in ascending order using Heap sort
 *             algorithm
 * @array: Pointer to the array to be sorted
 * @size: Size of the array
 *
 * Return: void
 */
void heap_sort(int *array, size_t size)
{
	int i = size / 2 - 1, temp;

	if (array == NULL || size < 2)
		return;
	for (; i >= 0; i--)
		heapify(array, size, i, size);
	for (i = size - 1; i >= 0; i--)
	{
		temp = array[0];
		array[0] = array[i];
		array[i] = temp;
		if (i > 0)
			print_array(array, size);
		heapify(array, i, 0, size);
	}
}

/**
 * heapify - Rearranges a binary tree to maintain the heap property.
 *
 * @array: Pointer to the array representing the binary tree
 * @heap: Size of the heap (portion of the array considered as a heap)
 * @i: Index of the current node (root of the subtree) being checked
 * @size: Size of the original array (total number of elements)
 *
 * Return: void
 */
void heapify(int *array, int heap, int i, int size)
{
	int lar = i, left = 2 * i + 1, right = 2 * i + 2, t;

	if (left < heap && array[left] > array[lar])
		lar = left;
	if (right < heap && array[right] > array[lar])
		lar = right;
	if (lar != i)
	{
		t = array[i], array[i] = array[lar], array[lar] = t;
		print_array(array, size);
		heapify(array, heap, lar, size);
	}
}
